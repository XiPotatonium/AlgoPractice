#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class LLNode {
public:
    int addr;
    int data;
    int next_addr;
    LLNode *next;
};

int main(void) {
    int start_addr, n, k;
    cin >> start_addr >> n >> k;

    unordered_map<int, int> table;
    vector<LLNode> nodes(n);

    if (start_addr < 0 || n == 0) {
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        cin >> nodes[i].addr >> nodes[i].data >> nodes[i].next_addr;
        table.emplace(nodes[i].addr, i);
    }

    for (int i = 0; i < n; ++i) {
        if (nodes[i].next_addr < 0) {
            nodes[i].next = NULL;
        } else {
            auto iter = table.find(nodes[i].next_addr);
            if (iter != table.end()) {
                nodes[i].next = &nodes[iter->second];
            } else {
                nodes[i].next =
                    NULL; // 这个其实不在链表上，但是要区分，不然段错误
            }
        }
    }

    LLNode *start = &nodes[table.find(start_addr)->second];
    LLNode *new_start = NULL;

    while (start != NULL) {
        LLNode *cur = start;
        for (int i = 0; i < k - 1; ++i) {
            if (cur->next != NULL) {
                cur = cur->next;
            } else {
                break;
            }
        }
        LLNode *tmp = start;
        start = cur->next;
        cur->next = new_start;
        new_start = tmp;
    }

    LLNode *cur = new_start;
    while (cur != NULL) {
        printf("%05d %d", cur->addr, cur->data);
        if (cur->next) {
            printf(" %05d\n", cur->next->addr);
        } else {
            printf(" -1\n");
        }
        cur = cur->next;
    }

    return 0;
}