#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;
    
    int count1[256] = {0}, count2[256] = {0};
    
    for (char c : s1) count1[c]++;
    for (char c : s2) count2[c]++;
    
    cout << "Common characters: ";
    for (int i = 0; i < 256; i++) {
        if (count1[i] > 0 && count2[i] > 0) {
            cout << (char)i << " ";
        }
    }
    cout << endl;
    return 0;
}