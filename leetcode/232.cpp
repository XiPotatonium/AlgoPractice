#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
    stack<int> s1;
    stack<int> s2;

public:
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) { s1.push(x); }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        } else {
            // error
        }

        int ret = s2.top();
        s2.pop();
        return ret;
    }

    /** Get the front element. */
    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        } else {
            // error
        }

        return s2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() { return s1.empty() && s2.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main(void) {
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    cout << queue.peek() << endl;                       // ·µ»Ø 1
    cout << queue.pop() << endl;                        // ·µ»Ø 1
    cout << (queue.empty() ? "true" : "false") << endl; // ·µ»Ø false

    return 0;
}