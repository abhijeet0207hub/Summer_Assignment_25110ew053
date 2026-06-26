#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter a string to compress ";
    cin >> str;

    string compressed = "";
    for (int i = 0; i < str.length(); i++) {
        int count = 1;
        
        while (i + 1 < str.length() && str[i] == str[i + 1]) {
            count++;
            i++;
        }
        compressed += str[i] + to_string(count);
    }

    cout << "Compressed string: " << compressed << endl;
    return 0;
}