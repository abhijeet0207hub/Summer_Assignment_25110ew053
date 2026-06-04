#include <iostream>
#include <cmath> 
using namespace std;

int main() {
    int num, originalNum, remainder;
    int digits = 0;
    int result = 0;

    cout << "Enter an integer: ";
    cin >> num;

    originalNum = num;

    
    while (originalNum != 0) {
        originalNum /= 10;
        digits++;
    }

    originalNum = num;

    while (originalNum != 0) {
        remainder = originalNum % 10;
        
        result += round(pow(remainder, digits)); 
        
        originalNum /= 10;
    }


    if (result == num) {
        cout << num << " is an Armstrong number." << endl;
    } else {
        cout << num << " is not an Armstrong number." << endl;
    }

    return 0;
}