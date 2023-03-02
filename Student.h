#include <iostream>
#include <stdlib.h>

using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

#include "Course.h"

class Student{
    private:
        string firstName;
        string lastName;
        string userID;
        string bNumber;
        // int capacity;
        // int currentQuantity;

        // Course* allCourses; // list of all courses a students take
    
    public:
        //? implement 4 constructors (default, copy, assignment)
        Student();
        Student(string bNumber, string userID, string firstName, string lastName);
        // Student(const Student& student);
        // ~Student();

        // core functionality methods
        // void showCourses(); // loop over registered students and print out (what command roster does)
        // void addCourse(Course addCourse);
        // void resizeArray();
        // bool checkCourseExists(Course newCourse);

        // getters: returns value

        string getFirstName();
        string getLastName();
        string getUserID();
        string getBNumber();

        // setters

        void setFirstName(string newFirstName);
        void setLastName(string newLastName);
        void setUserID(string newUserID);
        void setBNumber(string newBNumber);

};

#endif