#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "Student.h"

class StudentList {
    private:

        // array values
        int capacity;
        int currentQuantity;
        string firstName;
        string lastName;
        string userID;
        string bNumber;

        Student* allStudents;

    public:
        StudentList();
        StudentList(string newBNumber, string newUserID, string newLast, string newFirst); 
        ~StudentList();

        void addStudent(Student addStudent);
        void resizeArray();
        void print();
        void printName(string bNum);
        void searchByBnumPrintName(vector<string> bNums);
        
        bool searchByBnum(string bNum);

        string getFirstName();
        string getLastName();
        string getUserID();
        string getBNumber();
};
#endif