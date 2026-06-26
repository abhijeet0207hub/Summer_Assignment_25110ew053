#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string sentence;
    cout << "Enter a sentence to sort its words by length: ";
    getline(cin, sentence); 
    
    stringstream ss(sentence);
    string words[100];
    string word;
    int count = 0;
    
    while (ss >> word && count < 100) {
        words[count++] = word;
    }
    
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (words[j].length() > words[j + 1].length()) {
                string temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
    
    cout << "Words sorted by length: ";
    for (int i = 0; i < count; i++) {
        cout << words[i] << " ";
    }
    cout << endl;
    return 0;
}