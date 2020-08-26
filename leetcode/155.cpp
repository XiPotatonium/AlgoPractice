/// 最小栈，没什么意思

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class MinStack {
private:
    vector<int> _data;
    int _min = -1;

public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        _data.push_back(x);
        if (_data.size() == 1) {
            _min = x;
        } else if (x < _min) {
            _min = x;
        }
    }

    void pop() {
        _data.erase(_data.end() - 1);
        if (_data.size() > 0) {
            _min = _data[0];
            for (int i = 1; i < _data.size(); ++i) {
                if (_data[i] < _min) {
                    _min = _data[i];
                }
            }
        }
    }

    int top() { return *_data.rbegin(); }

    int getMin() { return _min; }
};

int main(void) {

    MinStack minStack;

    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.top() << endl;
    cout << minStack.getMin() << endl;

    return 0;
}