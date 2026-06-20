#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int maxFrequencyElement(const vector<int>& arr) {
    unordered_map<int, int> freqMap;
    int maxFreq = 0;
    int mostFrequentElement = -1;

    for (int num : arr) {
        freqMap[num]++;
        if (freqMap[num] > maxFreq) {
            maxFreq = freqMap[num];
            mostFrequentElement = num;
        }
    }
    return mostFrequentElement;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Maximum frequency element: " << maxFrequencyElement(arr) << endl;
    return 0;
}