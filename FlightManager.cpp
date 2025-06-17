#include "FlightManager.h"
#include <iostream>
#include <fstream>
using namespace std;

FlightManager::FlightManager() : numFlights(0) {}

bool FlightManager::isFlightNumberUnique(const string& flightNo) {
    for (int i = 0; i < numFlights; i++) {
        if (flights[i].flightNumber == flightNo)
            return false;
    }
    return true;
}

void FlightManager::saveFlightsToFile() {
    ofstream file("flights.txt");
    if (file.is_open()) {
        file << numFlights << endl;
        for (int i = 0; i < numFlights; ++i) {
            file << flights[i].flightNumber << " "
                 << flights[i].destination << " "
                 << flights[i].availableSeats << endl;
        }
        file.close();
    }
}

void FlightManager::loadFlightsFromFile() {
    ifstream file("flights.txt");
    if (file.is_open()) {
        file >> numFlights;
        for (int i = 0; i < numFlights; ++i) {
            file >> flights[i].flightNumber >> flights[i].destination >> flights[i].availableSeats;
            flights[i].numPassengers = 0;
        }
        file.close();
    }
}

void FlightManager::savePassengersToFile() {
    ofstream file("passengers.txt");
    if (file.is_open()) {
        for (int i = 0; i < numFlights; ++i) {
            file << flights[i].numPassengers << endl;
            for (int j = 0; j < flights[i].numPassengers; ++j) {
                file << flights[i].passengers[j].name << " "
                     << flights[i].passengers[j].seatNumber << endl;
            }
        }
        file.close();
    }
}

void FlightManager::loadPassengersFromFile() {
    ifstream file("passengers.txt");
    if (file.is_open()) {
        for (int i = 0; i < numFlights; ++i) {
            file >> flights[i].numPassengers;
            for (int j = 0; j < flights[i].numPassengers; ++j) {
                file >> flights[i].passengers[j].name >> flights[i].passengers[j].seatNumber;
            }
        }
        file.close();
    }
}

void FlightManager::addFlight() {
    if (numFlights < MAX_FLIGHTS) {
        string flightNo;
        cout << "Enter flight number: ";
        cin >> flightNo;

        if (!isFlightNumberUnique(flightNo)) {
            cout << "Flight number already exists! Please enter a unique flight number.\n";
            return;
        }

        flights[numFlights].flightNumber = flightNo;

        cout << "Enter destination: ";
        cin >> flights[numFlights].destination;

        cout << "Enter available seats: ";
        cin >> flights[numFlights].availableSeats;

        flights[numFlights].numPassengers = 0;
        numFlights++;
        saveFlightsToFile();
        cout << "Flight added and saved.\n";
    } else {
        cout << "Max flights reached.\n";
    }
}

void FlightManager::displayFlights() {
    cout << "Flight details:\n";
    for (int i = 0; i < numFlights; ++i) {
        cout << flights[i].flightNumber << " | "
             << flights[i].destination << " | "
             << "Seats Available: " << flights[i].availableSeats << endl;
    }
}

void FlightManager::findFlightByNumber(string flightNo) {
    bool found = false;
    for (int i = 0; i < numFlights; ++i) {
        if (flights[i].flightNumber == flightNo) {
            cout << flights[i].flightNumber << " | "
                 << flights[i].destination << " | "
                 << "Seats Available: " << flights[i].availableSeats << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Flight not found.\n";
}

void FlightManager::bookSeat(string flightNo) {
    for (int i = 0; i < numFlights; ++i) {
        if (flights[i].flightNumber == flightNo) {
            if (flights[i].availableSeats > 0) {
                string name, seatNo;
                cout << "Enter passenger name: ";
                cin >> name;
                cout << "Enter seat number: ";
                cin >> seatNo;
                if (flights[i].addPassenger(name, seatNo)) {
                    savePassengersToFile();
                    saveFlightsToFile();
                    cout << "Seat booked and saved.\n";
                } else {
                    cout << "Cannot book seat.\n";
                }
            } else {
                cout << "No seats available.\n";
            }
            return;
        }
    }
    cout << "Flight not found.\n";
}

void FlightManager::displayBookedSeats(string flightNo) {
    for (int i = 0; i < numFlights; ++i) {
        if (flights[i].flightNumber == flightNo) {
            flights[i].displayBookedSeats();
            return;
        }
    }
    cout << "Flight not found.\n";
}
