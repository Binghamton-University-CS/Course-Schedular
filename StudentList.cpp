#include <stdlib.h>
#include <iostream>

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

string StudentList::searchByBnumReturnName(string bNum){
    string str = "";
    for(int i = 0; i < currentQuantity; i++) {
        if(allStudents[i].getBNumber() == bNum) {
            str += allStudents[i].getFirstName() + " " + allStudents[i].getLastName();
            return str;
        }
    }
    return "";
}

bool StudentList::checkByBNum(string newBNumber) {
    for(int i = 0; i < currentQuantity; i++) {
        if(allStudents[i].getBNumber() == newBNumber) {
            return true;
        }
    }
    return false;
}

void StudentList::addStudent(Student addStudent) {
    if(currentQuantity == capacity){
        resizeArray();
    }
    if(searchByBnum(addStudent.getBNumber())) {
        allStudents[currentQuantity] = addStudent;
        currentQuantity += 1;
        print();
    }
    else {
        cout << "Fail: cannot enroll student, B Number exists" << endl;
    }
}

void StudentList::removeStudent(Student removeStudent) {
    // if(checkStudentExists(removeStudent)) {
    //     cout << "Student doesn't exists" << endl;
    // }
    // else {
    //     for(int i = 0; i < allStudents.size(); i++) {
    //         if(allStudents[i] == removeStudent) {
    //             break;
    //         }
    //     }
    //     currentQuantity -= 1;
    // }
}

void StudentList::resizeArray(){
    capacity = capacity * 2;
    Student* newStudent = new Student[capacity];

    for(int i = 0; i < currentQuantity; i++){
        newStudent[i] = allStudents[i]; // copy over values   
    }
    // memory management 
    cout << "here?" << endl;   
    delete[] allStudents;
    allStudents = newStudent;
}

void StudentList::print() {
    for(int i = 0; i < currentQuantity; i++) {
        cout << "Success: enrolled student " << allStudents[i].getBNumber() << " (" << allStudents[i].getUserID() << ") " << allStudents[i].getLastName() << ", " << allStudents[i].getFirstName() << endl;
    }
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

void StudentList::setFirstName(string newFirstName) {
    firstName = newFirstName;
}

void StudentList::setLastName(string newLastName) {
    lastName = newLastName;
}

void StudentList::setUserID(string newUserID) {
    userID = newUserID;
}

void StudentList::setBNumber(string newBNumber) {
    bNumber = newBNumber;
}

// StudentList StudentList::operator=(const Student& newStudent) {
//     firstName = newStudent.firstName;
//     lastName = newStudent.lastName;
//     userID = newStudent.userID;
//     bNumber = newStudent.bNumber;
//     capacity = newStudent.capacity;
//     currentQuantity = newStudent.currentQuantity;
// }

// bool StudentList::checkStudentExists(Student newStudent) {
//     for(int i = 0; i < currentQuantity; i++) {
//         if(allStudents[i] == newStudent) {
//             return false;
//         }
//     }
//     return false;
// }