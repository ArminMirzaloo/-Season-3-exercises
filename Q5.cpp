#include <iostream>
using namespace std;

void changeValue(int a[][100], int n) {
    //  Increase elements on the main diagonal by one unit
    for (int i = 0; i < n; ++i) {
        a[i][i] += 1;
    }

    //  Decrease elements on the secondary diagonal by one unit
    for (int i = 0; i < n; ++i) {
        a[i][n - i - 1] -= 1;
    }

    //  Increase elements above the main and secondary diagonals by one unit
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            a[i][j] += 1;       // Above the main diagonal
            a[j][i] += 1;       // Above the secondary diagonal
        }
    }

    //  Decrease elements below the main and secondary diagonals by one unit
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            a[i][j] -= 1;       // Below the main diagonal
            a[j][n - i - 1] -= 1; // Below the secondary diagonal
        }
    }

    //  Increase elements to the left of the main and secondary diagonals by two units
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            a[i][j] += 2;
        }
    }

    //  Decrease elements to the right of the main and secondary diagonals by two units
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            a[i][j] -= 2;
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;

    int a[100][100];
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    changeValue(a, n);

    cout << "Modified matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
