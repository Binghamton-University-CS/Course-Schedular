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
        Registration();
        Registration(string newBNumber, string newCRN);

        string getCRN();
        string getBNumber();

};
#endif