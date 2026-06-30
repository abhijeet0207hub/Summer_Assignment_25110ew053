#include <iostream>
#include <string>
using namespace std;

int main() {
    int rollNumbers[100];
    string names[100];
    float marks[100];
    int count = 0, choice;

    do {
        cout << "\n--- Student Record System ---\n";
        cout << "1. Add Student\n2. Display All\n3. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Roll No: "; cin >> rollNumbers[count];
            cout << "Name: "; cin.ignore(); getline(cin, names[count]);
            cout << "Marks: "; cin >> marks[count];
            count++;
        } else if (choice == 2) {
            for (int i = 0; i < count; i++) {
                cout << "Roll: " << rollNumbers[i] << " | Name: " << names[i] << " | Marks: " << marks[i] << endl;
            }
        }
    } while (choice != 3);

    return 0;
}