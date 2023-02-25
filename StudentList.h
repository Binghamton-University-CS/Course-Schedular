#include <string.h>
#include <stdlib.h>

using namespace std;

class StudentList{
    private:
        string firstName;
        string lastName;
        string userID;
        string bNumber;

        // array values
        int capacity;
        int currentQuantity;

        StudentList* regStudents; //array
    
    public:
        //? implement 4 constructors (default, copy, assignment)
        StudentList();
        StudentList(string firstName, string secondName, string userID, string bNumber);
        StudentList(const StudentList& student);
        // also need copy constructor
        // also need assignment constructor

        // destructor
        ~StudentList();

        // core functionality methods
        void showRegStudents(); // loop over registered students and print out (what command roster does)

        //array methods
        void insertStudent(StudentList toAdd);
        void resizeArray();


        // getters: returns value

        string getFirstName();
        string getSecondName();
        string getUserID();
        string getBNumber();

        // setters

        void setFirstName(string newFirstName);
        void setSecondName(string newSecondName);
        void setUserID(string newUserID);
        void setBNumber(string newBNumber);

};