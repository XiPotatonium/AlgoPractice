/// 判断一个树是否是另一棵树的子树
/// 最绝的是可以做子串匹配来解这个问题

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSubtree(TreeNode *s, TreeNode *t) {
        if (!s) {
            return false;
        }
        if (isSame(s, t)) {
            return true;
        }
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }

    bool isSame(TreeNode *s, TreeNode *t) {
        if (!t && !s) {
            return true;
        }
        if (!t || !s) {
            return false;
        }
        return s->val == t->val && isSame(s->left, t->left) &&
               isSame(s->right, t->right);
    }
};

int main(void) {
    Solution solution;

    vector<int> days({1, 4, 6, 7, 8, 20});
    vector<int> costs({7, 2, 15});

    cout << solution.mincostTickets(days, costs) << endl;

    return 0;
}