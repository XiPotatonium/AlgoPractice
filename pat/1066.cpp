#include <iostream>
#include <queue>

using namespace std;

class AVLNode {
public:
    static int get_height(AVLNode *node) { return node == NULL ? 0 : node->height; }

    AVLNode *left = NULL;
    AVLNode *right = NULL;
    int value;
    int height = 1;

    AVLNode(int val) { value = val; }

    AVLNode *lrotate() {
        AVLNode *new_root = right;
        right = right->left;
        new_root->left = this;
        update_height();
        new_root->update_height();
        return new_root;
    }

    AVLNode *rrotate() {
        AVLNode *new_root = left;
        left = left->right;
        new_root->right = this;
        update_height();
        new_root->update_height();
        return new_root;
    }

    void update_height() {
        int lheight = get_height(left);
        int rheight = get_height(right);

        height = (lheight > rheight ? lheight : rheight) + 1;
    }
};

class AVLTree {
    AVLNode *_insert(AVLNode *cur, int value) {
        if (cur == NULL) {
            return new AVLNode(value);
        }

        if (value < cur->value) {
            cur->left = _insert(cur->left, value);
            cur->update_height();

            if (AVLNode::get_height(cur->left) - AVLNode::get_height(cur->right) > 1) {
                if (AVLNode::get_height(cur->left->left) > AVLNode::get_height(cur->left->right)) {
                    cur = cur->rrotate();
                } else {
                    cur->left = cur->left->lrotate();
                    cur = cur->rrotate();
                }
            }
        } else if (value > cur->value) {
            cur->right = _insert(cur->right, value);
            cur->update_height();

            if (AVLNode::get_height(cur->right) - AVLNode::get_height(cur->left) > 1) {
                if (AVLNode::get_height(cur->right->right) >
                    AVLNode::get_height(cur->right->left)) {
                    cur = cur->lrotate();
                } else {
                    cur->right = cur->right->rrotate();
                    cur = cur->lrotate();
                }
            }
        } else {
        }

        return cur;
    }

public:
    AVLNode *root = NULL;

    void insert(int value) { root = _insert(root, value); }
};

int main(void) {
    int n, x;
    cin >> n;
    AVLTree tree;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        tree.insert(x);
    }

    cout << tree.root->value;

    return 0;
}