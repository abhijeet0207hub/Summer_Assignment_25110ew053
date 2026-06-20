#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter the size of the square matrix (N x N): ";
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    cout << "Enter elements of the Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    int primarySum = 0;
    int secondarySum = 0;

    
    for (int i = 0; i < n; i++) {
        primarySum += mat[i][i];              
        secondarySum += mat[i][n - i - 1];      
    }

    cout << "Primary Diagonal Sum: " << primarySum << endl;
    cout << "Secondary Diagonal Sum: " << secondarySum << endl;

    
    int totalDiagonalSum = primarySum + secondarySum;
    
    
    if (n % 2 != 0) {
        totalDiagonalSum -= mat[n / 2][n / 2];
    }
    
    cout << "Total Diagonal Sum (Unique Elements): " << totalDiagonalSum << endl;

    return 0;
}