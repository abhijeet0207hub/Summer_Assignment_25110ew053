#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
};

int main() {
    vector<Contact> contacts;
    int choice;

    do {
        cout << "\n--- Contact Management System ---\n";
        cout << "1. Add Contact\n2. Display All Contacts\n3. Search Contact\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Contact newContact;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, newContact.name);
                cout << "Enter Phone Number: ";
                getline(cin, newContact.phone);
                cout << "Enter Email: ";
                getline(cin, newContact.email);

                contacts.push_back(newContact);
                cout << "Contact added successfully!\n";
                break;
            }
            case 2: {
                if (contacts.empty()) {
                    cout << "Contact list is empty.\n";
                } else {
                    cout << "\n--- Contact List ---\n";
                    for (int i = 0; i < contacts.size(); i++) {
                        cout << "Name: " << contacts[i].name << "\nPhone: " << contacts[i].phone << "\nEmail: " << contacts[i].email << "\n-------------------\n";
                    }
                }
                break;
            }
            case 3: {
                string searchName;
                bool found = false;
                cout << "Enter name to search: ";
                cin.ignore();
                getline(cin, searchName);

                for (int i = 0; i < contacts.size(); i++) {
                    if (contacts[i].name == searchName) {
                        cout << "\nContact Found!\n";
                        cout << "Name: " << contacts[i].name << "\nPhone: " << contacts[i].phone << "\nEmail: " << contacts[i].email << "\n";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Contact not found.\n";
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