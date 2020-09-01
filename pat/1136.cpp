#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline void add(string &a, string &b) {
    if (b.length() > a.length()) {
        swap(a, b);
    }

    bool carry = false;
    auto ia = a.rbegin(), ib = b.rbegin();
    for (; ib != b.rend(); ++ia, ++ib) {
        *ia = (*ia + *ib - 2 * '0') + (carry ? 1 : 0);
        carry = *ia >= 10;
        *ia = *ia % 10 + '0';
    }

    while (ia != a.rend() && carry) {
        *ia += 1;
        carry = *ia > '9';
        *ia = (*ia - '0') % 10 + '0';
        --ia;
    }

    if (ia == a.rend() && carry) {
        a = string("1") + a;
    }
}

inline bool check_palindrome(const string &a) {
    auto left = a.cbegin();
    auto right = a.cend() - 1;

    while (left < right) {
        if (*left != *right) {
            return false;
        }

        ++left;
        --right;
    }

    return true;
}

int main(void) {
    string a, b;
    cin >> a;

    int i;
    for (i = 0; i < 10; ++i) {
        if (check_palindrome(a)) {
            break;
        }

        b = a;
        reverse(b.begin(), b.end());
        printf("%s + %s = ", a.c_str(), b.c_str());
        add(a, b);
        printf("%s\n", a.c_str());
    }

    if (i == 10) {
        printf("Not found in 10 iterations.");
    } else {
        printf("%s is a palindromic number.", a.c_str());
    }

    return 0;
}