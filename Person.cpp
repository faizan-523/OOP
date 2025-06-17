#include "Person.h"

Person::Person() {}

Person::Person(string n) : name(n) {}

void Person::display() {
    cout << "Name: " << name << endl;
}
