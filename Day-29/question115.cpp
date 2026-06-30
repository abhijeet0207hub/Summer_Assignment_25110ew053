#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;
    int choice;

    do {
        cout << "\n--- String Operations ---\n";
        cout << "1. Find Length\n2. Concatenate\n3. Compare\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // Clear newline buffer

        switch (choice) {
            case 1:
                cout << "Enter a string: ";
                getline(cin, str1);
                cout << "Length: " << str1.length() << endl;
                break;
            case 2:
                cout << "Enter first string: "; getline(cin, str1);
                cout << "Enter second string: "; getline(cin, str2);
                cout << "Concatenated: " << str1 + str2 << endl;
                break;
            case 3:
                cout << "Enter first string: "; getline(cin, str1);
                cout << "Enter second string: "; getline(cin, str2);
                if (str1 == str2) cout << "Strings are equal.\n";
                else cout << "Strings are not equal.\n";
                break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}