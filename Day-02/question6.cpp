#include <iostream>
using namespace std;
int main() {
    int n, rev = 0, rem;

    cout << "Enter the number: ";
    cin >> n;

    int temp = n;
    
    while (temp != 0) {
        rem = temp % 10;           
        rev = (rev * 10) + rem;
        temp=temp/ 10;                      
    }

    cout << "The reverse of " << n<< " is: " << rev << endl;

    return 0;
}