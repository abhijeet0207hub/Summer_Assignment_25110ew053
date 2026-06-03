#include <iostream>
using namespace std;
bool result(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int start, end;
    cout << "Enter the start of the range: ";
    cin >> start;
    cout << "Enter the end of the range: ";
    cin >> end;
    
    cout << "Prime numbers between " << start << " and " << end << " are: \n";
    
    for (int i = start; i <= end; i++) {
        if (result(i)) {
            cout << i << " ";
        }
    }
    
    return 0;
}