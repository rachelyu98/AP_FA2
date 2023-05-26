#include <iostream>
#include "src/include/warehouse.hpp"
#include "src/include/employee.hpp"
#include "src/include/IContainer.hpp"
#include "src/include/pallet.hpp"
#include "src/include/shelf.hpp"



int main(void){
    // om een warehouse aan te maken kan je deze regel uitvoeren
    // Dit is nodig om de rest van je warehouse op te stellen
    Warehouse warehouse = Warehouse();

    // Als je een warehouse hebt kan je die inrichten met shelves.
    // Op elke shelf passen 4 pallets met items daarop.
    // Hieronder staat een voorbeeld met een shelf(shelf1) die wordt aangemaakt met op die shelf 4 pallets met items
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Apple", 100, 40), 
        Pallet("Banana", 80, 10), 
        Pallet("Books", 50, 20), 
        Pallet("Shoes", 60, 20)
    };

    warehouse.addShelf(shelf1);

    // Een pallet is opgebouwd uit een naam, itemCapacity ern itemCount

    Shelf shelf2 = Shelf();
    shelf2.pallets = {
        Pallet("Apple", 100, 15), 
        Pallet("Shoes", 60, 20), 
        Pallet("Banana", 80, 5), 
        Pallet("Milk", 20, 30)
    };

    warehouse.addShelf(shelf2);

    //Bob wordt toegevoegd aan Warehouse
    warehouse.addEmployee(Employee("Bob", true));

    

    std::cout<<"Warehouse"<< std::endl;
    std::cout<<" "<< std::endl;

    //eerst laten zien hoe mijn orginele shelf1 eruit ziet
    std::cout<< "Pallet1: Naam: " << shelf1.pallets[0].getItemName() << ", itemcount: "<< shelf1.pallets[0].getItemCount() << std::endl;
    std::cout<<" "<< std::endl;
    std::cout<< "Pallet2: Naam: " << shelf1.pallets[1].getItemName() << ", itemcount: "<< shelf1.pallets[1].getItemCount() << std::endl;
    std::cout<<" "<< std::endl;
    std::cout<< "Pallet3: Naam: " << shelf1.pallets[2].getItemName() << ", itemcount: "<< shelf1.pallets[2].getItemCount() << std::endl;
    std::cout<<" "<< std::endl;
    std::cout<< "Pallet4: Naam: " << shelf1.pallets[3].getItemName() << ", itemcount: "<< shelf1.pallets[3].getItemCount() << std::endl;
    std::cout<<" "<< std::endl;
    std::cout<<" "<< std::endl;

    

    //laten zien hoe mijn orginele shelf2 eruit ziet
    std::cout<< "Pallet1: Naam: " << shelf2.pallets[0].getItemName() << ", itemcount: "<< shelf2.pallets[0].getItemCount() << std::endl;
    std::cout<<" "<< std::endl;
    std::cout<< "Pallet2: Naam: " << shelf2.pallets[1].getItemName() << ", itemcount: "<< shelf2.pallets[1].getItemCount() << std::endl;
    std::cout<<" "<< std::endl;
    std::cout<< "Pallet3: Naam: " << shelf2.pallets[2].getItemName() << ", itemcount: "<< shelf2.pallets[2].getItemCount() << std::endl;
    std::cout<<" "<< std::endl;
    std::cout<< "Pallet4: Naam: " << shelf2.pallets[3].getItemName() << ", itemcount: "<< shelf2.pallets[3].getItemCount() << std::endl;
    std::cout<<" "<< std::endl;
    std::cout<<" "<< std::endl;

    //rearrange shelf1
    bool success1 = warehouse.rearrangeShelf(warehouse.shelves[0]);
    if (success1) {
    std::cout << "Shelf1 is successful gesorteerd: " << std::endl;
    } 
    else {
    std::cout << "Rearrange Shelf1 failed." << std::endl;
    }

    //laten zien hoe shelf 1 na rearrange eruit ziet
    std::cout<<" "<< std::endl;
    std::cout << "Pallet1: Naam: " << warehouse.shelves[0].pallets[0].getItemName() << ", itemcount: " << warehouse.shelves[0].pallets[0].getItemCount() << std::endl;
    std::cout << " " << std::endl;
    std::cout << "Pallet2: Naam: " << warehouse.shelves[0].pallets[1].getItemName() << ", itemcount: " << warehouse.shelves[0].pallets[1].getItemCount() << std::endl;
    std::cout << " " << std::endl;
    std::cout << "Pallet3: Naam: " << warehouse.shelves[0].pallets[2].getItemName() << ", itemcount: " << warehouse.shelves[0].pallets[2].getItemCount() << std::endl;
    std::cout << " " << std::endl;
    std::cout << "Pallet4: Naam: " << warehouse.shelves[0].pallets[3].getItemName() << ", itemcount: " << warehouse.shelves[0].pallets[3].getItemCount() << std::endl;
    std::cout << " " << std::endl;
    std::cout << " " << std::endl;
    
    //sorteren shelf2
    bool success2 = warehouse.rearrangeShelf(warehouse.shelves[1]);
    if (success2) {
    std::cout << "Shelf2 is successful gesorteerd: " << std::endl;
    } 
    else {
    std::cout << "Rearrange Shelf2 failed." << std::endl;
    }
    

    //laten zien hoe shelf 2 na rearrange eruit ziet
    std::cout<<" "<< std::endl;
    std::cout << "Pallet1: Naam: " << warehouse.shelves[1].pallets[0].getItemName() << ", itemcount: " << warehouse.shelves[1].pallets[0].getItemCount() << std::endl;
    std::cout << " " << std::endl;
    std::cout << "Pallet2: Naam: " << warehouse.shelves[1].pallets[1].getItemName() << ", itemcount: " << warehouse.shelves[1].pallets[1].getItemCount() << std::endl;
    std::cout << " " << std::endl;
    std::cout << "Pallet3: Naam: " << warehouse.shelves[1].pallets[2].getItemName() << ", itemcount: " << warehouse.shelves[1].pallets[2].getItemCount() << std::endl;
    std::cout << " " << std::endl;
    std::cout << "Pallet4: Naam: " << warehouse.shelves[1].pallets[3].getItemName() << ", itemcount: " << warehouse.shelves[1].pallets[3].getItemCount() << std::endl;
    std::cout << " " << std::endl;
    std::cout << " " << std::endl;


    //200 appels uit shelf pakken
    bool successful = warehouse.pickItems("Apple", 55);
    if (successful) {
    std::cout << "55 appels succesful uit warehouse gepakt " << std::endl;
    } 
    else {
    std::cout << "uitpakken failed." << std::endl;
    }

    //laten zien hoe shelf 1 na uitpakken eruit ziet
    std::cout<<" "<< std::endl;
    std::cout << "Pallet1: Naam: " << warehouse.shelves[0].pallets[0].getItemName() << ", itemcount: " << warehouse.shelves[0].pallets[0].getItemCount() << std::endl;
    std::cout << " " << std::endl;
    std::cout << "Pallet2: Naam: " << warehouse.shelves[0].pallets[1].getItemName() << ", itemcount: " << warehouse.shelves[0].pallets[1].getItemCount() << std::endl;
    std::cout << " " << std::endl;
    std::cout << "Pallet3: Naam: " << warehouse.shelves[0].pallets[2].getItemName() << ", itemcount: " << warehouse.shelves[0].pallets[2].getItemCount() << std::endl;
    std::cout << " " << std::endl;
    std::cout << "Pallet4: Naam: " << warehouse.shelves[0].pallets[3].getItemName() << ", itemcount: " << warehouse.shelves[0].pallets[3].getItemCount() << std::endl;
    std::cout << " " << std::endl;
    std::cout << " " << std::endl;


    //laten zien hoe shelf 2 na uitpakken eruit ziet
    std::cout<<" "<< std::endl;
    std::cout << "Pallet1: Naam: " << warehouse.shelves[1].pallets[0].getItemName() << ", itemcount: " << warehouse.shelves[1].pallets[0].getItemCount() << std::endl;
    std::cout << " " << std::endl;
    std::cout << "Pallet2: Naam: " << warehouse.shelves[1].pallets[1].getItemName() << ", itemcount: " << warehouse.shelves[1].pallets[1].getItemCount() << std::endl;
    std::cout << " " << std::endl;
    std::cout << "Pallet3: Naam: " << warehouse.shelves[1].pallets[2].getItemName() << ", itemcount: " << warehouse.shelves[1].pallets[2].getItemCount() << std::endl;
    std::cout << " " << std::endl;
    std::cout << "Pallet4: Naam: " << warehouse.shelves[1].pallets[3].getItemName() << ", itemcount: " << warehouse.shelves[1].pallets[3].getItemCount() << std::endl;
    std::cout << " " << std::endl;
    std::cout << " " << std::endl;
}
