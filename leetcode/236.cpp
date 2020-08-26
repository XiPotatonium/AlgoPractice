/// 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

/// 百度百科中最近公共祖先的定义为：
/// “对于有根树 T 的两个结点p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x的深度尽可能大（一个节点也可以是它自己的祖先）。”

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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        bool hasp = false, hasq = false;
        return _lowestCommonAncestor(root, p, q, &hasp, &hasq);
    }

    TreeNode *_lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q,
                                    bool *phasp, bool *phasq) {
        bool hasp = root == p, hasq = root == q;
        TreeNode *res = NULL;
        if (root->left) {
            res = _lowestCommonAncestor(root->left, p, q, &hasp, &hasq);
            if (res != NULL) {
                return res;
            }
        }
        if (root->right) {
            res = _lowestCommonAncestor(root->right, p, q, &hasp, &hasq);
            if (res != NULL) {
                return res;
            }
        }
        if (hasp && hasq) {
            return root;
        }
        if (!*phasp) {
            *phasp = hasp;
        }
        if (!*phasq) {
            *phasq = hasq;
        }
        return NULL;
    }
};

int main(void) {
    Solution solution;

    cout << solution.mySqrt(23) << endl;
    cout << solution.mySqrt(2) << endl;
    cout << solution.mySqrt(4) << endl;
    cout << solution.mySqrt(8) << endl;
    cout << solution.mySqrt(16) << endl;
    cout << solution.mySqrt(0) << endl;
    cout << solution.mySqrt(5) << endl;

    return 0;
}