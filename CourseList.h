#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

#ifndef COURSELIST_H
#define COURSELIST_H

#include "Course.h"

class CourseList {
    private:
        int capacity;
        int currentQuantity;
        string crn;
        string name;
        string department;
        string number;

        Course* allCourses; 

    public:
        CourseList();
        CourseList(string newCRN, string newDepartment, string newNumber, string newName);
        ~CourseList();

        bool searchByCRN(string newCrn);
        void searchByCRNPrintInfo(vector<string> crn);
        void addCourse(Course addCourse);
        void removeCourse(string removeCourse);
        void resizeArray();
        void printBuild();
        bool checkByCRN(string newCRN);

        string getCRN();
        string getName();
        string getDepartment();
        string getNumber();
};
#endif