#include <iostream>
#include <string>
#include <iomanip> 

using namespace std;

int main() {
    string name, course;
    int rollNo;
    float marks[5];
    string subjects[5] = {"Mathematics", "Physics", "Chemistry", "English", "Computer Sci."};
    float total = 0, percentage = 0;
    char grade;

    cout << "=== Marksheet Generation System ===\n";
    

    cout << "Enter Student Name: ";
    getline(cin, name);
    
    cout << "Enter Roll Number: ";
    cin >> rollNo;
    cin.ignore(); 
    
    cout << "Enter Course/Class: ";
    getline(cin, course);

    
    cout << "\n--- Enter Marks (out of 100) ---\n";
    for(int i = 0; i < 5; i++) {
        cout << subjects[i] << ": ";
        cin >> marks[i];
        
    
        if (marks[i] < 0 || marks[i] > 100) {
            cout << "Invalid marks! Please enter a value between 0 and 100.\n";
            i--; 
            continue;
        }
        total += marks[i];
    }

    
    percentage = total / 5.0;
    
    if (percentage >= 90) grade = 'A';
    else if (percentage >= 80) grade = 'B';
    else if (percentage >= 70) grade = 'C';
    else if (percentage >= 60) grade = 'D';
    else if (percentage >= 40) grade = 'E';
    else grade = 'FAIL'; 

    
    cout << "\n==========================================\n";
    cout << "                 MARKSHEET                \n";
    cout << "==========================================\n";
    cout << "Name      : " << name << "\n";
    cout << "Roll No   : " << rollNo << "\n";
    cout << "Course    : " << course << "\n";
    cout << "------------------------------------------\n";
    
    cout << left << setw(20) << "Subject" << "Marks\n";
    cout << "------------------------------------------\n";
    for(int i = 0; i < 5; i++) {
        cout << left << setw(20) << subjects[i] << marks[i] << "\n";
    }
    cout << "------------------------------------------\n";
    
    cout << left << setw(20) << "Total Marks:" << total << " / 500\n";
    cout << left << setw(20) << "Percentage:" << fixed << setprecision(2) << percentage << "%\n";
    cout << left << setw(20) << "Grade:" << grade << "\n";
    
    if (grade == 'F') {
        cout << "Result    : FAIL\n";
    } else {
        cout << "Result    : PASS\n";
    }
    cout << "==========================================\n";

    return 0;
}