#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct SalaryRecord {
    int empId;
    string name;
    double basicSalary;
    double allowances;
    double deductions;
    double netSalary;
};

int main() {
    vector<SalaryRecord> salaries;
    int choice = 0;

    while (choice != 3) {
        cout << "=== Salary Management System ===\n";
        cout << "1. Process New Salary\n";
        cout << "2. View Salary Slips\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            SalaryRecord sr;
            cout << "Enter Employee ID: ";
            cin >> sr.empId;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, sr.name);
            
            cout << "Enter Basic Salary: ";
            cin >> sr.basicSalary;
            cout << "Enter Total Allowances (Bonus, HRA, etc.): ";
            cin >> sr.allowances;
            cout << "Enter Total Deductions (Tax, PF, etc.): ";
            cin >> sr.deductions;
            
            
            sr.netSalary = sr.basicSalary + sr.allowances - sr.deductions;
            
            salaries.push_back(sr);
            cout << "--> Salary processed and recorded successfully!\n";
        } 
        else if (choice == 2) {
            if (salaries.empty()) {
                cout << "--> No salary records found.\n";
            } else {
                cout << "\n--- Salary Slips ---\n";
                for (size_t i = 0; i < salaries.size(); ++i) {
                    cout << "ID: " << salaries[i].empId 
                         << " | Name: " << salaries[i].name 
                         << " | Basic: $" << salaries[i].basicSalary 
                         << " | Net Salary: $" << salaries[i].netSalary << "\n";
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