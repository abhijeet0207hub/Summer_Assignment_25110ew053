#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    if (s1.length() == s2.length() && (s1 + s1).find(s2) != string::npos) {
        cout << "The strings are rotations of each other." << endl;
    } else {
        cout << "The strings are NOT rotations of each other." << endl;
    }
    return 0;
}