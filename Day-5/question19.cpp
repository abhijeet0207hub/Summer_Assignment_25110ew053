#include <iostream>
using namespace std;

int main() {
    int num;

    cout << "Enter a number to find its factors: ";
    cin >> num;

    if (num <= 0) {
        cout << "enter a positive integer." << endl;
    } else {
        cout << "Factors of " << num << " are: ";
        
        for (int i = 1; i <= num; i++) {
        
            if (num % i == 0) {
                cout << i << " ";
            }
        }
        cout << endl;
    }

    return 0;
}