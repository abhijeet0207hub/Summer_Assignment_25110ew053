#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
};

int main() {
    vector<Student> students;
    int choice = 0;

    while (choice != 3) {
        cout << "\n Student Record Management \n";
        cout << "1. Add New Student\n";
        cout << "2. View All Students\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Student s;
            cout << "Enter Roll Number: ";
            cin >> s.rollNo;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, s.name);
            cout << "Enter Marks: ";
            cin >> s.marks;
            
            students.push_back(s);
            cout << "--> Student record added successfully!\n";
        } 
        else if (choice == 2) {
            if (students.empty()) {
                cout << "--> No student records found.\n";
            } else {
                cout << "\n--- Student List ---\n";
                for (size_t i = 0; i < students.size(); ++i) {
                    cout << "Roll No: " << students[i].rollNo 
                         << " | Name: " << students[i].name 
                         << " | Marks: " << students[i].marks << "\n";
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