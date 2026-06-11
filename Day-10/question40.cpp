#include <iostream>
using namespace std;

int main() {
    int n = 5;
    for (int i = 1; i <= n; i++) {
        // Print leading spaces
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        // Print increasing characters
        for (int j = 0; j < i; j++) {
            cout << (char)('A' + j);
        }
        // Print decreasing characters
        for (int j = i - 2; j >= 0; j--) {
            cout << (char)('A' + j);
        }
        cout << endl;
    }
    return 0;
}