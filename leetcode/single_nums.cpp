/// һ����������������ֻ������һ�Σ����������������Σ��ҳ�����������Ҫ��ʱ��O(N)���ռ�O(1)
/// �ռ�O(1)����������������
/// һ�������˼·�������������ൽŶ����Ͱ�У��е��ϣ�ĸо�����Ҫ��
/// 1. ͬ��������ͬ����Ͱ������Ȼ��ͨ��λpattern�����ࣩ
/// 2. ����ֻ������һ�ε����ڲ�ͬ��Ͱ������һ�����Ľ�����Ը������ṩ������������Щλ�ϻ��в��죩

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int> &nums) {
        vector<int> ret(2);
        int sum = 0;
        for (vector<int>::iterator iter = nums.begin(); iter != nums.end();
             ++iter) {
            sum ^= *iter;
        }

        int mask = 1;
        for (mask = 1;; mask = mask << 1) {
            if ((sum & mask) != 0) {
                // ��һλ����������ȵ�����ͬ
                break;
            }
        }

        ret[0] = ret[1] = 0;
        for (vector<int>::iterator iter = nums.begin(); iter != nums.end();
             ++iter) {
            if ((*iter & mask) == 0) {
                ret[0] ^= *iter;
            } else {
                ret[1] ^= *iter;
            }
        }

        return ret;
    }
};

int main(void) {
    Solution solution;

    vector<int> list = {4, 1, 4, 6};
    vector<int> ret;
    ret = solution.singleNumbers(list);

    for (vector<int>::iterator iter = ret.begin(); iter != ret.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}