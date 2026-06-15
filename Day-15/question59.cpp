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
    
    int k;
    cout << "Enter the number of positions to rotate right: ";
    cin >> k;
    
    // Rotate right logic
    if (!arr.empty()) {
        k = k % n; 
        
        reverse(arr.end() - k, arr.end());
        reverse(arr.begin(), arr.end() - k);
        reverse(arr.begin(), arr.end());
    }
    
    cout << "Array rotated right by " << k << ": ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}