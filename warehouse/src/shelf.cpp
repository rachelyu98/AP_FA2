#pragma once
#include "include/shelf.hpp"

Shelf::Shelf(){}

bool Shelf::swapPallet(int slot, int slot2){


    if (slot < 0 || slot >= 4 || slot2 < 0 || slot2 >= 4)
    {
        return false;
    }

    std::swap(pallets[slot], pallets[slot2]);
    return true;
}

bool Shelf::isEmpty(){
    for (const Pallet& pallet : pallets)
    {
        if (pallet.getItemCount() > 0 )
        {
            return false;
        }
    }
    return true;
}

bool Shelf::isFull()
{
    for (const Pallet& pallet : pallets)
    {
        if (pallet.getRemainingSpace() == 0)
        {
            return true;
        }
    }
    return false;
}