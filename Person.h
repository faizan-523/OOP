#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;

    Person();
    Person(string n);

    virtual void display();
    virtual ~Person() = default;
};

#endif
