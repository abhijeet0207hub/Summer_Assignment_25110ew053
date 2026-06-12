#include <iostream>
#include <functional>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;
    
    function<int(int)> fibonacci = [&](int num) -> int {
        if (num == 0) return 0;
        if (num == 1) return 1;
        return fibonacci(num - 1) + fibonacci(num - 2);
    };

    cout << "Fibonacci Series: ";
    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;
    
    return 0;
}