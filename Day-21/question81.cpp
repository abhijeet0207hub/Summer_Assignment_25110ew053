#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    int length = 0;
    
    
    for (char c : str) {
        length++;
    }

    cout << "The length of the string is: " << length << endl;

    return 0;
}