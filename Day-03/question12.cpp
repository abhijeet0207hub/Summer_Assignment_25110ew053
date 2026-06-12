#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two numbers to find their LCM: ";
    cin >> a >> b;
    
    int num1 = a;
    int num2 = b;
    
    while (num2 != 0) {
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    int hcf = num1;
    
    //Calculate LCM using the formula lcm x hcf = a x b
    int lcm = (a * b) / hcf;
    
    cout << "The LCM of " << a << " and " << b << " is: " << lcm << endl;
    
    return 0;
}