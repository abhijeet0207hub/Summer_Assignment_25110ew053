#include <iostream>
#include <string>

using namespace std;
int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    int freq[256] = {0};
    for (char c : str) {
        freq[(unsigned char)c]++;
    }

    bool found = false;
    for (char c : str) {
        if (freq[(unsigned char)c] == 1) {
            cout << "First non-repeating character: '" << c << "'" ;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No non-repeating character found.";
    }
    
    return 0;
}