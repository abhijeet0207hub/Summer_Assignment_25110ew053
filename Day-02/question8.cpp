#include <iostream>
using namespace std;

int main() {
    int n, num, a, rev = 0;
    cout << "Enter the number: ";
    cin >> n;
    num = n;
    while (n != 0) {
        a = n % 10;
        n = n / 10;
        rev = (rev * 10) + a;
    }
    if (num == rev) cout << "The number is a palindrome";
    else 
    cout << "The number is not a palindrome";
    return 0;
}