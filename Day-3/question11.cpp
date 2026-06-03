#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two numbers to find their GCD: ";
    cin >> a >> b;
    
    int originalA = a;
    int originalB = b;

    
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    cout << "The GCD of " << originalA << " and " << originalB << " is: " << a << endl;
    
    return 0;
}