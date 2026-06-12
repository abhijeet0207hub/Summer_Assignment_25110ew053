#include <iostream>
#include <cmath>
using namespace std;

bool isArmstrong(int n) {
    int original = n;
    int sum = 0;
    int digits = 0;
    int temp = n;
    
    
    while (temp > 0) {
        digits++;
        temp /= 10;
    }
    
    temp = n;
    
    while (temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }
    
    return sum == original;
}

int main() {
    int num;
    cout << "Enter a number to check if it is an Armstrong number: ";
    cin >> num;
    
    if (isArmstrong(num))
        cout << num << " is an Armstrong number." << endl;
    else
        cout << num << " is not an Armstrong number." << endl;
        
    return 0;
}