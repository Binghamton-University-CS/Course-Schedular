#include <iostream>
#include <stdlib.h>
#include <vector>
#include <regex>

#include "CourseList.h"
#include "StudentList.h"
#include "Student.h"
#include "Course.h"

using namespace std;

StudentList persons_in_class = StudentList();
CourseList courses_list = CourseList();

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
            // copiedCommand.push_back(command.substr(0, space));
            string more = command.substr(0, space);
            if(more.size() != 0) {
                copiedCommand.push_back(more);
            }
            command.erase(0, space + 1);
        }
        copiedCommand.push_back(command);

        if(copiedCommand.at(0) == "build") {                                          // BUILD
            smatch match;
            if(copiedCommand.size() < 5) {
                cout << "Input Error: too few arguments" << endl;
                exit(0);
            }
            if(regex_match(copiedCommand.at(1), match, regex("^[0-9]{6}"))) {      //  && regex_match(copiedCommand.at(4), match, regex("^((?![0-9])[\S])+"))
                if(regex_match(copiedCommand.at(2), match, regex("^[A-Z]{2,4}"))) { // DEPARTMENT
                    if(regex_match(copiedCommand.at(3), match, regex("^[1-6][0-9][0-9]"))) { // [1-6][0-9][0-9][A-Z]? NUMBER
                        unsigned int i;
                        string name = "";

                        for(i = 4; i < copiedCommand.size(); i++) {
                            name += copiedCommand.at(i);
                            if(i != copiedCommand.size() - 1) {
                                name += " ";
                            }
                        }
                        cout << "Success: built course " << copiedCommand.at(2) << copiedCommand.at(3) << " (CRN: " << copiedCommand.at(1) << "): " << name << endl;
                    }
                    else {
                        cout << "Input Error: illegal Course Number" << endl;
                    }
                }
                else {
                    cout << "Input Error: illegal Department" << endl;
                }
            }
            else {
                cout << "Input Error: illegal CRN" << endl;
            }
        }
        else if(copiedCommand.front() == "cancel") {                                // CANCEL
            smatch match;
            if(copiedCommand.size() < 2) {
                cout << "Input Error: too few arguments" << endl;
                exit(0);
            }
            if(regex_match(copiedCommand.at(1), match, regex("^[0-9]{6}"))) {
                cout << "Success: cancelled course " << copiedCommand.at(1) << endl;
                cout << endl;
            }
            else {
                cout << "Input Error: invalid CRN" << endl;
                cout << endl;
            }
        }
        else if(copiedCommand.front() == "enroll") { // ENROLL
            smatch match;
            if(copiedCommand.size() < 5) {
                cout << "Input Error: too few arguments" << endl;
                exit(0);
            }
            if(regex_match(copiedCommand.at(1), match, regex("^[B][0-9]{8}"))) {
                if(regex_match(copiedCommand.at(2), match, regex("^[a-z]+[a-z0-9]+[0-9]*"))) {
                    cout << "Works here" << endl;
                    Student student(copiedCommand.at(1), copiedCommand.at(2), copiedCommand.at(3), copiedCommand.at(4));
                    cout << "here" << endl;
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
                // delete student;
            }
            else {
                cout << "Input Error: invalid B-number" << endl;
            }
        }
        else if(copiedCommand.front() == "add") {                                      // ADD
            smatch match;
            if(copiedCommand.size() < 3) {
                cout << "Input Error: too few arguments" << endl;
                exit(0);
            }
            if(regex_match(copiedCommand.at(1), match, regex("^[B][0-9]{8}"))) {
                if(regex_match(copiedCommand.at(2), match, regex("^[0-9]{6}"))){
                    cout << "Success: added student " << copiedCommand.at(1) << " into course " << copiedCommand.at(2) << endl;
                    cout << endl;
                }
                else {
                    cout << "Input Error: invalid CRN" << endl;
                }
            }
            else {
                cout << "Input Error: invalid B-number" << endl;
            }
        }
        else if(copiedCommand.front() == "drop") {                                      // DROP
            smatch match;
            if(copiedCommand.size() < 3) {
                cout << "Input Error: too few arguments" << endl;
                exit(0);
            }
            if(regex_match(copiedCommand.at(1), match, regex("^[B][0-9]{8}"))) {
                if(regex_match(copiedCommand.at(2), match, regex("^[0-9]{6}"))) {
                    cout << "Success: removed student " << copiedCommand.at(1) << " from course " << copiedCommand.at(2) << endl;
                    cout << endl;
                }
                else {
                    cout << "Input Error: invalid CRN" << endl;
                }
            }
            else {
                cout << "Input Error: invalid B-number" << endl;
            }
        }
        else if(copiedCommand.front() == "roster") {                                    // ROSTER
            smatch match;
            if(copiedCommand.size() < 2) {
                cout << "Input Error: too few arguments" << endl;
                exit(0);
            }
            if(regex_match(copiedCommand.at(1), match, regex("^[0-9]{6}"))) {
                cout << "Roster: " << copiedCommand.at(1) << endl;
            }
            else {
                cout << "Input Error: invalid CRN" << endl;
            }
        }
        else if(copiedCommand.front() == "schedule") {                                  // SCHEDULE
            smatch match;
            if(copiedCommand.size() < 2) {
                cout << "Input Error: too few arguments" << endl;
                exit(0);
            }
            else if(regex_match(copiedCommand.at(1), match, regex("^B[0-9]{8}"))) {
                cout << "Student: " << copiedCommand.at(1) << endl;
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