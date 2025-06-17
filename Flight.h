#ifndef FLIGHT_H
#define FLIGHT_H

#include "Passenger.h"

const int MAX_PASSENGERS = 50;

class Flight {
public:
    string flightNumber;
    string destination;
    int availableSeats;

    Passenger passengers[MAX_PASSENGERS];
    int numPassengers;

    Flight();

    bool addPassenger(string passengerName, string seatNo);
    void displayBookedSeats();
};

#endif
