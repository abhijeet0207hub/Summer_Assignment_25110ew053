#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> mat(rows, vector<int>(cols));
    vector<vector<int>> trans(cols, vector<int>(rows)); 

    cout << "Enter elements of the Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }

    
    cout << "Transposed Matrix:\n";
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            trans[i][j] = mat[j][i]; 
            cout << trans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}