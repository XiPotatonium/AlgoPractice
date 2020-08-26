/// 交换链表中的数对
/// 有的时候不要计较迭代比递归慢什么的，如果递归写起来更方便，请毫不犹豫递归

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (!head) {
            return NULL;
        } else if (!head->next) {
            return head;
        }

        ListNode *ret = head->next;
        head->next = swapPairs(ret->next);
        ret->next = head;
        return ret;
    }
};

int main(void) {
    Solution solution;

    vector<int> nums({1, 1, 2, 1, 1});

    cout << solution.numberOfSubarrays(nums, 3);

    return 0;
}