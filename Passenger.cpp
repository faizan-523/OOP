#include "Passenger.h"

Passenger::Passenger() {}

Passenger::Passenger(string n, string s) : Person(n), seatNumber(s) {}

void Passenger::display() {
    cout << "Passenger: " << name << " | Seat: " << seatNumber << endl;
}
