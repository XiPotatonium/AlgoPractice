/// 不需要记录父节点，而是在insert结束后返回新的根节点，需要依据返回值更新
/// 注：是不是complete，除了这里使用的叶子节点之后不能再出现非叶子节点外，还有一种比较奇妙的方法
///     在BFS的时候同步记录节点的index，左孩子index是2 * i + 1（根的index为0），右孩子是2 * i + 2
///     如果发现有节点的index >= n，就说明不是complete（这个其实是complete的数学定义）

#include <iostream>
#include <queue>

using namespace std;

class AVLNode {
public:
    /// <summary>
    /// 这是为了方便NULL的情况，注意NULL的height是0，新建的AVL节点height就是1
    /// </summary>
    /// <param name="node"></param>
    /// <returns></returns>
    static int get_height(AVLNode *node) {
        if (node == NULL) {
            return 0;
        } else {
            return node->height;
        }
    }

    AVLNode *left = NULL;
    AVLNode *right = NULL;
    int value;
    int height = 1;

    AVLNode(int v) { value = v; }

    void update_height() {
        int left_h = get_height(left);
        int right_h = get_height(right);
        height = (left_h > right_h ? left_h : right_h) + 1;
    }

    AVLNode *lrotate() {
        AVLNode *new_root = right;
        right = right->left;
        new_root->left = this;
        update_height(); // 注意旋转完成后要更新高度
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
                    // ll insertion
                    cur = cur->rrotate();
                } else {
                    // lr insetion
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
            // throw
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

    queue<AVLNode *> q;
    q.push(tree.root);
    bool is_complete = true;
    bool leaf_met = false;

    while (!q.empty()) {
        AVLNode *cur = q.front();
        q.pop();

        if (cur->left) {
            q.push(cur->left);
        }
        if (cur->right) {
            q.push(cur->right);
        }

        if (!cur->left && cur->right) { // 左孩子为空右孩子不为空
            is_complete = false;
        }
        if (leaf_met && (cur->left || cur->right)) { // 叶节点之后依然发现有非叶子节点
            is_complete = false;
        }
        if (!cur->right) { // 左右都是空或者右孩子为空
            leaf_met = true;
        }

        if (cur != tree.root) {
            cout << " ";
        }
        cout << cur->value;
    }

    cout << endl << (is_complete ? "YES" : "NO");

    return 0;
}
