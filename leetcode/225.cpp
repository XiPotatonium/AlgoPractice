#include <iostream>
#include <queue>

using namespace std;

class MyStack {
    queue<int> q;

public:
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) { q.push(x); }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int n = q.size();
        for (int i = 0; i < n - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
        int ret = q.front();
        q.pop();
        return ret;
    }

    /** Get the top element. */
    int top() { return q.back(); }

    /** Returns whether the stack is empty. */
    bool empty() { return q.empty(); }
};

int main(void) { return 0; }