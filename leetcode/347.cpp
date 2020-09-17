#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
    int num;
    int freq;

    Node(int n, int f) : num(n), freq(f) {}

    bool operator<(const Node &b) const { return freq > b.freq; }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> m;
        int f;
        for (auto i : nums) {
            ++m[i];
        }

        vector<Node> tmp;
        for (auto &i : m) {
            tmp.emplace_back(i.first, i.second);
        }

        sort(tmp.begin(), tmp.end());

        vector<int> ret;
        for (int i = 0; i < k; ++i) {
            ret.emplace_back(tmp[i].num);
        }

        return ret;
    }
};

int main(void) {

    vector<int> vec = {1, 1, 1, 2, 2, 3};

    Solution s;
    auto res = s.topKFrequent(vec, 2);

    for (int i : res) {
        cout << i << " ";
    }

    return 0;
}