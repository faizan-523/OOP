#ifndef STAFFMANAGER_H
#define STAFFMANAGER_H

#include "Staff.h"

const int MAX_STAFF = 20;

class StaffManager {
private:
    Staff staff[MAX_STAFF];
    int numStaff;

public:
    StaffManager();

    void saveStaffToFile();
    void loadStaffFromFile();

    void addStaff();
    void showStaff();
    void manageStaffMenu();
};

#endif
