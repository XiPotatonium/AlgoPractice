/// K个一组翻转数组
/// 这也能叫困难？

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == NULL) {
            return NULL;
        }

        ListNode *tail = head;
        for (int i = 0; i < k - 1 && tail != NULL; ++i) {
            tail = tail->next;
        }

        if (tail == NULL) {
            return head; // 如果剩下的小于K，保持原序
        }

        ListNode *cur = head, *next, *prev = NULL;
        while (prev != tail) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            if (next != NULL) {
                next = next->next;
            }
        }

        head->next = reverseKGroup(cur, k);
        return tail;
    }
};

int main(void) {
    ListNode *root = new ListNode(1);
    ListNode *cur = root;
    cur->next = new ListNode(2);
    cur = cur->next;
    cur->next = new ListNode(3);
    cur = cur->next;
    cur->next = new ListNode(4);
    cur = cur->next;
    cur->next = new ListNode(5);
    cur = cur->next;

    Solution s;
    ListNode *res = s.reverseKGroup(root, 1);

    while (res != NULL) {
        cout << res->val << ' ';
        res = res->next;
    }

    return 0;
}