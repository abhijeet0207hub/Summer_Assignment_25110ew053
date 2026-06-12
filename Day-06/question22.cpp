#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string binary;
    cout << "Enter a binary number: ";
    cin >> binary;

    int decimal = 0;
    int power = 0;
    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }
    cout << "Decimal: " << decimal << endl;
    return 0;
}
