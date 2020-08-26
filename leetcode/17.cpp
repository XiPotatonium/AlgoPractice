// µÝ¹é£¬Êý×éÊ÷×´±éÀú

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<char>> table = {{'a', 'b', 'c'}, {'d', 'e', 'f'},      {'g', 'h', 'i'}, {'j', 'k', 'l'},
                                  {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};

    vector<string> res;
    char *tmp;

    void find(string &digits, int cur_idx) {
        if (cur_idx == digits.length()) {
            tmp[cur_idx] = 0;
            res.push_back(string(tmp));
            return;
        }

        int table_idx = digits[cur_idx] - '2';
        for (char ch : table[table_idx]) {
            tmp[cur_idx] = ch;
            find(digits, cur_idx + 1);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
            return {};
        }

        tmp = new char[digits.length() + 1];

        find(digits, 0);

        delete[] tmp;
        return res;
    }
};

int main(void) {
    Solution s;

    vector<string> vs = s.letterCombinations("23");
    for (string &s : vs) {
        cout << s << endl;
    }

    return 0;
}