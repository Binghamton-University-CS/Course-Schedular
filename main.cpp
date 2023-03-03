#include <iostream>
#include <stdlib.h>
#include <vector>
#include <regex>

#include "CourseList.h"
#include "StudentList.h"
#include "Student.h"
#include "Course.h"
#include "Registration.h"
#include "RegistrationList.h"

using namespace std;

StudentList persons_in_class = StudentList();
CourseList courses_list = CourseList();
RegistrationList regList = RegistrationList();

void showPrompt() {
   std::cout << "Enter [\"build <crn> <department> <number> <name>\"" << std::endl <<
                "       \"cancel <crn>\"" << std::endl <<
                "       \"enroll <bnumber> <userid> <first> <last>\"" << std::endl <<
                "       \"add <bnumber> <crn>\"" << std::endl <<
                "       \"drop <bnumber> <crn>\"" << std::endl <<
                "       \"roster <crn>\"" << std::endl <<
                "       \"schedule <bnumber>\"" << std::endl <<
                "       \"quit\"]" << endl <<
                ": ";
}

int main(){
    while(true) {
        showPrompt();
        string command;
        getline(cin, command);

        vector<string> copiedCommand;
        size_t space;

        while((space = (command.find(" "))) != string::npos) {
            string more = command.substr(0, space);
            if(more.size() != 0) {
                copiedCommand.push_back(more);
            }
            command.erase(0, space + 1);
        }
        copiedCommand.push_back(command);

        if(copiedCommand.at(0) == "build") { // BUILD
            if(copiedCommand.size() > 5) {
                cout << "Warning: ignoring extra argument(s)" << endl;
            }
            smatch match;
            if(copiedCommand.size() < 5) {
                cout << "Input Error: too few arguments" << endl;
            }
            else if(regex_match(copiedCommand.at(1), match, regex("^[0-9]{6}"))) {      
                if(regex_match(copiedCommand.at(2), match, regex("^[A-Z]{2,4}"))) { 
                    if(regex_match(copiedCommand.at(3), match, regex("^[1-6][0-9][0-9][A-Z]?|[7][0][0]?[A-Z]?"))) { 
                        unsigned int i;
                        string name = "";

                        for(i = 4; i < copiedCommand.size(); i++) {
                            name += copiedCommand.at(i);
                            if(i != copiedCommand.size() - 1) {
                                name += " ";
                            }
                        }
                        Course course(copiedCommand.at(1), copiedCommand.at(2), copiedCommand.at(3), name);
                        if(courses_list.searchByCRN(copiedCommand.at(1))) {
                            courses_list.addCourse(course);
                        }
                        else {
                            cout << "Fail: cannot build course" << course.getDepartment() << course.getNumber() << "(CRN: " << course.getCRN() << "): CRN exists" << endl;
                        }
                    }
                    else {
                        cout << "Input Error: illegal course number" << endl;
                    }
                }
                else {
                    cout << "Input Error: illegal department" << endl;
                }
            }
            else {
                cout << "Input Error: illegal CRN" << endl;
            }
        }
        else if(copiedCommand.front() == "cancel") { // CANCEL
            if(copiedCommand.size() > 2) {
                cout << "Warning: ignoring extra argument(s)" << endl;
            }
            smatch match;
            if(copiedCommand.size() < 2) {
                cout << "Input Error: too few arguments" << endl;
            }
            else if(regex_match(copiedCommand.at(1), match, regex("^[0-9]{6}"))) {
                unsigned int i;
                string name = "";

                for(i = 4; i < copiedCommand.size(); i++) {
                    name += copiedCommand.at(i);
                    if(i != copiedCommand.size() - 1) {
                        name += " ";
                    }
                }
                if(courses_list.checkByCRN(copiedCommand.at(1))) {
                    courses_list.removeCourse(copiedCommand.at(1));
                    regList.cancelReg(copiedCommand.at(1));
                }
                else {
                    cout << "Fail: cannot cancel course, CRN doesn't exist" << endl;
                }
            }
            else {
                cout << "Input Error: invalid CRN" << endl;
            }
        }
        else if(copiedCommand.front() == "enroll") { // ENROLL
            if(copiedCommand.size() > 5) {
                cout << "Warning: ignoring extra argument(s)" << endl;
            }
            smatch match;
            if(copiedCommand.size() < 5) {
                cout << "Input Error: too few arguments" << endl;
            }
            else if(regex_match(copiedCommand.at(1), match, regex("^[B][0-9]{8}"))) {
                if(regex_match(copiedCommand.at(2), match, regex("^[a-z]+[a-z0-9]+[0-9]*"))) {
                    unsigned int i;
                    string name = "";

                    for(i = 4; i < copiedCommand.size(); i++) {
                        name += copiedCommand.at(i);
                        if(i != copiedCommand.size() - 1) {
                            name += " ";
                        }
                    }
                    Student student(copiedCommand.at(1), copiedCommand.at(2), copiedCommand.at(3), copiedCommand.at(4));
                    if(persons_in_class.searchByBnum(copiedCommand.at(1))) {
                        persons_in_class.addStudent(student);
                    }
                    else {
                        cout << "Fail: cannot enroll student, B Number exists" << endl;
                    }
                    
                }
                else {
                    cout << "Input Error: invalid User ID" << endl;
                }
            }
            else {
                cout << "Input Error: invalid B-number" << endl;
            }
        }
        else if(copiedCommand.front() == "add") { // ADD
            if(copiedCommand.size() > 3) {
                cout << "Warning: ignoring extra argument(s)" << endl;
            }
            smatch match;
            if(copiedCommand.size() < 3) {
                cout << "Input Error: too few arguments" << endl;
            }
            else if(regex_match(copiedCommand.at(1), match, regex("^[B][0-9]{8}"))) {
                if(regex_match(copiedCommand.at(2), match, regex("^[0-9]{6}"))){
                    unsigned int i;
                    string name = "";

                    for(i = 4; i < copiedCommand.size(); i++) {
                        name += copiedCommand.at(i);
                        if(i != copiedCommand.size() - 1) {
                            name += " ";
                        }
                    }
                    Registration reg(copiedCommand.at(1), copiedCommand.at(2));
                    if(courses_list.checkByCRN(copiedCommand.at(2)) && !persons_in_class.searchByBnum(copiedCommand.at(1))) {
                        if(regList.checkRegExists(reg)) {
                            regList.addReg(reg);
                        }
                        else {
                            cout << "Fail: cannot add, student " << copiedCommand.at(1) << " already enrolled in course " << copiedCommand.at(2) << endl;
                        }
                    }
                    else {
                        cout << "Fail: student or CRN doesn't exist" << endl;
                    }
                }
                else {
                    cout << "Input Error: invalid CRN" << endl;
                }
            }
            else {
                cout << "Input Error: invalid B-number" << endl;
            }
        }
        else if(copiedCommand.front() == "drop") { // DROP
            if(copiedCommand.size() > 3) {
                cout << "Warning: ignoring extra argument(s)" << endl;
            }
            smatch match;
            if(copiedCommand.size() < 3) {
                cout << "Input Error: too few arguments" << endl;
            }
            else if(regex_match(copiedCommand.at(1), match, regex("^[B][0-9]{8}"))) {
                if(regex_match(copiedCommand.at(2), match, regex("^[0-9]{6}"))) {
                    unsigned int i;
                    string name = "";

                    for(i = 4; i < copiedCommand.size(); i++) {
                        name += copiedCommand.at(i);
                        if(i != copiedCommand.size() - 1) {
                            name += " ";
                        }
                    }
                   Registration reg(copiedCommand.at(1), copiedCommand.at(2));
                    if(courses_list.checkByCRN(copiedCommand.at(2)) && !persons_in_class.searchByBnum(copiedCommand.at(1))) {
                        if(!regList.checkRegExists(reg)) {
                            regList.dropReg(reg);
                        }
                        else {
                            cout << "Fail: cannot drop, student " << copiedCommand.at(1) << " not enrolled in course " << copiedCommand.at(2) << endl;
                        }
                    }
                    else {
                        cout << "Fail: student or CRN doesn't exist" << endl;
                    }
                }
                else {
                    cout << "Input Error: invalid CRN" << endl;
                }
            }
            else {
                cout << "Input Error: invalid B-number" << endl;
            }
        }
        else if(copiedCommand.front() == "roster") { // ROSTER
            if(copiedCommand.size() > 2) {
                cout << "Warning: ignoring extra argument(s)" << endl;
            }
            smatch match;
            if(copiedCommand.size() < 2) {
                cout << "Input Error: too few arguments" << endl;
            }
            else if(regex_match(copiedCommand.at(1), match, regex("^[0-9]{6}"))) {
                unsigned int i;
                string name = "";

                for(i = 4; i < copiedCommand.size(); i++) {
                    name += copiedCommand.at(i);
                    if(i != copiedCommand.size() - 1) {
                        name += " ";
                    }
                }

                cout << "CRN: " << copiedCommand.at(1) << endl;
                vector<string> bNumbers = regList.returnBnum(copiedCommand.at(1));
                cout << "Students: " << bNumbers.size() << endl;
                persons_in_class.searchByBnumPrintName(bNumbers);
            }
            else {
                cout << "Input Error: invalid CRN" << endl;
            }
        }
        else if(copiedCommand.front() == "schedule") { // SCHEDULE
            if(copiedCommand.size() > 2) {
                cout << "Warning: ignoring extra argument(s)" << endl;
            }
            smatch match;
            if(copiedCommand.size() < 2) {
                cout << "Input Error: too few arguments" << endl;
            }
            else if(regex_match(copiedCommand.at(1), match, regex("^B[0-9]{8}"))) {
                unsigned int i;
                string name = "";

                for(i = 4; i < copiedCommand.size(); i++) {
                    name += copiedCommand.at(i);
                    if(i != copiedCommand.size() - 1) {
                        name += " ";
                    }
                }

                cout << "Student: " << copiedCommand.at(1) << ": ";
                persons_in_class.printName(copiedCommand.at(1));
                vector<string> crns = regList.returnCrn(copiedCommand.at(1));
                courses_list.searchByCRNPrintInfo(crns);
                
            }
            else {
                cout << "Input Error: invalid B-number" << endl;
            }
        }
        else if(copiedCommand.front() == "quit") {
            exit(0);
        }
        else {
            cout << "Command not recognized, please try again." << endl;
        }
    }
};