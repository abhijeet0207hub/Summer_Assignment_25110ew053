#include <iostream>
using namespace std;


int findSum(int a, int b) {
    return a + b;
}

int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    int sum = findSum(num1, num2);
    
    cout << "Sum: " << sum << endl;
    
    return 0;
}