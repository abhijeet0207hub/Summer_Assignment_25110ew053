#include <iostream>
#include <string>
using namespace std;

struct Employee {
    int empId;
    string name;
    double salary;
};

int main() {
    Employee emps[50];
    int count = 0, choice;

    do {
        cout << "\n--- Employee System ---\n";
        cout << "1. Add Employee\n2. Display Employees\n3. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "ID: "; cin >> emps[count].empId;
            cout << "Name: "; cin.ignore(); getline(cin, emps[count].name);
            cout << "Salary: "; cin >> emps[count].salary;
            count++;
        } else if (choice == 2) {
            for (int i = 0; i < count; i++) {
                cout << "ID: " << emps[i].empId << " | Name: " << emps[i].name << " | Salary: " << emps[i].salary << endl;
            }
        }
    } while (choice != 3);

    return 0;
}