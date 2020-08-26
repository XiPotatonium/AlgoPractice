/// 两个数组的中位数
/// 这种题目是有高效解法的，但是建议先实现一个朴素方法，至少能过部分点，还能作为参考
/// 高效解法似乎是竞赛级别的，Advance基本不考察
/// 如果真的有部分点超时的，尝试手动优化前几步
/// 注意，即使是朴素解法，还是有很多边界条件要考虑，容易导致错部分点


#include <iostream>
#include <vector>

using namespace std;

// vector传参的时候是会直接复制的，记得传引用
long int trival_median(vector<long int>& array0, vector<long int>& array1) {
    int i0 = 0, i1 = 0;
    int mid = (array0.size() + array1.size() + 1) / 2;
    long int ret;
    int count = 0;
    // 是不是需要先考察array0和array1的最小元素，保证array0的最小元素比array1的最小元素小
    // 如果无法保证，下面算法会存在问题，但是奇葩的是，居然过了
    // 就是朴素的，一个一个比过去
    for (; count < mid && i0 < array0.size() && i1 < array1.size(); ++i0, ++count) {
        ret = array0[i0];
        while (i1 < array1.size() && array1[i1] < array0[i0] && count < mid) {
            ret = array1[i1];
            ++i1;
            ++count;
        }
    }
    if (count < mid) {
        if (i0 < array0.size()) {
            // 如果这个下标手推不出来，要么直接while循环到那里就好了
            ret = array0[i0 + mid - count - 1];
        }
        else {
            ret = array1[i1 + mid - count - 1];
        }
    }
    return ret;
}

int main(void) {
    vector<long int> array0, array1;
    int n;
    long int v;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%ld", &v);
        array0.push_back(v);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%ld", &v);
        array1.push_back(v);
    }

    printf("%ld\n", trival_median(array0, array1));
    return 0;
}