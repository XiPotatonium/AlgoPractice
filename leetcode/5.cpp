/// 最长回文子串
/// 有DP算法

#include <iostream>
#include <string>

using namespace std;

bool is_palindrome[1000][1000];

class Solution {
public:
    string longestPalindrome(string s) {
        return dp(s);
    }

    string trival(string s) {
        for (int len = s.length(); len > 0; --len) {
            for (int left = 0; left <= s.length() - len; ++left) {
                bool is_palindrome = true;
                for (int i = left, j = left + len - 1; i <= j; ++i, --j) {
                    if (s[i] != s[j]) {
                        is_palindrome = false;
                        break;
                    }
                }
                if (is_palindrome) {
                    return s.substr(left, len);
                }
            }
        }

        return s.substr(0, 1);
    }

    string dp(string s) {
        int max_left = 0;
        int max_len = 1;
        for (int i = 0; i < 1000; ++i) {
            for (int j = i + 1; j < 1000; ++j) {
                is_palindrome[i][j] = 0;
            }
            is_palindrome[i][i] = 1;
        }

        for (int left = 0; left + 2 <= s.length(); ++left) {
            if (s[left] == s[left + 1]) {
                is_palindrome[left][left + 1] = true;
                max_left = left;
                max_len = 2;
            }
        }

        for (int len = 3; len <= s.length(); ++len) {
            for (int left = 0; left + len <= s.length(); ++left) {
                if (is_palindrome[left + 1][left + len - 2] && s[left] == s[left + len - 1]) {
                    is_palindrome[left][left + len - 1] = true;
                    max_left = left;
                    max_len = len;
                }
            }
        }

        return s.substr(max_left, max_len);
    }
};

int main(void) {
    Solution solution;
    string s;

    cin >> s;
    cout << solution.longestPalindrome(s);

    return 0;
}