#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode pseudo(-1);
        pseudo.next = head;
        ListNode *p1, *p2;
        p1 = &pseudo;
        p2 = head;
        for (int i = 0; i < n; ++i) {
            p2 = p2->next;
        }

        while (p2 != NULL) {
            p1 = p1->next;
            p2 = p2->next;
        }

        p1->next = p1->next->next;
        return pseudo.next;
    }
};

int main(void) {

    Solution s;
    s.removeNthFromEnd();

    return 0;
}