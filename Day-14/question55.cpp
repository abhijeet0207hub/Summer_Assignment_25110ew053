#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int largest = INT_MIN;
    int second = INT_MIN;
    
    // Second largest logic
    if (arr.size() >= 2) {
        for (int num : arr) {
            if (num > largest) {
                second = largest;
                largest = num;
            } else if (num > second && num != largest) {
                second = num;
            }
        }
    }

    if (second != INT_MIN) {
        cout << "Second largest element is: " << second << endl;
    } else {
        cout << "No second largest element exists." << endl;
    }
    
    return 0;
}