#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    int age;
    
    cout << "Enter your full name: ";
    getline(cin, name);
    
    cout << "Enter your age: ";
    cin >> age;
    
    if (age >= 18) {
        cout << name << ", you are eligible to vote." << endl;
    } else {
        cout << name << ", you are NOT eligible to vote. You must wait " << (18 - age) << " more year(s)." << endl;
    }
    return 0;
}