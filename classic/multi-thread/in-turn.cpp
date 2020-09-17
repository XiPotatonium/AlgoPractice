#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

mutex mut;
condition_variable condv;
int done_cnt;
int value = 0;

int ft1() {
    unique_lock<mutex> ulock(mut);      // ���Զ�����
    for (int i = 0; i < 10; ++i) {
        cout << "t1: " << value++ << endl;
        condv.notify_all();             // �����ֹ������������Ա��notify_one
        if (done_cnt == 0) {
            condv.wait(ulock);          // �ȴ��������̻߳���
        }
    }
    done_cnt++;
    condv.notify_all();                 // �ǵ���һ���߳̿��ܻ��ǿ��ŵ�
    return 0;
}

int ft2() {
    unique_lock<mutex> ulock(mut);
    for (int i = 0; i < 10; ++i) {
        cout << "t2: " << value << endl;
        condv.notify_all();
        if (done_cnt == 0) {
            condv.wait(ulock);
        }
    }
    done_cnt++;
    condv.notify_all();
    return 0;
}

int main(void) {
    done_cnt = 0;
    thread t1(ft1);
    thread t2(ft2);
    t1.join();
    t2.join();

    return 0;
}