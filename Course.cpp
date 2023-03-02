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

// void Course::checkBNumberExists(string bNum) {
//     for(int i = 0; i < currentQuantity; i++) {
//         if(listOfBnumbers[i].getBNumber() == bNum) {
//             return false;
//         }
//     }
//     return true;
// }

// void Course::addStudent(string addStudent) {
//     if(currentQuantity == capacity){
//         resizeArray();
//     }
//     listOfBnumbers[currentQuantity] = addStudent;
//     currentQuantity++;
// }

// void Course::resizeArray() {
//     capacity = capacity * 2;
//     string* newStudent = new string[capacity];

//     for(int i = 0; i < currentQuantity; i++){
//         newStudent[i] = listOfBnumbers[i]; // copy over values   
//     }
//     // memory management    
//     delete[] listOfBnumbers;
//     listOfBnumbers = newStudent;
// }

// void Course::showRegStudents() {
//     int i;

//     for(i = 0; i < currentQuantity; i++) {
//         cout << getCRN() << endl;
//     }
// }

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

void Course::setCRN(string newCRN) {
    crn = newCRN;
}

void Course::setDepartment(string newDepartment) {
    department = newDepartment;
}

void Course::setName(string newName) {
    name = newName;
}

void Course::setNumber(string newNumber) {
    number = newNumber;
}