#include <iostream>
#include <vector>

using namespace std;

int findMissingNumber(const vector<int>& arr, int n) {
    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;
    for (int num : arr) {
        actualSum += num;
    }
    return expectedSum - actualSum;
}

int main() {
    int n;
    cout << "Enter the maximum number (N): ";
    cin >> n;
    
    int size = n - 1; 
    vector<int> arr(size);
    
    cout << "Enter the " << size << " elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    
    cout << "Missing number: " << findMissingNumber(arr, n) << endl;
    return 0;
}