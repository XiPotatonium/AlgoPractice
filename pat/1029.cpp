/// �����������λ��
/// ������Ŀ���и�Ч�ⷨ�ģ����ǽ�����ʵ��һ�����ط����������ܹ����ֵ㣬������Ϊ�ο�
/// ��Ч�ⷨ�ƺ��Ǿ�������ģ�Advance����������
/// �������в��ֵ㳬ʱ�ģ������ֶ��Ż�ǰ����
/// ע�⣬��ʹ�����ؽⷨ�������кܶ�߽�����Ҫ���ǣ����׵��´��ֵ�


#include <iostream>
#include <vector>

using namespace std;

// vector���ε�ʱ���ǻ�ֱ�Ӹ��Ƶģ��ǵô�����
long int trival_median(vector<long int>& array0, vector<long int>& array1) {
    int i0 = 0, i1 = 0;
    int mid = (array0.size() + array1.size() + 1) / 2;
    long int ret;
    int count = 0;
    // �ǲ�����Ҫ�ȿ���array0��array1����СԪ�أ���֤array0����СԪ�ر�array1����СԪ��С
    // ����޷���֤�������㷨��������⣬����������ǣ���Ȼ����
    // �������صģ�һ��һ���ȹ�ȥ
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
            // �������±����Ʋ�������Ҫôֱ��whileѭ��������ͺ���
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