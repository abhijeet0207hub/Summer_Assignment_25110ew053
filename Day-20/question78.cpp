#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter size of the square matrix (N x N): ";
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    bool isSymmetric = true;

    // Logic to check symmetry
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != mat[j][i]) {
                isSymmetric = false;
                break;
            }
        }
        if (!isSymmetric) break;
    }

    if (isSymmetric) {
        cout << "The matrix is symmetric." << endl;
    } else {
        cout << "The matrix is NOT symmetric." << endl;
    }

    return 0;
}