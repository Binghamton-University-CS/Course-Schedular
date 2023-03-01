#include <iostream>
#include <stdlib.h>

using namespace std;

#ifndef COURSELIST_H
#define COURSELIST_H

#include "Course.h"

class CourseList {
    public:
        CourseList();
        CourseList(string newCRN, string newDepartment, string newNumber, string newName);
        ~CourseList();
        void searchByCRN(string newCrn);
        void addCourse(Course addCourse);
        void removeCourse(Course removeCourse);
        void resizeArray();
        // void insertCourse(Student* addCourse);

        void printListOfStudents(Course allCourses);
        bool checkCourseExists(Course newCourse);

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

    private:
        // array values
        int capacity;
        int currentQuantity;
        string crn;
        string name;
        string department;
        string number;

        Course* allCourses; // list of all students in a course
};
#endif