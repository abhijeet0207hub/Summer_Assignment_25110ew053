#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    bool isPalindrome = true;
    int n = str.length();
    
    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - 1 - i]) {
            isPalindrome = false;
            break;
        }
    }

if (isPalindrome) {
        cout << "The string is a Palindrome.";
    } else {
        cout << "The string is Not a Palindrome" ;
    }
    
    return 0;
}