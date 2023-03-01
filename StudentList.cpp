#include <stdlib.h>
#include <iostream>

#include "StudentList.h"
// #include "Course.cpp"

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

StudentList::StudentList(string newBNumber) {
    bNumber = newBNumber;
}

StudentList::~StudentList() {
    delete[] allStudents;
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

bool StudentList::searchByBnum(string bNum){
    for(int i = 0; i < currentQuantity; i++) {
        if(allStudents[i].getBNumber() == bNum) {
            return false;
        }
    }
    return true;
}
        
void StudentList::enrollStudent(Student enrollStudent) {
    // cout << "is it here?" << endl;
    // // allStudents = new StudentList[capacity];
    // if(currentQuantity == capacity){
    //     resizeArray();
    // }
    // cout << "does it work here?" << endl;
    // if(checkStudentExists(enrollStudent)) {
    //     cout << "Student already exists" << endl;
    // }
    // else {
    //     cout << currentQuantity << endl;
    //     allStudents[currentQuantity] = enrollStudent;
    //     cout << "one" << endl;
    //     cout << allStudents[currentQuantity].firstName << endl;
    //     cout << "two" << endl;
    //     currentQuantity += 1;
    // }
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
        cout << "Student already exists" << endl;
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
    delete[] allStudents;
    allStudents = newStudent;
}

void StudentList::print() {
    // cout << sizeof(allStudents)/sizeof(allStudents[0]) << endl;
    // cout << currentQuantity << endl;
    //  cout << " " << allStudents[0].getFirstName() << " " << allStudents[0].getLastName() << " " << allStudents[0].getBNumber() << endl;
    for(int i = 0; i < currentQuantity; i++) {
        cout << allStudents[i].getFirstName() << " " << allStudents[i].getLastName() << " " << allStudents[i].getUserID() << " " << allStudents[i].getBNumber() << endl;
        // cout << allStudents[i] << endl;
        cout << endl;
    }
}

// void Course::insertStudent(Student* addStudent){
//     if(currentQuantity == capacity){
//         resizeArray();
//     }
//     listOfCourses[currentQuantity] = addStudent;
//     currentQuantity++:
// }

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