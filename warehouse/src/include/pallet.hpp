#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "IContainer.hpp"

class Pallet : public IContainer
{
    private:
        int itemCount; //only multale through taking and putting
        std::string itemName; //only multable if empty
        int itemCapacity;  //only multable if empty

    public:
        Pallet(std::string itemName, int itemCapacity, int itemCount);
        Pallet();
        std::string getItemName();
        int getItemCount() const;
        int getRemainingSpace() const;
        bool reallocateEmptyPallet(std::string itemName, int itemCapacity);
        bool takeOne();
        bool putOne();
        bool isEmpty() override;
        bool isFull() override;
};