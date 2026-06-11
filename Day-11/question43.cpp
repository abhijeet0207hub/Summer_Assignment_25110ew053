#include <iostream>
using namespace std;

// Function returns true if prime, false otherwise
bool isPrime(int n) {
    // 0, 1, and negative numbers are not prime
    if (n <= 1) {
        return false;
    }
    

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false; 
        }
    }
    return true; 
}

int main() {
    int num;
    cout << "Enter a number to check: ";
    cin >> num;
    
    if (isPrime(num)) {
        cout << num << " is a Prime Number." << endl;
    } else {
        cout << num << " is NOT a Prime Number." << endl;
    }
    
    return 0;
}