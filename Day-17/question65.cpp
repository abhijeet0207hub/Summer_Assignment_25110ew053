#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeArrays(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> merged = arr1;
    merged.insert(merged.end(), arr2.begin(), arr2.end());
    return merged;
}

int main() {
    int n1, n2;
    
    cout << "Enter the size of the first array: ";
    cin >> n1;
    vector<int> arr1(n1);
    cout << "Enter " << n1 << " elements for the first array: ";
    for (int i = 0; i < n1; i++) cin >> arr1[i];
    
    cout << "Enter the size of the second array: ";
    cin >> n2;
    vector<int> arr2(n2);
    cout << "Enter " << n2 << " elements for the second array: ";
    for (int i = 0; i < n2; i++) cin >> arr2[i];
    
    vector<int> result = mergeArrays(arr1, arr2);
    
    cout << "Merged Array: ";
    for (int num : result) cout << num << " ";
    cout << endl;
    
    return 0;
}