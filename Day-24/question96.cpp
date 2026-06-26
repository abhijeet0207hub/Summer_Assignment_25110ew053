#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    string result = "";
    bool seen[256] = {false}; // ASCII character tracker

    for (char c : str) {
        if (!seen[c]) {
            result += c;
            seen[c] = true;
        }
    }

    cout << "String after removing duplicates: " << result << endl;
    return 0;
}