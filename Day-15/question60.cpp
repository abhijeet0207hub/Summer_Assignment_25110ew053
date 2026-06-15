#include <iostream>
#include <vector>
#include <algorithm>

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
    
    int nonZeroIdx = 0; 
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) {
            swap(arr[nonZeroIdx], arr[i]);
            nonZeroIdx++;
        }
    }
    
    cout << "Array after moving zeroes: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}