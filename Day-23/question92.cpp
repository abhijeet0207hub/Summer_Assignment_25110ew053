#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    int freq[256] = {0};
    for (char c : str) {
        freq[(unsigned char)c]++;
    }

    char maxChar = '\0';
    int maxFreq = -1;

    for (int i = 0; i < 256; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            maxChar = (char)i;
        }
    }

    cout << "Maximum occurring character: '" << maxChar << "Frequency: " << maxFreq ;
    
    return 0;
}