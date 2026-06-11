#include <iostream>
using namespace std;


long long findFactorial(int n) {
    if (n < 0) {
        return 0; 
    }
    
    long long factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }
    
    return factorial;
}

int main() {
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;
    
    long long result = findFactorial(num);
    
    if (num >= 0) {
        cout << "Factorial of " << num << " is: " << result << endl;
    } else {
        cout << "Error: Factorial of a negative number doesn't exist." << endl;
    }
    
    return 0;
}