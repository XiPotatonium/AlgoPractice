#include <iostream>
#include <vector>

using namespace std;

class AVLNode {
public:
    /// <summary>
    /// 这是为了方便NULL的情况
    /// </summary>
    /// <param name="n"></param>
    /// <returns></returns>
    static int get_height(AVLNode *n) {
        if (n == NULL) {
            return 0;
        }
        return n->height;
    }

    AVLNode *left;
    AVLNode *right;
    int value;
    int height;

    AVLNode(int value) : value(value) {}

    void update_height() {
        int lheight = get_height(left);
        int rheight = get_height(right);
        return lheight > rheight ? height + 1 : rheight + 1;
    }

    /// <summary>
    /// 因为不在AVLNode中记录父节点，所以旋转之后通过返回值更新根结点
    /// </summary>
    /// <returns></returns>
    AVLNode* lrotate() { 
        AVLNode *newroot = right;
        right = newroot->left;
        newroot->left = this;
        update_height();
        newroot->update_height();
        return newroot;
    }

    AVLNode* rrotate() { 
        AVLNode *newroot = left;
        left = newroot->right;
        newroot->right = this;
        update_height();
        newroot->update_height();
        return newroot;
    }
};

class AVLTree {
    AVLNode *_insert(AVLNode *root, int value) {
        if (root == NULL) {
            return new AVLNode(value);
        }

        if (value < root->value) {
            root->left = _insert(root->left, value);
            root->update_height();

            if (AVLNode::get_height(root->left) - AVLNode::get_height(root->right) > 1) {
                if (AVLNode::get_height(root->left->left) > AVLNode::get_height(root->left->right)) {
                    // ll insertion
                    root = root->rrotate();
                } else {
                    // lr insertion
                    root->left = root->left->lrotate();
                    root = root->rrotate();
                }
            }
        } else if (value == root->value) {
            // 不会进入到这里
        } else {
            if (AVLNode::get_height(root->right->right) > AVLNode::get_height(root->right->left)) {
                // rr insertion
                root = root->lrotate();
            } else {
                // rl insertion
                root->right = root->right->rrotate();
                root = root->lrotate();
            }
        }

        return root;
    }

public:
    AVLNode *root;

    void insert(int value) {
        root = _insert(root, value);
    }
};

int main(void) {
    int n, x;
    cin >> n;

    AVLTree tree;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        tree.insert(x);
    }

	return 0;
}