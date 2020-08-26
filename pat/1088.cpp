#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    long long _a1;
    long long _b1;
    long long _a2;
    long long _b2;

    void _pre_print(char op) {
        print_num(_a1, _b1);
        cout << " " << op << " ";
        print_num(_a2, _b2);
        cout << " = ";
    }

    void print_num(long long a, long long b) {
        if (b == 0) {
            cout << "Inf";
            return;
        } else if (a == 0) {
            cout << "0";
            return;
        }

        bool neg = false;
        if (a < 0) {
            cout << "(-";
            a = -a;
            neg = true;
        }

        long long k = a / b;
        a = a % b;

        if (k != 0) {
            cout << k;
        }
        if (k != 0 && a != 0) {
            cout << " ";
        }
        if (a != 0) {
            long long g = gcd(a, b);
            cout << a / g << "/" << b / g;
        }
        if (neg) {
            cout << ")";
        }
    }

    long long gcd(long long a, long long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

public:
    Solution(long long a1, long long b1, long long a2, long long b2) {
        // 不要在这里就表示成_b1 == _b2的形式
        // 这样会在乘法的时候超出范围（注意乘法）
        // mgj我总觉得这种限制很脑瘫，8102年了还在用大数限制程序，这TM关乎时间空间复杂度吗？
        _a1 = a1;
        _b1 = b1;
        _a2 = a2;
        _b2 = b2;
    }

    void add() {
        _pre_print('+');
        print_num(_a1 * _b2 + _a2 * _b1, _b1 * _b2);
        cout << endl;
    }

    void sub() {
        _pre_print('-');
        print_num(_a1 * _b2 - _a2 * _b1, _b1 * _b2);
        cout << endl;
    }

    void mul() {
        _pre_print('*');
        print_num(_a1 * _a2, _b1 * _b2);
        cout << endl;
    }

    void div() {
        _pre_print('/');
        if (_a2 < 0) {
            print_num(-_a1 * _b2, -_a2 * _b1);
        } else {
            print_num(_a1 * _b2, _a2 * _b1);
        }
        cout << endl;
    }
};

int main() {
    long long a1, b1, a2, b2;
    string num1, num2;
    cin >> num1 >> num2;

    for (long long i = 0; i < num1.size(); ++i) {
        if (num1[i] == '/') {
            num1[i] = ' ';
            break;
        }
    }
    for (long long i = 0; i < num2.size(); ++i) {
        if (num2[i] == '/') {
            num2[i] = ' ';
            break;
        }
    }

    stringstream ss1(num1);
    ss1 >> a1 >> b1;
    stringstream ss2(num2);
    ss2 >> a2 >> b2;

    Solution s(a1, b1, a2, b2);
    s.add();
    s.sub();
    s.mul();
    s.div();

    return 0;
}
