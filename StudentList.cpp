#include <stdlib.h>
#include <iostream>
#include <vector>

#include "StudentList.h"

StudentList::StudentList() {
    firstName = "";
    lastName = "";
    userID = "";
    bNumber = "";
    capacity = 1;
    currentQuantity = 0;
    allStudents = new Student[capacity];
}

StudentList::StudentList(string newBNumber, string newUserID, string newFirst, string newLast){
    firstName = newFirst;
    lastName = newLast;
    userID = newUserID;
    bNumber = newBNumber;
    capacity = 1;
    currentQuantity = 0;
    allStudents = new Student[capacity];
}

StudentList::~StudentList() {
    delete[] allStudents;
}

bool StudentList::searchByBnum(string bNum){
    for(int i = 0; i < currentQuantity; i++) {
        if(allStudents[i].getBNumber() == bNum) {
            return false;
        }
    }
    return true;
}

void StudentList::searchByBnumPrintName(vector<string> bNums){
    for(int i = 0; i < currentQuantity; i++) {
        for(unsigned int j = 0; j < bNums.size(); j++) {
            if(allStudents[i].getBNumber() == bNums.at(j)) {
                cout << allStudents[i].getBNumber() << " " << allStudents[i].getFirstName() << " " << allStudents[i].getLastName() << endl;
            }
        }
    }
}

void StudentList::addStudent(Student addStudent) {
    if(currentQuantity == capacity){
        resizeArray();
    }
    if(searchByBnum(addStudent.getBNumber())) {
        allStudents[currentQuantity] = addStudent;
        print();
        currentQuantity += 1;
    }
    else {
        cout << "Fail: cannot enroll student, B Number exists" << endl;
    }
}

void StudentList::resizeArray(){
    capacity = capacity * 2;
    Student* newStudent = new Student[capacity];

    for(int i = 0; i < currentQuantity; i++){
        newStudent[i] = allStudents[i]; 
    }
    delete[] allStudents;
    allStudents = newStudent;
}

void StudentList::printName(string bNum) {
    for(int i = 0; i < currentQuantity; i++) {
        if(allStudents[i].getBNumber() == bNum) {
            cout << allStudents[i].getFirstName() << " " << allStudents[i].getLastName() << endl;
        }
    }
}

void StudentList::print() {
    cout << "Success: enrolled student " << allStudents[currentQuantity].getBNumber() << " (" << allStudents[currentQuantity].getUserID() << ") " << allStudents[currentQuantity].getLastName() << ", " << allStudents[currentQuantity].getFirstName() << endl;
}

string StudentList::getFirstName(){
    return firstName;
}

string StudentList::getLastName() {
    return lastName;
}

string StudentList::getUserID() {
    return userID;
}

string StudentList::getBNumber() {
    return bNumber;
}