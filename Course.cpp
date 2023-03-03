#include <stdlib.h>
#include <iostream>

#include "Course.h"

Course::Course() {
    crn = "";
    name = "";
    department = "";
    number = "";
}

Course::Course(string newCRN, string newDepartment, string newNumber, string newName) {
    crn = newCRN;
    name = newName;
    department = newDepartment;
    number = newNumber;
}

string Course::getCRN(){
    return crn;
}

string Course::getDepartment() {
    return department;
}

string Course::getName() {
    return name;
}

string Course::getNumber() {
    return number;
}