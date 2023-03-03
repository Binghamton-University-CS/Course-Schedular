#include <stdlib.h>
#include <iostream>

#include "Registration.h"

Registration::Registration() {
    crn = "";
    bNumber = "";
}

Registration::Registration(string newBNumber, string newCRN) {
    crn = newCRN;
    bNumber = newBNumber;
}

string Registration::getCRN(){
    return crn;
}

string Registration::getBNumber() {
    return bNumber;
}