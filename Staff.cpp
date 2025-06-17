#include "Staff.h"

Staff::Staff() {}

Staff::Staff(string n, string r) : Person(n), role(r) {}

void Staff::display() {
    cout << name << " | " << role << endl;
}
