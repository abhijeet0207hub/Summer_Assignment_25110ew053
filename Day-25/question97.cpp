#include <iostream>
using namespace std;

int main() {
    int n1, n2;
    int arr1[100], arr2[100], merged[200];
    
    cout << "Enter the number of elements for the first sorted array: ";
    cin >> n1;
    cout << "Enter " << n1 << " sorted elements: ";
    for(int i = 0; i < n1; i++) cin >> arr1[i];
    
    cout << "Enter the number of elements for the second sorted array: ";
    cin >> n2;
    cout << "Enter " << n2 << " sorted elements: ";
    for(int i = 0; i < n2; i++) cin >> arr2[i];
    
    int i = 0, j = 0, k = 0;
    

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }
    

    while (i < n1) merged[k++] = arr1[i++];
    while (j < n2) merged[k++] = arr2[j++];
    
    cout << "Merged Array: ";
    for (int x = 0; x < n1 + n2; x++) {
        cout << merged[x] << " ";
    }
    cout << endl;
    return 0;
}