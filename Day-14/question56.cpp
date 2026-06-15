#include <iostream>
#include <vector>
#include <unordered_set>

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
    
    unordered_set<int> seen;
    unordered_set<int> duplicates;
    
    // Duplicate finding logic
    for (int num : arr) {
        if (seen.find(num) != seen.end()) {
            duplicates.insert(num);
        } else {
            seen.insert(num);
        }
    }
    
    cout << "Duplicates: ";
    if (duplicates.empty()) {
        cout << "None";
    } else {
        for (int num : duplicates) {
            cout << num << " ";
        }
    }
    cout << endl;
    
    return 0;
}