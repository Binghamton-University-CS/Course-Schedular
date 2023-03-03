#include <stdlib.h>
#include <iostream>
#include <vector>

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

void CourseList::searchByCRNPrintInfo(vector<string> crn) {
    for(int i = 0; i < currentQuantity; i++) {
        for(unsigned int j = 0; j < crn.size(); j++) {
            if(allCourses[i].getCRN() == crn.at(j)) {
                cout << allCourses[i].getCRN() << " " << allCourses[i].getDepartment() << " " << allCourses[i].getNumber() << " " << allCourses[i].getName() << endl;
            }
        }
    }
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
        printBuild();
        currentQuantity += 1;
    }
    else {
        cout << "Fail: cannot enroll student, B Number exists" << endl;
    }
}

void CourseList::removeCourse(string removeCourse) {
    if(currentQuantity == 1) {
        currentQuantity -= 1;
    }
    else {
        int position;
        for(int i = (currentQuantity-1);i >= 0; i--) {
            if(allCourses[i].getCRN() == removeCourse) {
                position = i;
            }
        }
        if(position == currentQuantity - 1) {
            currentQuantity -= 1;
        }
        else {
            while(position < currentQuantity) {
                allCourses[position] = allCourses[position+1];
                position++;
            }
            currentQuantity -= 1;
        }
    }
}

void CourseList::resizeArray(){
    capacity = capacity * 2;
    Course* newCourses = new Course[capacity];

    for(int i = 0; i < currentQuantity; i++){
        newCourses[i] = allCourses[i]; 
    }
    delete[] allCourses;
    allCourses = newCourses;
}

void CourseList::printBuild() {
    cout << "Success: built course " << allCourses[currentQuantity].getDepartment() << allCourses[currentQuantity].getNumber() << " (CRN: " << allCourses[currentQuantity].getCRN() << "): " << allCourses[currentQuantity].getName() << endl;
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