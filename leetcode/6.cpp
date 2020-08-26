/// Z字形
/// 记得有只有一行这个边界条件

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        char* str = new char[s.length() + 1];
        strcpy(str, s.c_str());
        int loop = 2 * (numRows - 1);
        int i = 0;
        for (int r = 0; r < numRows; ++r) {
            for (int j = r; j < s.length(); ) {
                str[i++] = s[j];
                if (r == 0 || r == numRows - 1) {
                    j += loop;
                }
                else {
                    j += loop - 2 * r;
                    if (j < s.length()) {
                        str[i++] = s[j];
                        j += 2 * r;
                    }
                }
            }
        }

        string ret(str);
        delete[] str;

        return ret;
    }
};

int main(void) {
    Solution solution;

    cout << solution.convert("A", 1);

    return 0;
}