#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

vector<int> findIntersection(vector<int>& arr1, vector<int>& arr2) {
    vector<int> intersection;
    
    
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    
    
    set_intersection(arr1.begin(), arr1.end(), 
                     arr2.begin(), arr2.end(), 
                     back_inserter(intersection));
                     
    return intersection;
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
    
    
    vector<int> result = findIntersection(arr1, arr2);
    
    cout << "Intersection of arrays: ";
    if (result.empty()) {
        cout << "No intersection found.";
    } else {
        for (int num : result) cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
