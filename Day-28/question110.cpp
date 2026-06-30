#include <iostream>
#include <string>

using namespace std;

int main() {
    string accountHolder = "";
    int accountNumber = 0;
    double balance = 0.0;
    bool accountCreated = false;
    int choice;

    do {
        cout << "\n--- Bank Account System ---\n";
        cout << "1. Create Account\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice > 1 && choice < 5 && !accountCreated) {
            cout << "Please create an account first!\n";
            continue;
        }

        switch (choice) {
            case 1: {
                cout << "Enter Account Holder Name: ";
                cin.ignore();
                getline(cin, accountHolder);
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                cout << "Initial Deposit: ₹";
                cin >> balance;
                accountCreated = true;
                cout << "Account created successfully!\n";
                break;
            }
            case 2: {
                double depositAmount;
                cout << "Enter amount to deposit: ₹";
                cin >> depositAmount;
                if (depositAmount > 0) {
                    balance += depositAmount;
                    cout << "Deposited successfully. Current Balance: ₹" << balance << "\n";
                } else {
                    cout << "Invalid amount!\n";
                }
                break;
            }
            case 3: {
                double withdrawAmount;
                cout << "Enter amount to withdraw: ₹";
                cin >> withdrawAmount;
                if (withdrawAmount > 0 && withdrawAmount <= balance) {
                    balance -= withdrawAmount;
                    cout << "Withdrawn successfully. Current Balance: ₹" << balance << "\n";
                } else {
                    cout << "Insufficient funds or invalid amount!\n";
                }
                break;
            }
            case 4: {
                cout << "Account Holder: " << accountHolder << "\n";
                cout << "Account Number: " << accountNumber << "\n";
                cout << "Available Balance: ₹" << balance << "\n";
                break;
            }
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}