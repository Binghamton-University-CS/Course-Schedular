#include <iostream>
#include <stdlib.h>

using namespace std;

#ifndef REGISTRATIONLIST_H
#define REGISTRATIONLIST_H

#include "Registration.h"

class RegistrationList {
    private:
        string crn;
        string bNumber;
        int capacity;
        int currentQuantity;

        Registration* allRegistrations; // list of all students in a course

    public:
        RegistrationList();
        RegistrationList(string newCRN, string newBNumber);
        ~RegistrationList();

        void addReg(Registration addReg);
        void dropReg(Registration dropReg);
        void resizeArray();
        void printListOfStudents(Registration allCourses);
        void printRoster(string newCRN);
        void printSchedule(string newBNumber);
        void print();

        bool check(Registration newReg);
        bool checkRegExists(Registration newReg);
        void searchByCRN(string newCRN);

        // getters: returns value

        string getCRN();
        string getBNumber();

        // setters

        void setCRN(string newCRN);
        void setBNumber(string newName);
};
#endif