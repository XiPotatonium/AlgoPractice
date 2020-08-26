// 快乐前缀」是在原字符串中既是 非空 前缀也是后缀（不包括原字符串自身）的字符串。
// 给你一个字符串 s，请你返回它的 最长快乐前缀。
// 如果不存在满足题意的前缀，则返回一个空字符串。

// 头一次见到不要求精确的问题
// 这道题如果去判断eq会超时的，直接用哈希结果代替eq判断，不考虑碰撞

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        if (s.length() == 1) {
            return "";
        }

        int s_len = s.length();
        int len = 1;
        int prefix_hash = s[0] - 'a';
        int postfix_hash = s[s_len - 1] - 'a';
        int max_len = s[0] == s[s_len - 1] ? 1 : 0;

        int postfix_base = 26;

        for (len = 2; len < s_len; ++len) {
            prefix_hash = ((prefix_hash * 26) % 82595483 + (s[len - 1] - 'a')) % 82595483;
            postfix_hash = (postfix_hash + ((s[s_len - len] - 'a') * postfix_base) % 82595483) % 82595483;
            postfix_base = (postfix_base * 26) % 82595483;

            if (prefix_hash == postfix_hash) {
                // bool eq = true;
                // for (int i = 0; i < len; ++i) {
                //    if (s[i] != s[s_len - len + i]) {
                //        eq = false;
                //        break;
                //    }
                //}
                // if (eq) {
                //    max_len = len;
                //}
                max_len = len;
            }
        }

        if (max_len == 0) {
            return "";
        } else {
            return s.substr(0, max_len);
        }
    }
};

// 2147483629
// 82595483
// 16777213

int foo() {
    int n = INT32_MAX / 26;

    for (; n > 0; --n) {
        bool prime = true;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                prime = false;
                break;
            }
        }
        if (prime) {
            return n;
        }
    }

    return -1;
}

int main(void) {

    Solution s;
    cout << s.longestPrefix("ababab") << endl;

    // cout << foo() << endl;

    return 0;
}
