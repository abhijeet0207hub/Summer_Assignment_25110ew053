#include <iostream>

using namespace std;

int reverseNumber(int n, int reversed = 0) {

    if (n == 0) return reversed;
    
    reversed = reversed * 10 + (n % 10);
    
    return reverseNumber(n / 10, reversed);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Reversed number: " << reverseNumber(n) << endl;
    return 0;
}