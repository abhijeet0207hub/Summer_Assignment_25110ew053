#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rows, cols;
    cout << "Enter number of rows and columns for the matrices: ";
    cin >> rows >> cols;

    vector<vector<int>> mat1(rows, vector<int>(cols));
    vector<vector<int>> mat2(rows, vector<int>(cols));
    vector<vector<int>> sum(rows, vector<int>(cols));

    cout << "Enter elements of the First Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat1[i][j];
        }
    }

    cout << "Enter elements of the Second Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat2[i][j];
        }
    }

    
    cout << "Resultant Matrix after Addition:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum[i][j] = mat1[i][j] + mat2[i][j];
            cout << sum[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}