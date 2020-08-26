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
        ListNode *ret = head;
        ListNode *tail = head;
        for (int i = 0; i < k - 1 && tail; ++i) {
            tail = tail->next;
        }
        ListNode *pred = NULL;
        while (tail != NULL) {
            // 交换
            if (pred) {
                pred->next = tail;
            } else {
                ret = tail;
            }
            pred = head;
            ListNode *tmp = head;
            head = head->next;
            tmp->next = tail->next;
            while (tmp != tail) {
                ListNode *tmp1 = head;
                head = head->next;
                tmp1->next = tmp;
                tmp = tmp1;
            }

            //
            head = tail = pred->next;
            for (int i = 0; i < k - 1 && tail; ++i) {
                tail = tail->next;
            }
        }
        return ret;
    }
};

int main(void) {

    Solution s;
    vector<int> v = {1, 1, 1};

    cout << s.subarraySum(v, 2) << endl;

    return 0;
}