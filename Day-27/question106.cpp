#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Employee {
    int empId;
    string name;
    string department;
};

int main() {
    vector<Employee> employees;
    int choice = 0;

    while (choice != 3) {
        cout << "\n=== Employee Management System ===\n";
        cout << "1. Add New Employee\n";
        cout << "2. View All Employees\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Employee emp;
            cout << "Enter Employee ID: ";
            cin >> emp.empId;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, emp.name);
            cout << "Enter Department: ";
            getline(cin, emp.department);
            
            employees.push_back(emp);
            cout << "--> Employee added successfully!\n";
        } 
        else if (choice == 2) {
            if (employees.empty()) {
                cout << "--> No employee records found.\n";
            } else {
                cout << "\n--- Employee List ---\n";
                for (size_t i = 0; i < employees.size(); ++i) {
                    cout << "ID: " << employees[i].empId 
                         << " | Name: " << employees[i].name 
                         << " | Dept: " << employees[i].department << "\n";
                }
            }
        } 
        else if (choice == 3) {
            cout << "Exiting system...\n";
        } 
        else {
            cout << "--> Invalid choice! Please try again.\n";
        }
    }

    return 0;
}