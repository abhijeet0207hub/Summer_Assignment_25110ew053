#include <iostream>
#include <string>
using namespace std;

int main() {
    string playerName;
    cout << "Enter your name to start the quiz: ";
    getline(cin, playerName);

    int score = 0;
    int answer;
    
    cout << "\n--- Welcome to the Quiz, " << playerName << "! ---" << endl;
    
    cout << "Q1. Which language is this program written in?" << endl;
    cout << "1) Python\n2) C++\n3) Java" << endl;
    cout << "Your answer (1-3): ";
    cin >> answer;
    if (answer == 2) score++;
    
    cout << "\nQ2. Which company is NOT listed for this question in your assignment?" << endl;
    cout << "1) TCS\n2) Accenture\n3) Google" << endl;
    cout << "Your answer (1-3): ";
    cin >> answer;
    if (answer == 3) score++;
    
    cout << "\nQ3. What is the minimum voting age in most democracies?" << endl;
    cout << "1) 16\n2) 18\n3) 21" << endl;
    cout << "Your answer (1-3): ";
    cin >> answer;
    if (answer == 2) score++;
    
    cout << "\n--- Quiz Finished ---" << endl;
    cout << playerName << ", your final score is: " << score << " out of 3." << endl;
    
    return 0;
}