#pragma once
#include <iostream>
#include "include/pallet.hpp"

Pallet::Pallet(std::string itemName, int itemCapacity, int itemCount){
    this->itemName = itemName;
    this->itemCapacity = itemCapacity;
    this->itemCount = itemCount;
}

Pallet::Pallet()
{
    itemName = "";
    itemCapacity = 0;
    itemCount = 0;
}

std::string Pallet::getItemName(){

    return itemName;
}

int Pallet::getItemCount() const{
    
    return itemCount;
}

int Pallet::getRemainingSpace() const{

    return itemCapacity - itemCount;
}

bool Pallet::reallocateEmptyPallet(std::string itemName, int itemCapacity){
    this->itemName = itemName;
    this->itemCapacity = itemCapacity;

    if (itemName == "" && itemCapacity == 0) {
        
        return true;
    }

    return false;
}

bool Pallet::takeOne(){
    if (itemCount > 0){
        itemCount--;
        return true;
    }
    return false;
}

bool Pallet::putOne(){
    if (itemCapacity > itemCount){
        itemCount++;
        return true;
    }
    return false;
}

bool Pallet::isEmpty()
{
    if (itemCount == 0){
        return true;
    }
    return false;
}

bool Pallet::isFull()
{
    if (itemCount == itemCapacity) {
        return true;
    }
    return false;
}





