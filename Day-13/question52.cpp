#include <iostream>
using namespace std;

int main() {
    int n, evenCount = 0, oddCount = 0;

    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[100];

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        if (arr[i] % 2 == 0)
            evenCount++;
        else
            oddCount++;
    }

    cout << "\nEven elements = " << evenCount << endl;
    cout << "Odd elements = " << oddCount << endl;

    return 0;
}
