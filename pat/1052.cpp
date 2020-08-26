/// 这题目要求讲得也太不清楚了
/// 首先给的链表节点可能不是本链表里的
/// 其次链表可能是空的

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct LinkedListNode {
    int addr;
    int key;
    int next;
    bool in_ll = false;
};

bool pred(const LinkedListNode &a, const LinkedListNode &b) {
    return a.key < b.key;
}

int main(void) {
    int n, addr, next, start_addr;
    int key;

    scanf("%d %d", &n, &start_addr);

    vector<LinkedListNode> ll(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &addr, &key, &next);
        ll[i].addr = addr;
        ll[i].key = key;
        ll[i].next = next;
    }

    sort(ll.begin(), ll.end(), pred);

    unordered_map<int, LinkedListNode *> table;

    for (auto iter = ll.begin(); iter != ll.end(); ++iter) {
        table.emplace(iter->addr, &(*iter));
    }

    if (start_addr < 0) { // mgj
        printf("0 -1\n", n);
        return 0;
    }

    n = 0;
    auto ti = table.find(start_addr);
    while (1) {
        ++n;
        ti->second->in_ll = true;
        if (ti->second->next < 0) {
            break;
        }
        ti = table.find(ti->second->next);
    }

    auto iter = ll.begin();
    while (iter != ll.end() && !(iter->in_ll)) {
        ++iter;
    }

    printf("%d %05d\n", n, iter->addr);

    while (1) {
        printf("%05d %d", iter->addr, iter->key);
        ++iter;
        while (iter != ll.end() && !(iter->in_ll)) {
            ++iter;
        }
        if (iter != ll.end()) {
            printf(" %05d\n", iter->addr);
        } else {
            printf(" -1\n");
            break;
        }
    }

    return 0;
}