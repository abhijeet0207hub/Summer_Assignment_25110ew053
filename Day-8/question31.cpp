#include <iostream>
using namespace std;

int main() {
    int n = 5;
    
    for (int i = 1; i <= n; i++) {
        char ch = 'A'; // Reset to 'A' at the start of each row
        for (int j = 1; j <= i; j++) {
            cout << ch;
            ch++;      // Increment to the next letter
        }
        cout << endl;
    }
    
    return 0;
}