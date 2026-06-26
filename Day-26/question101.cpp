#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    
    int maxRange;
    cout << "Enter the maximum number for the guessing range: ";
    cin >> maxRange;
    
    int secretNum = rand() % maxRange + 1; 
    int guess;
    int attempts = 0;
    
    cout << "Guess the secret number (between 1 and " << maxRange << "): " << endl;
    
    while (true) {
        cout << "Your guess: ";
        cin >> guess;
        attempts++;
        
        if (guess > secretNum) {
            cout << "Too high! Try again." << endl;
        } else if (guess < secretNum) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number in " << attempts << " attempts." << endl;
            break;
        }
    }
    return 0;
}