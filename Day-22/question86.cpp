#include <iostream>
#include <string>

using namespace std;

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    int wordCount = 0;
    bool inWord = false;

    for (char c : sentence) {
        if (c == ' ' || c == '\t' || c == '\n') {
            inWord = false;
        } else if (!inWord) {
            wordCount++;
            inWord = true;
        }
    }

    cout << "Number of words: " << wordCount << endl;
    
    return 0;
}