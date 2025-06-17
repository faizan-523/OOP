#include "StaffManager.h"
#include <iostream>
#include <fstream>
using namespace std;

StaffManager::StaffManager() : numStaff(0) {}

void StaffManager::saveStaffToFile() {
    ofstream file("staff.txt");
    if (file.is_open()) {
        file << numStaff << endl;
        for (int i = 0; i < numStaff; ++i) {
            file << staff[i].name << " " << staff[i].role << endl;
        }
        file.close();
    }
}

void StaffManager::loadStaffFromFile() {
    ifstream file("staff.txt");
    if (file.is_open()) {
        file >> numStaff;
        for (int i = 0; i < numStaff; ++i) {
            file >> staff[i].name >> staff[i].role;
        }
        file.close();
    }
}

void StaffManager::addStaff() {
    if (numStaff < MAX_STAFF) {
        cout << "Enter staff name: ";
        cin >> staff[numStaff].name;
        cout << "Enter staff role: ";
        cin >> staff[numStaff].role;
        numStaff++;
        saveStaffToFile();
        cout << "Staff added and saved.\n";
    } else {
        cout << "Max staff reached.\n";
    }
}

void StaffManager::showStaff() {
    cout << "Staff List:\n";
    for (int i = 0; i < numStaff; ++i) {
        staff[i].display();
    }
}

void StaffManager::manageStaffMenu() {
    char choice;
    do {
        cout << "\nStaff Menu:\n1. Add Staff\n2. Show Staff\n3. Exit\nChoice: ";
        cin >> choice;
        if (choice == '1') {
            addStaff();
        } else if (choice == '2') {
            showStaff();
        }
    } while (choice != '3');
}
