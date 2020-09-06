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
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> ret;
        if (root == nullptr) {
            return ret;
        }

        queue<TreeNode *> q;
        q.push(root);
        TreeNode *tail = root;
        ret.push_back(vector<int>());

        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();

            ret.rbegin()->push_back(cur->val);

            if (cur->left != nullptr) {
                q.push(cur->left);
            }
            if (cur->right != nullptr) {
                q.push(cur->right);
            }

            if (cur == tail && !q.empty()) {
                tail = q.back();
                ret.push_back(vector<int>());
            }
        }

        reverse(ret.begin(), ret.end());

        return ret;
    }
};

int main(void) { return 0; }