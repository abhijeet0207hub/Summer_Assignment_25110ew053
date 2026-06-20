#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void findPair(const vector<int>& arr, int target) {
    unordered_set<int> seen;
    for (int num : arr) {
        int complement = target - num;
        if (seen.count(complement)) {
            cout << "Pair found: (" << complement << ", " << num << ")" << endl;
            return;
        }
        seen.insert(num);
    }
    cout << "No pair found with the given sum." << endl;
}

int main() {
    int n, target;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target sum: ";
    cin >> target;

    findPair(arr, target);
    return 0;
}