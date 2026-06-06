#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    // Using GCC built-in popcount
    cout << "Set bits: " << __builtin_popcount(n) << endl;
    return 0;
}