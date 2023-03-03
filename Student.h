#include <iostream>
#include <stdlib.h>

using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

class Student{
    private:
        string firstName;
        string lastName;
        string userID;
        string bNumber;
    
    public:
        Student();
        Student(string bNumber, string userID, string firstName, string lastName);

        string getFirstName();
        string getLastName();
        string getUserID();
        string getBNumber();
};

#endif