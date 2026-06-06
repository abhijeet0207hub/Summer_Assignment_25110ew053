#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Enter a decimal number: ";
    cin >> n;

    if (n == 0) {
        cout << "Binary: 0" << endl;
        return 0;
    }

    vector<int> binary;
    while (n > 0) {
        binary.push_back(n % 2);
        n /= 2;
    }

    reverse(binary.begin(), binary.end());
    
    cout << "Binary: ";
    for (int bit : binary) cout << bit;
    return 0;
}