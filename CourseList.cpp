#include "CourseList.h"

Course::CourseList() {
    crn = "";
    name = "";
    department = "";
    number = "";
}

Course::CourseList(string newCRN, string newName, string newDepartment, string newNumber) {
    crn = newCRN;
    name = newName;
    department = newDepartment;
    number = newNumber;
}

Course::CourseList(const StudentList& student) {
    crn = student.crn;
    name = student.name;
    department = student.department;
    number = student.number;
}

Course::~CourseList() {
    delete[] registeredStudents;
}

void Course::showRegStudents() {
    int i;

    for(i = 0; i < regStudents.size(); i++) {
        cout << regStudents.at(i) << endl;
    }
 }

void Course::resizeArray(){
    capacity = capacity * 2;
    StudentList* newRegStudents = new StudentList[capacity];

    for(int i = 0; i < currentQuantity; i++){
        newRegStudents[i] = regStudents[i]; // copy over values   
    }
    // memory management    
    delete[] regStudents;
    regStudents = newRegStudents;
}

void Course::insertStudent(StudentList toAdd){
    if(currentQuantity == capacity){
        resizeArray();
    }
    registeredStudents[currentQuantity] = toAdd;
    currentQuantity++:
}

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