#include <iostream>
using namespace std;

int main() {
    int balance = 1000; 
    int choice;
    int amount;
    
    while (true) {
        cout << "\n--- ATM Menu ---" << endl;
        cout << "1. Check Balance\n2. Deposit\n3. Withdraw\n4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        if (choice == 1) {
            cout << "Current Balance: $" << balance << endl;
        } else if (choice == 2) {
            cout << "Enter amount to deposit: $";
            cin >> amount;
            if (amount > 0) {
                balance += amount;
                cout << "Deposit successful." << endl;
            } else {
                cout << "Invalid amount." << endl;
            }
        } else if (choice == 3) {
            cout << "Enter amount to withdraw: $";
            cin >> amount;
            if (amount <= balance && amount > 0) {
                balance -= amount;
                cout << "Withdrawal successful." << endl;
            } else {
                cout << "Insufficient funds or invalid amount." << endl;
            }
        } else if (choice == 4) {
            cout << "Thank you for using the ATM. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}