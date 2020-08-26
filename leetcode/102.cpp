/// 二叉树层序遍历，我怎么感觉好像哪里做过

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
    vector<vector<int>> levelOrder(TreeNode *root) {
        queue<TreeNode *> q;
        vector<vector<int>> ret;
        if (root == NULL) {
            return ret;
        }
        ret.emplace_back(vector<int>());
        q.push(root);
        TreeNode *tail = root;
        while (!q.empty()) {
            TreeNode *front = q.front();
            if (front->left) {
                q.push(front->left);
            }
            if (front->right) {
                q.push(front->right);
            }
            q.pop();
            ret[ret.size() - 1].push_back(front->val);
            if (front == tail) {
                tail = q.back();
                if (!q.empty()) {
                    ret.emplace_back(vector<int>());
                }
            }
        }
        return ret;
    }
};

int main(void) {

    MinStack minStack;

    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.top() << endl;
    cout << minStack.getMin() << endl;

    return 0;
}