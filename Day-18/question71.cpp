#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, target;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " SORTED elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    
    sort(arr.begin(), arr.end()); 

    cout << "Enter the element to search for: ";
    cin >> target;


    int left = 0;
    int right = n - 1;
    int resultIndex = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            resultIndex = mid;
            break;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (resultIndex != -1) {
        cout << "Element found at index: " << resultIndex << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}