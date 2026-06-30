#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
};

int main() {
    vector<Book> books;
    int choice;

    do {
        cout << "\n--- Library Management System ---\n";
        cout << "1. Add Book\n2. Display Books\n3. Search Book\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Book newBook;
                cout << "Enter Book ID: ";
                cin >> newBook.id;
                cin.ignore();
                cout << "Enter Book Title: ";
                getline(cin, newBook.title);
                cout << "Enter Author Name: ";
                getline(cin, newBook.author);
                
                books.push_back(newBook);
                cout << "Book added successfully!\n";
                break;
            }
            case 2: {
                if (books.empty()) {
                    cout << "Library is empty.\n";
                } else {
                    cout << "\n--- Library Catalog ---\n";
                    for (int i = 0; i < books.size(); i++) {
                        cout << "ID: " << books[i].id << " | Title: " << books[i].title << " | Author: " << books[i].author << "\n";
                    }
                }
                break;
            }
            case 3: {
                int searchId;
                bool found = false;
                cout << "Enter Book ID to search: ";
                cin >> searchId;
                
                for (int i = 0; i < books.size(); i++) {
                    if (books[i].id == searchId) {
                        cout << "Book Found - Title: " << books[i].title << ", Author: " << books[i].author << "\n";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Book not found.\n";
                }
                break;
            }
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}