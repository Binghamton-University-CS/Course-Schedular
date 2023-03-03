#include <stdlib.h>
#include <iostream>
#include <vector>

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

RegistrationList::~RegistrationList() {
    delete[] allRegistrations;
}

bool RegistrationList::check(Registration orgReg, Registration newReg) {
    for(int i = 0; i < currentQuantity; i++) {
        if(orgReg.getBNumber() == newReg.getBNumber() && orgReg.getCRN() == newReg.getCRN()) {
            return true;
        }
    }
    return false;
}

bool RegistrationList::checkRegExists(Registration newReg) {
    if(currentQuantity == 0) {
        return true;
    }
    for(int i = 0; i < currentQuantity; i++) {
        if(check(allRegistrations[i], newReg)) {
            return false;
        }
    }
    return true;
}

vector<string> RegistrationList::returnBnum(string newCRN) {
    vector<string> bNumbers;
    for(int i = 0; i < currentQuantity; i++) {
        if(allRegistrations[i].getCRN() == newCRN) {
            bNumbers.push_back(allRegistrations[i].getBNumber()); 
        }
    }
    return bNumbers;
}

vector<string> RegistrationList::returnCrn(string newBNumber) {
    vector<string> crns;
    for(int i = 0; i < currentQuantity; i++) {
        if(allRegistrations[i].getBNumber() == newBNumber) {
            crns.push_back(allRegistrations[i].getCRN()); 
        }
    }
    return crns;
}

void RegistrationList::addReg(Registration addReg) {
    if(currentQuantity == capacity){
        resizeArray();
    }
    allRegistrations[currentQuantity] = addReg;
    printAdd();
    currentQuantity += 1;
}

void RegistrationList::dropReg(Registration dropReg) {
    if(currentQuantity == 1) {
        currentQuantity -= 1;
        printDrop(dropReg);
    }
    else {
        int position;
        for(int i = (currentQuantity-1);i >= 0; i--) {
            if(check(allRegistrations[i], dropReg)) {
                position = i;
            }
        }
        if(position == currentQuantity - 1) {
            currentQuantity -= 1;
        }
        else {
            while(position < currentQuantity) {
                allRegistrations[position] = allRegistrations[position+1];
                position++;
            }
            currentQuantity -= 1;
        }
        printDrop(dropReg);
    }
}

void RegistrationList::cancelReg(string cancelReg) {
    Registration* temp = new Registration[capacity];
    for(int i = 0; i <= currentQuantity; i++) {
        temp[i] = allRegistrations[i];
    }

    int size = currentQuantity;
    if(currentQuantity == 1) {
        currentQuantity -= 1;
    }
    else {
        for(int i = (size-1); i >= 0; i--) {
            if(temp[i].getCRN() == cancelReg) {
                if(i == size - 1) { 
                    currentQuantity -= 1;
                }
                else {
                    int j = i;
                    while(j < size-1) {
                        allRegistrations[j] = allRegistrations[j+1];
                        j++;
                    }
                    currentQuantity -= 1;
                }
            }
        }
    }
    delete[] temp;
    printCancel(cancelReg);
}

void RegistrationList::resizeArray(){
    capacity = capacity * 2;
    Registration* newReg = new Registration[capacity];

    for(int i = 0; i < currentQuantity; i++){
        newReg[i] = allRegistrations[i]; 
    }  
    delete[] allRegistrations;
    allRegistrations = newReg;
}

void RegistrationList::printCancel(string cancelReg) {
    cout << "Success: cancelled course " << cancelReg << endl;
 }

void RegistrationList::printDrop(Registration dropReg) {
    cout << "Success: removed student " << dropReg.getBNumber() << " from course " << dropReg.getCRN() << endl;
 }

void RegistrationList::printAdd() {
    cout << "Success: added student " << allRegistrations[currentQuantity].getBNumber() << " into course " << allRegistrations[currentQuantity].getCRN() << endl;
 }

string RegistrationList::getBNumber(){
    return bNumber;
}

string RegistrationList::getCRN() {
    return crn;
}