#include <iostream>
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<TreeNode *> stack;
        vector<int> ret;

        while (root != NULL || !stack.empty()) {
            if (root == NULL) {
                root = stack.back();
                stack.pop_back();
                ret.push_back(root->val);
                root = root->right;
            } else {
                stack.push_back(root);
                root = root->left;
            }
        }

        return ret;
    }
};

int main(void) {

    Solution s;

    auto vs = s.generateParenthesis(3);

    for (auto &v : vs) {
        cout << v << endl;
    }

    return 0;
}