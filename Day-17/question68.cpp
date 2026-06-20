#include <iostream>
#include <vector>
#include <unordered_set> 

using namespace std;

vector<int> findCommonElements(const vector<int>& arr1, const vector<int>& arr2) {
    
    unordered_set<int> seenElements(arr1.begin(), arr1.end());
    vector<int> commonElements;
    
    
    for (int num : arr2) {
        
        if (seenElements.find(num) != seenElements.end()) { 
            commonElements.push_back(num);
            
             
            seenElements.erase(num); 
        }
    }
    return commonElements;
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
    
    
    vector<int> result = findCommonElements(arr1, arr2);
    
    cout << "Common elements: ";
    if (result.empty()) {
        cout << "No common elements found.";
    } else {
        for (int num : result) cout << num << " ";
    }
    cout << endl;
    
    return 0;
}