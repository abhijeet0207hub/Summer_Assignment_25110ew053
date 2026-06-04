#include <iostream>
#include <cmath>
using namespace std;

bool isArmstrong(int num) {
    int originalNum = num;
    int digits = 0;
    int result = 0;

    
    int temp = num;
    while (temp != 0) {
        temp /= 10;
        digits++;
    }

    temp = num;
    while (temp != 0) {
        int remainder = temp % 10;
        result += round(pow(remainder, digits)); 
        temp /= 10;
    }

    return result == originalNum;
}

int main() {
    int start, end;

    cout << "Enter the starting number of the range: ";
    cin >> start;
    
    cout << "Enter the ending number of the range: ";
    cin >> end;

    cout << "\nArmstrong numbers between " << start << " and " << end << " are: \n";

    for (int i = start; i <= end; i++) 
    {
        if (isArmstrong(i)) {
            cout << i << " ";
        }
    }
    
    cout << endl;

    return 0;
}