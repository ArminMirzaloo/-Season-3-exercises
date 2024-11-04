#include <iostream>
#include <cstring>
using namespace std;

class BigNumber {
private:
    int digits[1000];
    int size;

public:
    BigNumber(int num = 1) {
        memset(digits, 0, sizeof(digits));
        size = 0;
        while (num > 0) {
            digits[size++] = num % 10;
            num /= 10;
        }
    }

    void multiply(int num) {
        int carry = 0;
        for (int i = 0; i < size; ++i) {
            int product = digits[i] * num + carry;
            digits[i] = product % 10;
            carry = product / 10;
        }
        while (carry > 0) {
            digits[size++] = carry % 10;
            carry /= 10;
        }
    }

    static BigNumber fact(int n) {
        BigNumber result(1);
        for (int i = 2; i <= n; ++i) {
            result.multiply(i);
        }
        return result;
    }

    void print() const {
        for (int i = size - 1; i >= 0; --i) {
            cout << digits[i];
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter a number between 1 and 100: ";
    cin >> n;

    if (n < 1 || n > 100) {
        cout << "Number out of range!" << endl;
        return 1;
    }

    BigNumber result = BigNumber::fact(n);
    cout << "Factorial of " << n << " is: ";
    result.print();

    return 0;
}
