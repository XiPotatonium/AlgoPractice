#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<vector<int>> _ans;

    void _binaryTreePaths(TreeNode *root, vector<int> &path) {
        path.emplace_back(root->val);

        if (root->left == NULL && root->right == NULL) {
            _ans.emplace_back(path);
        } else {
            if (root->left) {
                _binaryTreePaths(root->left, path);
            }

            if (root->right) {
                _binaryTreePaths(root->right, path);
            }
        }

        path.pop_back();
    }

public:
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> ret;

        if (root == NULL) {
            return ret;
        }
        vector<int> tmp;
        _binaryTreePaths(root, tmp);

        for (auto &i : _ans) {
            stringstream ss;
            for (int j = 0; j < i.size(); ++j) {
                if (j != 0) {
                    ss << "->";
                }
                ss << i[j];
            }
            ret.emplace_back(ss.str());
        }

        return ret;
    }
};