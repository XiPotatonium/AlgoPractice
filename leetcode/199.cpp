/// 从右侧看二叉树
/// 层序遍历，并且要识别层的开头和末尾

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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ret;
        if (!root) {
            return ret;
        }
        queue<TreeNode *> q;
        q.emplace(root);
        while (!q.empty()) {
            ret.push_back(q.front()->val);
            TreeNode *back = q.back();
            while (true) {
                TreeNode *front = q.front();
                if (front->right) {
                    q.emplace(front->right);
                }
                if (front->left) {
                    q.emplace(front->left);
                }
                q.pop();
                if (front == back) {
                    break;
                }
            }
        }

        return ret;
    }
};

int main(void) {
    Solution solution;

    vector<int> nums({1, 1, 2, 1, 1});

    cout << solution.numberOfSubarrays(nums, 3);

    return 0;
}