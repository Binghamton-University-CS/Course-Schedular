#include <stdlib.h>
#include <iostream>

#include "RegistrationList.h"
#include "StudentList.h"
#include "CourseList.h"

RegistrationList::RegistrationList() {
    crn = "";
    bNumber = "";
    capacity = 1;
    currentQuantity = 0;
    allRegistrations = new Registration[capacity];
}

RegistrationList::RegistrationList(string newBNumber, string newCRN) {
    bNumber = newBNumber;
    crn = newCRN;
    capacity = 1;
    currentQuantity = 0;
    allRegistrations = new Registration[capacity];
}

// Student::Student(const Student& student) {
//     firstName = student.firstName;
//     lastName = student.lastName;
//     userID = student.userID;
//     bNumber = student.bNumber;
// }

RegistrationList::~RegistrationList() {
    delete[] allRegistrations;
}

bool RegistrationList::checkRegExists(Registration newReg) {
    if(currentQuantity == 0) {
        return true;
    }
    for(int i = 0; i < currentQuantity; i++) {
        cout << "here?" << endl;
        if(allRegistrations[i].getCRN() == newReg.getCRN() && allRegistrations[i].getBNumber() == newReg.getBNumber()) {
            return false;
        }
    }
    cout << "1" << endl;
    return true;
}

bool RegistrationList::check(Registration newReg) {
    StudentList student;
    CourseList course;
    for(int i = 0; i < currentQuantity; i++) {
        if(student.checkByBNum(newReg.getBNumber())) {
            if(course.checkByCRN(newReg.getCRN())) {
                return true;
            }
        }
    }
    return false;
}

void RegistrationList::printRoster(string newCRN) {
    StudentList newStudentList;
    cout << "CRN: " << newCRN << endl;
    int numStudent = 0;
    for(int i = 0; i < currentQuantity; i++) {
        if(allRegistrations[i].getCRN() == newCRN) {
            numStudent += 1;
        }
    }
    cout << "Students: " << numStudent << endl;
    for(int i = 0; i < currentQuantity; i++) {
        if(allRegistrations[i].getCRN() == newCRN) {
            string name = newStudentList.searchByBnumReturnName(allRegistrations[i].getBNumber());
            cout << allRegistrations[i].getBNumber() << " " << name << endl;
        }
    }

}

void RegistrationList::printSchedule(string newBNumber) {
    CourseList newCourseList;
    StudentList newStudentList;
    cout << "Student: " << newBNumber << ": ";
    for(int i = 0; i < currentQuantity; i++) {
        if(allRegistrations[i].getBNumber() == newBNumber) {
            string name = newStudentList.searchByBnumReturnName(allRegistrations[i].getBNumber());
            cout << allRegistrations[i].getBNumber() << " " << name << endl;
            break;
        }
    }
    for(int i = 0; i < currentQuantity; i++) {
        if(allRegistrations[i].getBNumber() == newBNumber) {
            string info = newCourseList.searchByCRNReturnInfo(allRegistrations[i].getCRN());
            cout << allRegistrations[i].getCRN() << " " << info << endl;
        }
    }
}

void RegistrationList::resizeArray(){
    capacity = capacity * 2;
    Registration* newReg = new Registration[capacity];

    for(int i = 0; i < currentQuantity; i++){
        newReg[i] = allRegistrations[i]; // copy over values   
    }
    // memory management    
    delete[] allRegistrations;
    allRegistrations = newReg;
}

void RegistrationList::addReg(Registration addReg) {
    if(currentQuantity == capacity){
        resizeArray();
    }
    allRegistrations[currentQuantity] = addReg;
    currentQuantity += 1;
    print();
}

void RegistrationList::dropReg(Registration dropReg) {
    // int size = currentQuantity;

    // for(int i = 0; i < size; i++) {
    //     if(allRegistrations[i].getBNumber() == removeReg.getBNumber)
    // }
}

 void RegistrationList::print() {
    for(int i = 0; i < currentQuantity; i++) {
        cout << "Success: added student " << allRegistrations[i].getBNumber() << " into course " << allRegistrations[i].getCRN() << endl;
    }
 }

string RegistrationList::getBNumber(){
    return bNumber;
}

string RegistrationList::getCRN() {
    return crn;
}

void RegistrationList::setCRN(string newCRN) {
    crn = newCRN;
}

void RegistrationList::setBNumber(string newBNumber) {
    bNumber = newBNumber;
}