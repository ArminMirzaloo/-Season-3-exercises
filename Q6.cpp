#include <iostream>
using namespace std;

void khayamPascal(int n) {
    int arr[n][n];

    // Initialize the first element of each row and the diagonal elements to 1
    for (int i = 0; i < n; i++) {
        arr[i][0] = 1;
        arr[i][i] = 1;
    }

    // Fill in the Pascal's triangle values
    for (int i = 2; i < n; i++) {
        for (int j = 1; j < i; j++) {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }

    // Print the triangle with appropriate spacing
    for (int i = 0; i < n; i++) {
        for (int space = 0; space < n - i - 1; space++) {
            cout << " ";
        }
        for (int j = 0; j <= i; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;

    khayamPascal(n);

    return 0;
}
