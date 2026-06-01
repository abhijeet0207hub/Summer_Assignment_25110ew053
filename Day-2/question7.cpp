#include <iostream>

using namespace std;

int main() {
    int n , digit;
    long long product = 1; 

    cout << "Enter a number: ";
    cin >> n;

    if (n == 0) {
        product = 0;
    } else {
        if (n < 0) {
            n = -n;
        }
        
        while (n > 0) {
            digit = n % 10;
            product = product*digit;
            n= n/10;
        }
    }

    cout << "The product of the digits is: " << product << endl;

    return 0;
}