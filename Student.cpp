#include <stdlib.h>
#include <iostream>

#include "Student.h"

Student::Student() {
    firstName = "";
    lastName = "";
    userID = "";
    bNumber = "";
}

Student::Student(string newBNumber, string newUserID, string newFirst, string newLast) {
    firstName = newFirst;
    lastName = newLast;
    userID = newUserID;
    bNumber = newBNumber;
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