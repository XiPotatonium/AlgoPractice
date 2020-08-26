/// 合并 k 个排序链表，返回合并后的排序链表
/// 偷懒了直接用STL，不然要手搓优先队列的

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct ListNodeMinheapPred {
    bool operator()(const ListNode *a, const ListNode *b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, ListNodeMinheapPred>
            heap;
        for (vector<ListNode *>::iterator iter = lists.begin();
             iter != lists.end(); ++iter) {
            if (*iter != NULL) {
                heap.push(*iter);
            }
        }
        ListNode *ret = NULL;
        ListNode *cur = NULL;
        while (!heap.empty()) {
            ListNode *n = heap.top();
            heap.pop();
            if (!ret && !cur) {
                cur = ret = n;
            } else {
                cur->next = n;
                cur = n;
            }
            if (n->next) {
                heap.push(n->next);
                n->next = NULL;
            }
        }

        return ret;
    }
};

int main(void) {
    Solution solution;

    vector<ListNode *> lists(3);

    vector<vector<int>> res = solution.permute(arr);
    for (vector<vector<int>>::iterator row = res.begin(); row != res.end();
         ++row) {
        for (vector<int>::iterator iter = row->begin(); iter != row->end();
             ++iter) {
            cout << *iter << " ";
        }
        cout << endl;
    }

    return 0;
}