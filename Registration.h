#include <iostream>
#include <stdlib.h>

using namespace std;

#ifndef REGISTRATION_H
#define REGISTRATION_H

class Registration{
    private:
        string bNumber;
        string crn;
    
    public:
        //? implement 4 constructors (default, copy, assignment)
        Registration();
        Registration(string newBNumber, string newCRN);

        // getters: returns value

        string getCRN();
        string getBNumber();

        // setters

        void setCRN(string newFirstName);
        void setBNumber(string newBNumber);

};

#endif