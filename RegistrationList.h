#include <iostream>
#include <stdlib.h>
#include <vector>

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
        void cancelReg(string cancelReg);
        void resizeArray();
        
        vector<string> returnBnum(string newCRN);
        vector<string> returnCrn(string newBNumber);
        void printAdd();
        void printDrop(Registration dropReg);
        void printCancel(string cancelReg);
        void searchByCRN(string newCRN);

        bool check(Registration orgReg, Registration newReg);
        bool checkRegExists(Registration newReg);

        string getCRN();
        string getBNumber();
};
#endif