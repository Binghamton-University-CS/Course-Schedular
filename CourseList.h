#include <string.h>
#include <stdlib.h>
#include "StudentList.h"

using namespace std;

class CourseList{
    private:
        string crn;
        string name;
        string department;
        string number;

        // array values
        int capacity;
        int currentQuantity;

        StudentList* regStudents; //array
    
    public:
        //? implement 4 constructors (default, copy, assignment)
        CourseList();
        CourseList(string crn, string name, string department, string number);
        CourseList(const StudentList& student);
        // also need copy constructor
        // also need assignment constructor

        // destructor
        ~CourseList();

        // core functionality methods
        void showRegStudents(); // loop over registered students and print out (what command roster does)

        //array methods
        void insertStudent(StudentList toAdd);
        void resizeArray();


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