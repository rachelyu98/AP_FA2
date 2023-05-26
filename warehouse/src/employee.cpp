#pragma once
#include "include/employee.hpp"


Employee::Employee(const std::string name, bool forkliftCertificate)
    : name(name), busy(false), forkliftCertificate(forkliftCertificate){}


std::string Employee::getName(){
    return name;
}

bool Employee::getBusy(){
    return busy;
}

void Employee::setBusy(bool busy){
    this->busy = busy;
}

bool Employee::getForkliftCertificate(){
    return forkliftCertificate;
}

void Employee::setForkliftCertificate(bool forkliftCertificate){
    this->forkliftCertificate = forkliftCertificate;
}











