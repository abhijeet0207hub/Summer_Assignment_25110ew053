#include <iostream>

using namespace std;

int main() {
    int x, n;
    cout << "Enter base and exponent: ";
    cin >> x >> n;

    long long res = 1;
    long long base = x;
    int exponent = n; 

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            res *= base;
        }
        base *= base;
        exponent /= 2;
    }

    cout << x << "^" << n << " = " << res << endl;
    return 0;
}
