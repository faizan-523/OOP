#ifndef FLIGHTMANAGER_H
#define FLIGHTMANAGER_H

#include "Flight.h"
#include <string>

const int MAX_FLIGHTS = 100;

class FlightManager {
private:
    Flight flights[MAX_FLIGHTS];
    int numFlights;

public:
    FlightManager();

    bool isFlightNumberUnique(const string& flightNo);

    void saveFlightsToFile();
    void loadFlightsFromFile();

    void savePassengersToFile();
    void loadPassengersFromFile();

    void addFlight();
    void displayFlights();
    void findFlightByNumber(string flightNo);
    void bookSeat(string flightNo);
    void displayBookedSeats(string flightNo);
};

#endif
