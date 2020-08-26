/// 判断二叉搜索树
/// 记得二叉搜索树是有范围的，要判断max，min

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
    bool isValidBST(TreeNode *root) {
        return root ? _isValidBST(root, INT32_MIN, INT32_MAX) : true;
    }

    bool _isValidBST(TreeNode *root, int min, int max) {
        if (root->val < min || root->val > max) {
            return false;
        }
        if (root->left && (root->left->val >= root->val ||
                           !_isValidBST(root->left, min, root->val - 1))) {
            return false;
        }
        if (root->right && (root->right->val <= root->val ||
                            !_isValidBST(root->right, root->val + 1, max))) {
            return false;
        }
        return true;
    }
};

int main(void) {
    Solution solution;

    cout << solution.myAtoi("42") << endl;
    cout << solution.myAtoi("   -42") << endl;
    cout << solution.myAtoi("4193 with words") << endl;
    cout << solution.myAtoi("words and 987") << endl;
    cout << solution.myAtoi("-91283472332") << endl;

    return 0;
}