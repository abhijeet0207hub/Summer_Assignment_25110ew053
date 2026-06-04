#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the term number: ";
    cin >> n;

    int first = 0, second = 1, next;

    if (n == 1) {
        cout << "The " << n << "th term of Fibonacci series is: " << first << endl;
    } else if (n == 2) {
        cout << "The " << n << "th term of Fibonacci series is: " << second << endl;
    } else {
        for (int i = 3; i <= n; i++) {
            next = first + second;
            first = second;
            second = next;
        }
        cout << "The " << n << "th term of Fibonacci series is: " << second << endl;
    }

    return 0;
}
