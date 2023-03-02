#include <iostream>
#include <stdlib.h>

using namespace std;

#ifndef COURSE_H
#define COURSE_H

class Course{
    private:
        string crn;
        string name;
        string department;
        string number;

        // int capacity;
        // int currentQuantity;

        // string* listOfBnumbers; // list of all students in a course
    
    public:
        //? implement 4 constructors (default, copy, assignment)
        Course();
        Course(string newCRN, string newDepartment, string newNumber, string newName); // build
        Course(string newCRN);
        // Course(const Course& course);
        // ~Course();

        // core functionality methods
        void showRegStudents(); // loop over registered students and print out (what command roster does)
        // void addStudent(string bNumber);
        // void resizeArray(); 
        // getters: returns value

        string getCRN();
        string getName();
        string getDepartment();
        string getNumber();

        // setters

        void setCRN(string newCRN);
        void setName(string newName);
        void setDepartment(string newDepartment);
        void setNumber(string newNumber);

};

#endif