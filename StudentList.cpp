#include "StudentList.h"

Course::StudentList() {
    firstName = "";
    secondName = "";
    userID = "";
    bNumber = "";
}

Course::StudentList(string newFirst, string newSecond, string newUserID, string newBNumber) {
    firstName = newFirst;
    secondName = newSecond;
    userID = newUserID;
    bNumber = newBNumber;
}

Course::StudentList(const StudentList& student) {
    firstName = student.firstName;
    secondName = student.secondName;
    userID = student.userID;
    bNumber = student.bNumber;
}

Course::~StudentList() {
    delete[] students;
}

void Course::showRegStudents() {
    int i;

    for(i = 0; i < regStudents.size(); i++) {
        cout << retStudents.at(i) << endl;
    }
 }

void Course::resizeArray(){
    capacity = capacity * 2;
    StudentList* newRegStudents = new StudentList[capacity];

    for(int i = 0; i < currentQuantity; i++){
        newRegStudents[i] = regStudents[i]; // copy over values   
    }
    // memory management    
    delete[] regstudents;
    regstudents = newRegStudents;
}

void Course::insertStudent(StudentList toAdd){
    if(currentQuantity == capacity){
        resizeArray();
    }
    registeredStudents[currentQuantity] = toAdd;
    currentQuantity++:
}

string Course::getFirstName(){
    return firstName;
}

string Course::getSecondName() {
    return secondName;
}

string Course::getUserID() {
    return userID;
}

string Course::getBNumber() {
    return bNumber;
}

void Course::setFirstName(string newFirstName) {
    firstName = newFirstName;
}

void Course::setDepartment(string newSecondName) {
    secondName = newSecondName;
}

void Course::setName(string newUserID) {
    userID = newUserID;
}

void Course::setNumber(string newBNumber) {
    bNumber = newBNumber;
}