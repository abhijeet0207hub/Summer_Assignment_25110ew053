#include <iostream>
#include <string>
using namespace std;

struct Item {
    int id;
    string name;
    int quantity;
};

int main() {
    Item inventory[50];
    int count = 0, choice;

    do {
        cout << "\n--- Inventory System ---\n";
        cout << "1. Add Item\n2. View Inventory\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            if (count < 50) {
                cout << "Enter Item ID: "; cin >> inventory[count].id;
                cout << "Enter Item Name: "; cin >> inventory[count].name;
                cout << "Enter Quantity: "; cin >> inventory[count].quantity;
                count++;
                cout << "Item added.\n";
            } else {
                cout << "Inventory full!\n";
            }
        } else if (choice == 2) {
            cout << "ID\tName\tQuantity\n";
            for (int i = 0; i < count; i++) {
                cout << inventory[i].id << "\t" << inventory[i].name << "\t" << inventory[i].quantity << "\n";
            }
        }
    } while (choice != 3);

    return 0;
}