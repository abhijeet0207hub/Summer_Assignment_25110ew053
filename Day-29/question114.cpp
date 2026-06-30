#include <iostream>
using namespace std;

int main() {
    int arr[100], size = 0, choice, element, pos;

    do {
        cout << "\n--- Array Operations ---\n";
        cout << "1. Insert\n2. Delete (by index)\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (size < 100) {
                    cout << "Enter element to insert: ";
                    cin >> arr[size++];
                    cout << "Inserted successfully.\n";
                } else {
                    cout << "Array is full!\n";
                }
                break;
            case 2:
                cout << "Enter index to delete (0 to " << size - 1 << "): ";
                cin >> pos;
                if (pos >= 0 && pos < size) {
                    for (int i = pos; i < size - 1; i++) arr[i] = arr[i + 1];
                    size--;
                    cout << "Deleted successfully.\n";
                } else {
                    cout << "Invalid index!\n";
                }
                break;
            case 3:
                cout << "Array elements: ";
                for (int i = 0; i < size; i++) cout << arr[i] << " ";
                cout << endl;
                break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}