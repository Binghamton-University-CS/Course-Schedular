#include <iostream>
#include <stdlib.h>

using namespace std;

#ifndef COURSELIST_H
#define COURSELIST_H

#include "Course.h"

class CourseList {
    private:
        // array values
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

        // void whatever(int course);

        bool searchByCRN(string newCrn);
        string searchByCRNReturnInfo(string info);

        void addCourse(Course addCourse);
        // void addCourse();
        void removeCourse(Course removeCourse);
        void resizeArray();
        void printListOfStudents(Course allCourses);
        void print();

        bool checkByCRN(string newCRN);

        // getters: returns value

        string getCRN();
        string getName();
        string getDepartment();
        string getNumber();

        // setters

        void setCRN(string newCRN);
        void setName(string newName);
        void setDepartment(string newDepartment);
        void setNumber(string newNumber);
};
#endif