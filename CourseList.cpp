#include <stdlib.h>
#include <iostream>

#include "CourseList.h"

CourseList::CourseList() {
    crn = "";
    name = "";
    department = "";
    number = "";
    capacity = 1;
    currentQuantity = 0;
    allCourses = new Course[capacity];
}

CourseList::CourseList(string newCRN, string newDepartment, string newNumber, string newName) {
    crn = newCRN;
    name = newName;
    department = newDepartment;
    number = newNumber;
    capacity = 1;
    currentQuantity = 0;
    allCourses = new Course[capacity];
}

CourseList::~CourseList() {
    delete[] allCourses;
}

bool CourseList::searchByCRN(string newCRN){
    for(int i = 0; i < currentQuantity; i++) {
        if(allCourses[i].getCRN() == newCRN) {
            return false;
        }
    }
    return true;
}

string CourseList::searchByCRNReturnInfo(string info) {
    string str = "";
    for(int i = 0; i < currentQuantity; i++) {
        if(allCourses[i].getCRN() == info) {
            str += allCourses[i].getDepartment() + " " + allCourses[i].getNumber() + " " + allCourses[i].getName();
            return str;
        }
    }
    return "";
}

bool CourseList::checkByCRN(string newCRN) {
    for(int i = 0; i < currentQuantity; i++) {
        if(allCourses[i].getCRN() == newCRN) {
            return true;
        }
    }
    return false;
}

void CourseList::addCourse(Course addCourse) {
    if(currentQuantity == capacity){
        resizeArray();
    }
    if(searchByCRN(addCourse.getCRN())) {
        allCourses[currentQuantity] = addCourse;
        currentQuantity += 1;
        print();
    }
    else {
        cout << "Fail: cannot enroll student, B Number exists" << endl;
    }
}

// void CourseList::whatever(int course) {
//     cout << course << endl;
// }

void CourseList::print() {
    for(int i = 0; i < currentQuantity; i++) {
        cout << "Success: built course " << allCourses[i].getDepartment() << allCourses[i].getNumber() << " (CRN: " << allCourses[i].getCRN() << "): " << allCourses[i].getName() << endl;
    }
}

// void CourseList::removeCourse(Course removeCourse) {
//     if(checkCourseExists(removeCourse)) {
//         cout << "Student doesn't exists" << endl;
//     }
//     else {
//         // allCourses[currentQuantity] = NULL;
//         currentQuantity -= 1;
//     }
// }

void CourseList::resizeArray(){
    capacity = capacity * 2;
    Course* newCourses = new Course[capacity];

    for(int i = 0; i < currentQuantity; i++){
        newCourses[i] = allCourses[i]; // copy over values   
    }
    // memory management   
    delete[] allCourses;
    allCourses = newCourses;
}

string CourseList::getCRN(){
    return crn;
}

string CourseList::getDepartment() {
    return department;
}

string CourseList::getName() {
    return name;
}

string CourseList::getNumber() {
    return number;
}

void CourseList::setCRN(string newCRN) {
    crn = newCRN;
}

void CourseList::setDepartment(string newDepartment) {
    department = newDepartment;
}

void CourseList::setName(string newName) {
    name = newName;
}

void CourseList::setNumber(string newNumber) {
    number = newNumber;
}