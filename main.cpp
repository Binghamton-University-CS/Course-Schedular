#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <cctype>
#include <regex>
#include "CourseList.h"
using namespace std;

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
            copiedCommand.push_back(command.substr(0, space));
            command.erase(0, space + 1);
        }
        copiedCommand.push_back(command);

        if(copiedCommand.at(0) == "build") {
            smatch match;
            if(copiedCommand.size() < 5) {
                cout << "Input Error: too few arguments" << endl;
            }
            else if(regex_match(copiedCommand.at(1), match, regex("^[0-9]{6}")) && regex_match(copiedCommand.at(2), match, regex("^[A-Z]{2,4}")) && regex_match(copiedCommand.at(3), match, regex("^[1-4][0-9][0-9][A-Z]?"))) {      //  && regex_match(copiedCommand.at(4), match, regex("^((?![0-9])[\S])+"))
                cout << "Success: built course " << copiedCommand.at(2) << copiedCommand.at(3) << " (CRN: " << copiedCommand.at(1) << "): " << copiedCommand.at(4) << endl;
                cout << endl;
            }
            else if(copiedCommand.at(1).size() > 6 || copiedCommand.at(1).size() < 6) {
                cout << "Input Error: " << copiedCommand.at(1) << " is not a valid CRN" << endl;
                cout << endl;
            }
            // else if(islower(copiedCommand.at(2))) {
            //     cout << "Input Error: " << copiedCommand.at(2) << " is not a valid department" << endl;
            //     cout << endl;
            // }
            else if(copiedCommand.at(3).size() > 4 || copiedCommand.at(3).size() < 1) {
                cout << "Input Error: " << copiedCommand.at(3) << " is not a valid course number" << endl;
                cout << endl;
            }
            else {
                cout << "Invalid" << endl;
            }
        }
        else if(copiedCommand.front() == "cancel") {
            smatch match;
            if(copiedCommand.size() < 2) {
                cout << "Input Error: too few arguments" << endl;
            }
            else if(regex_match(copiedCommand.at(1), match, regex("^[0-9]{6}"))) {
                cout << "Success: cancelled course " << copiedCommand.at(1) << endl;
                cout << endl;
            }
            else if(copiedCommand.at(1).size() < 6 || copiedCommand.at(1).size() > 6) {
                cout << "Input Error: " << copiedCommand.at(1) << " is not a valid CRN" << endl;
                cout << endl;
            }
            else {
                cout << "Invalid" << endl;
                cout << endl;
            }
        }
        else if(copiedCommand.front() == "enroll") {
            smatch match;
            if(copiedCommand.size() < 5) {
                cout << "Input Error: too few arguments" << endl;
            }
            else if(regex_match(copiedCommand.at(1), match, regex("^B[0-9]{9}")) && regex_match(copiedCommand.at(2), match, regex("^[a-z]{2,4}"))) {
                cout << "Success: enrolled student " << copiedCommand.at(1) << " (" << copiedCommand.at(2) << ") " << copiedCommand.at(4) << ", " << copiedCommand.at(3) << endl;
                cout << endl;
            }
            else if(copiedCommand.at(1).size() > 9 || copiedCommand.at(1).size() < 9) {
                cout << "Input Error: " << copiedCommand.at(1) << " is not a valid B numbers" << endl;
                cout << endl;
            }
            else if(copiedCommand.at(2).size() > 6 || copiedCommand.at(1).size() < 6) {
                cout << "Input Error: " << copiedCommand.at(1) << " is not a valid CRN" << endl;
                cout << endl;
            }
            else {
                cout << "Invalid" << endl;
            }
        }
        else if(copiedCommand.front() == "add") {
            smatch match;
            if(copiedCommand.size() < 3) {
                cout << "Input Error: too few arguments" << endl;
            }
            else if(regex_match(copiedCommand.at(1), match, regex("^B[0-9]{8}")) && regex_match(copiedCommand.at(2), match, regex("^[0-9]{6}"))) {
                cout << "Success: added student " << copiedCommand.at(1) << " into course " << copiedCommand.at(2) << endl;
                cout << endl;
            }
            else {
                cout << "Invalid" << endl;
            }
        }
        else if(copiedCommand.front() == "drop") {
            smatch match;
            if(copiedCommand.size() < 3) {
                cout << "Input Error: too few arguments" << endl;
            }
            else if(regex_match(copiedCommand.at(1), match, regex("^B[0-9]{8}")) && regex_match(copiedCommand.at(2), match, regex("^[0-9]{6}"))) {
                cout << "Success: removed student " << copiedCommand.at(1) << " from course " << copiedCommand.at(2) << endl;
                cout << endl;
            }
            else {
                cout << "Invalid" << endl;
            }
        }
        else if(copiedCommand.front() == "roster") {
            smatch match;
            if(copiedCommand.size() < 2) {
                cout << "Input Error: too few arguments" << endl;
            }
            else if(regex_match(copiedCommand.at(1), match, regex("^[0-9]{6}"))) {
                cout << "Success: " << endl;
            }
            else {
                cout << "Invalid" << endl;
            }
        }
        else if(copiedCommand.front() == "schedule") {
            smatch match;
            if(copiedCommand.size() < 2) {
                cout << "Input Error: too few arguments" << endl;
            }
            else if(regex_match(copiedCommand.at(1), match, regex("^B[0-9]{8}"))) {
                cout << "Valid" << endl;
            }
            else {
                cout << "Invalid Command" << endl;
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