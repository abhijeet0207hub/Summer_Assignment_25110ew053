#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> unionOfArrays(const vector<int>& arr1, const vector<int>& arr2) {
    set<int> unionSet(arr1.begin(), arr1.end());
    unionSet.insert(arr2.begin(), arr2.end());
    
    return vector<int>(unionSet.begin(), unionSet.end());
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
    
    vector<int> result = unionOfArrays(arr1, arr2);
    
    cout << "Union of arrays: ";
    for (int num : result) cout << num << " ";
    cout << endl;
    
    return 0;
}