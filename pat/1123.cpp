/// ����Ҫ��¼���ڵ㣬������insert�����󷵻��µĸ��ڵ㣬��Ҫ���ݷ���ֵ����
/// ע���ǲ���complete����������ʹ�õ�Ҷ�ӽڵ�֮�����ٳ��ַ�Ҷ�ӽڵ��⣬����һ�ֱȽ�����ķ���
///     ��BFS��ʱ��ͬ����¼�ڵ��index������index��2 * i + 1������indexΪ0�����Һ�����2 * i + 2
///     ��������нڵ��index >= n����˵������complete�������ʵ��complete����ѧ���壩

#include <iostream>
#include <queue>

using namespace std;

class AVLNode {
public:
    /// <summary>
    /// ����Ϊ�˷���NULL�������ע��NULL��height��0���½���AVL�ڵ�height����1
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
        update_height(); // ע����ת��ɺ�Ҫ���¸߶�
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

        if (!cur->left && cur->right) { // ����Ϊ���Һ��Ӳ�Ϊ��
            is_complete = false;
        }
        if (leaf_met && (cur->left || cur->right)) { // Ҷ�ڵ�֮����Ȼ�����з�Ҷ�ӽڵ�
            is_complete = false;
        }
        if (!cur->right) { // ���Ҷ��ǿջ����Һ���Ϊ��
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
