#include <stdlib.h>
#include <iostream>

#include "Student.h"

Student::Student() {
    firstName = "";
    lastName = "";
    userID = "";
    bNumber = "";
    capacity = 1;
    currentQuantity = 0;
    allCourses = new Course[capacity];
}

Student::Student(string newBNumber, string newUserID, string newFirst, string newLast) {
    cout << "1" << endl;
    firstName = newFirst;
    cout << "2" << endl;
    lastName = newLast;
    cout << "3" << endl;
    userID = newUserID;
    cout << "4" << endl;
    bNumber = newBNumber;
    cout << "5" << endl;
    capacity = 1;
    cout << "6" << endl;
    currentQuantity = 0;
    cout << "7" << endl;
    allCourses = new Course[capacity];
    cout << "8" << endl;
}

// Student::Student(const Student& student) {
//     firstName = student.firstName;
//     lastName = student.lastName;
//     userID = student.userID;
//     bNumber = student.bNumber;
// }

// Student::~Student() {
//     delete[] allStudents;
// }

bool Student::checkCourseExists(Course newCourse) {
    // for(int i = 0; i < allStudents.size(); i++) {
    //     if(allStudents[i] == newStudent) {
    //         return false;
    //     }
    // }
    return false;
}

void Student::resizeArray(){
    capacity = capacity * 2;
    Course* newCourse = new Course[capacity];

    for(int i = 0; i < currentQuantity; i++){
        newCourse[i] = allCourses[i]; // copy over values   
    }
    // memory management    
    delete[] allCourses;
    allCourses = newCourse;
}

void Student::addCourse(Course addCourse) {
    // cout << "is it here?" << endl;
    // Course* newCourse;
    if(currentQuantity == capacity){
        resizeArray();
    }
    // cout << "does it work here?" << endl;
    if(checkCourseExists(addCourse)) {
        cout << "Course already exists" << endl;
    }
    else {
        cout << currentQuantity << endl;
        allCourses[currentQuantity] = addCourse;
        
        // cout << "one" << endl;
        cout << getBNumber() << endl;
        // cout << "two" << endl;
        currentQuantity += 1;
    }
}

void Student::showCourses() {
    int i;
    cout << "Students: " << currentQuantity << endl;
    for(i = 0; i < currentQuantity; i++) {
        cout << "allStudents.at(i)" << endl;
    }
 }

string Student::getFirstName(){
    return firstName;
}

string Student::getLastName() {
    return lastName;
}

string Student::getUserID() {
    return userID;
}

string Student::getBNumber() {
    return bNumber;
}

void Student::setFirstName(string newFirstName) {
    firstName = newFirstName;
}

void Student::setLastName(string newLastName) {
    lastName = newLastName;
}

void Student::setUserID(string newUserID) {
    userID = newUserID;
}

void Student::setBNumber(string newBNumber) {
    bNumber = newBNumber;
}