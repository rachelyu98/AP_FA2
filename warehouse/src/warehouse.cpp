#pragma once
#include "include/warehouse.hpp"

Warehouse::Warehouse() {}

void Warehouse::addEmployee(Employee employee){
    Employees.push_back(employee); //employee toevogen aan Employee vector
}

void Warehouse::addShelf(Shelf shelf){
    shelves.push_back(shelf); //shelf toevoegen aan shelf vector

}

bool Warehouse::rearrangeShelf(Shelf& shelf){
    for (Employee& employee : Employees){
        //als employee geen certificate heeft of employee is niet beschikbaar
        if (!employee.getForkliftCertificate() || employee.getBusy()){
            return false;
        }
    }
    
    //sorteer de pallets op een shelf op volgorde van itemCount
    for (int i = 0; i < shelf.pallets.size() - 1; ++i)
    {
        for (int j = 0; j < shelf.pallets.size() - i - 1; ++j)
        {
            if (shelf.pallets[j].getItemCount() > shelf.pallets[j + 1].getItemCount())
            {
                // Wissel twee pallets
                shelf.swapPallet(j, j + 1);
            }
        }
    }
    return true;
}


bool Warehouse::pickItems(std::string itemName, int itemCount){
    int remaining = itemCount;
    // Loop door alle shelves
    for (Shelf& shelf : shelves)
    {
        // Loop door alle pallets van de shelf
        for (Pallet& pallet : shelf.pallets)
        {
            // Controleer of er het product op pallet is
            if (pallet.getItemName() == itemName)
            {
                // Pak het product uit 
                while (remaining > 0 && pallet.takeOne())
                {
                    remaining--;  //de producten worden uitgepakt
                }

                // als de gewenste hoevoeelheid bereikt is
                if (remaining == 0)
                {
                    return true;
                }
            }
        }
    }

    // er zijn niet genoeg producten
    return false;
}
