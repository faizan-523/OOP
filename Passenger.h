#ifndef PASSENGER_H
#define PASSENGER_H

#include "Person.h"

class Passenger : public Person {
public:
    string seatNumber;

    Passenger();
    Passenger(string n, string s);

    void display() override;
};

#endif
