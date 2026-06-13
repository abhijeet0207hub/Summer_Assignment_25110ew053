#include <iostream>
using namespace std;

int main() {
    int n;
    int sum = 0;

    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[100];

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    float average = (float)sum / n;

    cout << "\nSum of the array elements = " << sum << endl;
    cout << "Average of the array elements = " << average << endl;

    return 0;
}