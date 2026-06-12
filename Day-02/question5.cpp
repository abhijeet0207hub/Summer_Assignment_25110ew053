#include <iostream>
using namespace std;
int main() {
    int n, a,sum = 0;

    cout << "Enter the number: ";
    cin >> n;


    if (n < 0) n= -n;

    int temp = n; 
    while (temp > 0) {
        a=temp%10;
        sum=sum+a ;
        temp = temp/10;       
    }

    std::cout << "The sum of digits of " << n << " is: " << sum << std::endl;

    return 0;
}