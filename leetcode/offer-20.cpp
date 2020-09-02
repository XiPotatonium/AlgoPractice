// 傻逼题目，需求都不明确我写个🔨

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
    bool is_digit(char ch) { return '0' <= ch && ch <= '9'; }

public:
    /// <summary>
    /// [+-]?[0-9]*(.[0-9]*)?([eE][+-]?[0-9]+)?
    /// </summary>
    /// <param name="s"></param>
    /// <returns></returns>
    bool isNumber(string s) {
        int i = 0;

        for (; i < s.length() && isspace(s[i]); ++i)
            ;
        if (i == s.length()) {
            return false;
        }

        if (s[i] == '+' || s[i] == '-') {
            ++i;
        }

        if (i == s.length()) {
            return false;
        }

        bool has_base = false;
        for (; i < s.length() && is_digit(s[i]); ++i) {
            has_base = true;
        }

        if (s[i] == '.') {
            ++i;
            for (; i < s.length() && is_digit(s[i]); ++i) {
                has_base = true;
            }

            // 排除.
            if (!has_base) {
                return false;
            }
        }
        // 科学计数法之前必须要有数字
        if (has_base && (s[i] == 'e' || s[i] == 'E')) {
            ++i;
            if (s[i] == '+' || s[i] == '-') {
                ++i;
            }
            if (!is_digit(s[i])) {
                return false;
            }
            for (; i < s.length() && is_digit(s[i]); ++i)
                ;
        }

        for (; i < s.length() && isspace(s[i]); ++i)
            ;

        return i == s.length();
    }
};

unordered_map<string, bool> test_cases;

int main(void) {
    test_cases.emplace("1 ", true);
    test_cases.emplace(".1", true);
    test_cases.emplace("e9", false);
    test_cases.emplace("3.", true);
    test_cases.emplace(".", false);

    Solution s;

    for (auto &kv : test_cases) {
        if (s.isNumber(kv.first) != kv.second) {
            printf("%s %s\n", kv.first.c_str(), kv.second ? "true" : "false");
        }
    }

    return 0;
}