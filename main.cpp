#include <iostream>
#include "FlightManager.h"
#include "StaffManager.h"
using namespace std;

int main() {
    FlightManager flightManager;
    StaffManager staffManager;

    flightManager.loadFlightsFromFile();
    flightManager.loadPassengersFromFile();
    staffManager.loadStaffFromFile();

    char choice;
    do {
        cout << "Menu:\n";
        cout << "1. Add Flight\n";
        cout << "2. Display Flights\n";
        cout << "3. Find Flight by Number\n";
        cout << "4. Book Seat\n";
        cout << "5. Show Booked Seats\n";
        cout << "6. Manage Staff\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                flightManager.addFlight();
                break;
            case '2':
                flightManager.displayFlights();
                break;
            case '3': {
                string fno;
                cout << "Enter flight number: ";
                cin >> fno;
                flightManager.findFlightByNumber(fno);
                break;
            }
            case '4': {
                string fno;
                cout << "Enter flight number to book seat: ";
                cin >> fno;
                flightManager.bookSeat(fno);
                break;
            }
            case '5': {
                string fno;
                cout << "Enter flight number to display booked seats: ";
                cin >> fno;
                flightManager.displayBookedSeats(fno);
                break;
            }
            case '6':
                staffManager.manageStaffMenu();
                break;
            case '7':
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != '7');

    return 0;
}
