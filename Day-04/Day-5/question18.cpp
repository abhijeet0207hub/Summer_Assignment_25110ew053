#include <iostream>
using namespace std;

int main() {
    int n, Num, rem, sum = 0;

    cout << "Enter a number to check: ";
    cin >> n;

    Num = n;

    while (n > 0) {
        rem = n % 10; 
        
        int fact = 1;
        for (int i = 1; i <= rem; i++) {
            fact *= i;
        }
        
        sum += fact;
        
        n /= 10;
    }

    if (sum == Num && Num > 0) {
        cout << Num << " is a Strong number." << endl;
    } else {
        cout << Num << " is not a Strong number." << endl;
    }

    return 0;
}