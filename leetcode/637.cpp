#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }

        vector<double> ret;
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *tail = root;
        double sum = 0;
        int cnt = 0;

        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            ++cnt;
            sum += cur->val;

            if (cur->left) {
                q.push(cur->left);
            }
            if (cur->right) {
                q.push(cur->right);
            }

            if (cur == tail) {
                ret.push_back(sum / cnt);
                sum = cnt = 0;
                if (!q.empty()) {
                    tail = q.back();
                }
            }
        }

        return ret;
    }
};

int main(void) {
    Solution s;
    s.isValid("()");

    return 0;
}