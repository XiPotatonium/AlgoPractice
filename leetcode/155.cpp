#include <stack>
#include <vector>

using namespace std;

class MinStack {
    int _min;
    vector<int> _data;

public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        _data.push_back(x);
        if (_data.size() == 1) {
            _min = 0;
        } else if (x < _data[_min]) {
            _min = _data.size() - 1;
        }
    }

    void pop() {
        _data.pop_back();
        if (_data.size() != 0 && _min >= _data.size()) {
            _min = 0;
            for (int i = 1; i < _data.size(); ++i) {
                if (_data[i] < _data[_min]) {
                    _min = i;
                }
            }
        }
    }

    int top() { return *_data.rbegin(); }

    int getMin() { return _data[_min]; }
};