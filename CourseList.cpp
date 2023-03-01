#include <stdlib.h>
#include <iostream>

#include "CourseList.h"

CourseList::CourseList() {
    crn = "";
    name = "";
    department = "";
    number = "";
    capacity = 0;
    currentQuantity = 0;
}

CourseList::CourseList(string newCRN, string newDepartment, string newNumber, string newName) {
    crn = newCRN;
    name = newName;
    department = newDepartment;
    number = newNumber;
    capacity = 2;
    currentQuantity = 0;
}

// CourseList::CourseList(string newCRN) {
//     crn = newCRN;
// }

CourseList::~CourseList() {
    delete[] allCourses;
}

bool CourseList::checkCourseExists(Course newCourse) {
    // for(int i = 0; i < allCourses.size(); i++) {
    //     if(allCourses[i] == newStudent) {
    //         return false;
    //     }
    // }
    return false;
}

// bool CourseList::searchByBnum(string bNum){
//     int i;
//     for(i = 0; i < allCourses.size(); i++) {
//         if(allCourses.bNumber == bNum) {

//         }
//     }
// }
        
void CourseList::addCourse(Course addCourse) {
    cout << "is it here?" << endl;
    // allStudents = new CourseList[capacity];
    if(currentQuantity == capacity){
        resizeArray();
    }
    cout << "does it work here?" << endl;
    if(checkCourseExists(addCourse)) {
        cout << "Student already exists" << endl;
    }
    else {
        cout << currentQuantity << endl;
        allCourses[currentQuantity] = addCourse;
        cout << "one" << endl;
        cout << getCRN() << endl;
        cout << "two" << endl;
        currentQuantity += 1;
    }
}

void CourseList::removeCourse(Course removeCourse) {
    if(checkCourseExists(removeCourse)) {
        cout << "Student doesn't exists" << endl;
    }
    else {
        // allCourses[currentQuantity] = NULL;
        currentQuantity -= 1;
    }
}

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

// void CourseList::insertStudent(Course courseToAdd){
//     if(currentQuantity == capacity){
//         resizeArray();
//     }
//     registeredStudents[currentQuantity] = toAdd;
//     currentQuantity++:
// }

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