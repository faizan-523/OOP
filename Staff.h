#ifndef STAFF_H
#define STAFF_H

#include "Person.h"

class Staff : public Person {
public:
    string role;

    Staff();
    Staff(string n, string r);

    void display() override;
};

#endif
