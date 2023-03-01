#include <iostream>
#include <stdlib.h>

using namespace std;

#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "Student.h"

class StudentList {
    public:
        StudentList();
        StudentList(string newBNumber, string newUserID, string newLast, string newFirst); // enroll
        StudentList(string bNumber); // add & drop & schedule
        ~StudentList();

        void addStudent(Student addStudent);
        void removeStudent(Student removeStudent);
        void enrollStudent(Student enrollStudent);
        void resizeArray();
        void print();
        
        bool searchByBnum(string bNum);
        // bool checkStudentExists(Student newStudent);

        void printListOfCourses();

    private:

        // array values
        int capacity;
        int currentQuantity;
        string firstName;
        string lastName;
        string userID;
        string bNumber;

        Student* allStudents; // list of all courses a student takes

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