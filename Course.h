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
    
    public:
        Course();
        Course(string newCRN, string newDepartment, string newNumber, string newName); // build

        string getCRN();
        string getName();
        string getDepartment();
        string getNumber();
};
#endif