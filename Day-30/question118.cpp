#include <iostream>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    bool isIssued;
};

int main() {
    Book library[100];
    int count = 0, choice, searchId;

    do {
        cout << "\n--- Mini Library ---\n";
        cout << "1. Add Book\n2. Issue Book\n3. Return Book\n4. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Book ID: "; cin >> library[count].id;
            cout << "Title: "; cin.ignore(); getline(cin, library[count].title);
            library[count].isIssued = false;
            count++;
        } else if (choice == 2 || choice == 3) {
            cout << "Enter Book ID: "; cin >> searchId;
            bool found = false;
            for (int i = 0; i < count; i++) {
                if (library[i].id == searchId) {
                    library[i].isIssued = (choice == 2);
                    cout << (choice == 2 ? "Book Issued.\n" : "Book Returned.\n");
                    found = true; break;
                }
            }
            if (!found) cout << "Book not found.\n";
        }
    } while (choice != 4);

    return 0;
}