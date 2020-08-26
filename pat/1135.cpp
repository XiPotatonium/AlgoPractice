/// 阅读理解，没什么好说的

#include <iostream>
#include <memory>

using namespace std;

static int s_bh;

class RBNode {
public:
    int m_v;
    bool m_isr;
    shared_ptr<RBNode> left;
    shared_ptr<RBNode> right;

    RBNode(int v, bool isr) {
        m_v = v;
        m_isr = isr;
        left = right = nullptr;
    }
};

shared_ptr<RBNode> add_to_searchtree(shared_ptr<RBNode> root, int v, bool isr) {
    if (root == nullptr) {
        return shared_ptr<RBNode>(new RBNode(v, isr));
    }
    if (v < root->m_v) {
        root->left = add_to_searchtree(root->left, v, isr);
    }
    else {
        root->right = add_to_searchtree(root->right, v, isr);
    }
    return root;
}

bool rec_check_rbtree(shared_ptr<RBNode> root, int bh) {
    if (root == nullptr) {
        if (s_bh < 0) {
            s_bh = bh;
        }
        return s_bh == bh;
    }
    if (root->m_isr) {
        // red的孩子是black
        if (root->left != nullptr && root->left->m_isr) {
            return false;
        }
        if (root->right != nullptr && root->right->m_isr) {
            return false;
        }
    }
    else {
        bh += 1;
    }
    return rec_check_rbtree(root->left, bh) && rec_check_rbtree(root->right, bh);
}

bool check_rbtree(shared_ptr<RBNode> root) {
    if (root->m_isr) {
        return false;
    }
    s_bh = -1;
    return rec_check_rbtree(root, 0);
}

int main(void) {
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        int n, v;
        scanf("%d", &n);
        shared_ptr<RBNode> root;
        for (int j = 0; j < n; ++j) {
            scanf("%d", &v);
            root = add_to_searchtree(root, v < 0 ? -v : v, v < 0);
        }
        printf("%s\n", check_rbtree(root) ? "Yes" : "No");
    }
}