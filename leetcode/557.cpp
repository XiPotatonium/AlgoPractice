#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> arr;

        stringstream ss(s);

        while (!ss.eof()) {
            ss >> s;
            reverse(s.begin(), s.end());
            arr.emplace_back(std::move(s));
        }

        for (auto iter = arr.cbegin(); iter != arr.cend(); ++iter) {
            if (iter != arr.cbegin()) {
                s += ' ';
            }
            s += *iter;
        }

        return s;
    }
};

int main(void) {

    Solution s;
    cout << s.reverseWords("Let's take LeetCode contest") << endl;

    return 0;
}
