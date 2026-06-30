#include <iostream>
#include <vector>

using namespace std;

int main() {
    int totalSeats = 10;
    vector<bool> seats(totalSeats, false); // false = available, true = booked
    int choice;

    do {
        cout << "\n--- Ticket Booking System ---\n";
        cout << "1. View Seats\n2. Book Ticket\n3. Cancel Ticket\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\n--- Seat Availability ---\n";
                for (int i = 0; i < totalSeats; i++) {
                    cout << "Seat " << i + 1 << ": ";
                    if (seats[i]) {
                        cout << "[Booked]\n";
                    } else {
                        cout << "[Available]\n";
                    }
                }
                break;
            }
            case 2: {
                int seatNum;
                cout << "Enter seat number to book (1-" << totalSeats << "): ";
                cin >> seatNum;

                if (seatNum < 1 || seatNum > totalSeats) {
                    cout << "Invalid seat number!\n";
                } else if (!seats[seatNum - 1]) {
                    seats[seatNum - 1] = true;
                    cout << "Seat " << seatNum << " successfully booked!\n";
                } else {
                    cout << "Sorry, seat " << seatNum << " is already booked.\n";
                }
                break;
            }
            case 3: {
                int seatNum;
                cout << "Enter seat number to cancel (1-" << totalSeats << "): ";
                cin >> seatNum;

                if (seatNum < 1 || seatNum > totalSeats) {
                    cout << "Invalid seat number!\n";
                } else if (seats[seatNum - 1]) {
                    seats[seatNum - 1] = false;
                    cout << "Booking for seat " << seatNum << " successfully canceled!\n";
                } else {
                    cout << "Seat " << seatNum << " is not booked yet.\n";
                }
                break;
            }
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}