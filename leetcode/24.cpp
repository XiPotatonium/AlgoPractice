/// ���������е�����
/// �е�ʱ��Ҫ�ƽϵ����ȵݹ���ʲô�ģ�����ݹ�д���������㣬�������ԥ�ݹ�

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