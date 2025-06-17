#include "Flight.h"
#include <iostream>
using namespace std;

Flight::Flight() : availableSeats(0), numPassengers(0) {}

bool Flight::addPassenger(string passengerName, string seatNo) {
    if (numPassengers < MAX_PASSENGERS && availableSeats > 0) {
        for (int i = 0; i < numPassengers; i++) {
            if (passengers[i].seatNumber == seatNo) {
                cout << "Error: Seat number " << seatNo << " is already booked.\n";
                return false;
            }
        }
        passengers[numPassengers] = Passenger(passengerName, seatNo);
        numPassengers++;
        availableSeats--;
        return true;
    }
    return false;
}

void Flight::displayBookedSeats() {
    cout << "Booked seats for Flight " << flightNumber << ":\n";
    for (int i = 0; i < numPassengers; i++) {
        passengers[i].display();
    }
}
