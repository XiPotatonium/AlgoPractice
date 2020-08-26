/// 编写一个算法来判断一个数 n 是不是快乐数。
/// 快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为
/// 1，也可能是 无限循环 但始终变不到 1。如果 可以变为 
/// 1，那么这个数就是快乐数。 如果 n 是快乐数就返回 True ；不是，则返回 False 。

/// 多次debug后发现神秘数字是4，密码学的直觉表明一定有循环
/// 快慢指针？

/// 1. 最终会得到1.
/// 2. 最终会进入循环。
/// 3.
/// 值会越来越大，最后接近无穷大。这不会发生分析999就知道数字会被困在三位数以下。

/// 快慢指针。快指针一次走两步，慢指针一次走一步，这样在环路中一定能相遇。

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int num = n;
        while (num != 1) {
            int temp = 0;
            while (num != 0) {
                temp += (num % 10) * (num % 10);
                num /= 10;
            }
            num = temp;
            if (num == 4) {
                return false;
            }
        }

        return num == 1;
    }
};

int main(void) {
    Solution solution;

    cout << solution.isHappy(19);

    return 0;
}