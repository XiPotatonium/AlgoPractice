/// MGJ为什么我模拟的时候超时了？

#include <iostream>
#include <vector>

using namespace std;

class Member {
public:
    int parent;
    vector<int> children;
};

class Solution {
    void _solve(vector<Member> &tree, int root, int depth) {
        if (tree[root].children.size() == 0) {
            if (depth > max_depth) {
                max_depth = depth;
                max_count = 1;
            } else if (depth == max_depth) {
                max_count++;
            }
        }

        for (int i = 0; i < tree[root].children.size(); ++i) {
            _solve(tree, tree[root].children[i], depth + 1);
        }
    }

public:
    int max_depth;
    int max_count;
    void solve(vector<Member> &tree, int root) {
        max_count = 0;
        max_depth = 0;
        _solve(tree, root, 0);
    }
};

int main(void) {
    int n, x, root;
    double p, r;

    cin >> n >> p >> r;
    r /= 100;

    vector<Member> tree(n);

    for (int i = 0; i < n; ++i) {
        cin >> x;
        tree[i].parent = x;
        if (x < 0) {
            root = i;
        } else {
            tree[x].children.push_back(i);
        }
    }

    Solution s;
    s.solve(tree, root);

    for (int i = 0; i < s.max_depth; ++i) {
        p *= (1 + r);
    }

    printf("%.2lf %d", p, s.max_count);

    return 0;
}