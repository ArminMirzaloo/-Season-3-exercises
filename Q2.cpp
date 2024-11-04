#include <iostream>
using namespace std;

int combination(int n, int r) {
    if (r > n - r)  
        r = n - r;
    
    int result = 1;
    for (int i = 0; i < r; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

int main() {
    int n, r;
    cin >> n >> r;
    
    cout << combination(n, r) << endl;
    return 0;
}
