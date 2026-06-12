#include <iostream>

using namespace std;

int main() {
    long long n;
    cout << "Enter a number: ";
    cin >> n;

    if (n <= 1) {
        cout << "No prime factors exist for numbers <= 1." << endl;
        return 0;
    }

    long long largest_prime = -1;

    for (long long i = n / 2; i >= 2; --i) {
        
        if (n % i == 0) {
            
            bool is_prime = true;
            for (long long j = 2; j * j <= i; ++j) {
                if (i % j == 0) {
                    is_prime = false;
                    break; 
                }
            }
            
            if (is_prime) {
                largest_prime = i;
                break; 
            }
        }
    }

    if (largest_prime == -1) {
        largest_prime = n;
    }

    cout << "The largest prime factor of " << n << " is " << largest_prime << endl;

    return 0;
}