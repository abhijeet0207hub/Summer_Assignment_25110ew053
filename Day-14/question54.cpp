#include <iostream>
#include <vector>

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
    
    int target;
    cout << "Enter the element to find the frequency of: ";
    cin >> target;
    
    int count = 0;

    // Frequency logic
    for (int num : arr) {
        if (num == target) {
            count++;
        }
    }

    cout << "Frequency of " << target << " is: " ;
    
    return 0;
}