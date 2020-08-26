/// 前序和中序还原二叉树
/// 前提是没有重复元素

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
private:
    vector<int> *ppre;
    int ipre;

    TreeNode *_buildTree(vector<int> &inorder, int l, int h) {
        if (l > h) {
            return NULL;
        }
        int mid = 0;
        for (mid = 0; mid < inorder.size(); ++mid) {
            if (inorder[mid] == (*ppre)[ipre]) {
                break;
            }
        }
        TreeNode *node = new TreeNode((*ppre)[ipre]);
        ipre++;
        node->left = _buildTree(inorder, l, mid - 1);
        node->right = _buildTree(inorder, mid + 1, h);
        return node;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        ppre = &preorder;
        ipre = 0;
        return _buildTree(inorder, 0, inorder.size() - 1);
    }
};

int main(void) {

    Solution s;
    vector<vector<int>> v = {{1, 0}};

    cout << s.findTheLongestSubstring("leetcodeisgreat") << endl;

    return 0;
}