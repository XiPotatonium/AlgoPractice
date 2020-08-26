#include <iostream>
#include <vector>

using namespace std;

class Demo {
public:
    bool aha;
    int v;
    Demo *p;
};

void foo(int i) {
    if (i >= 100) {
        return;
    }
    Demo a;
    a.p = new Demo();
    foo(i + 1);
    cout << a.aha << " " << a.v << endl;
    cout << a.p->aha << " " << a.p->v << " " << a.p->p << endl;
}

int main(void) { 
    foo(0);

	return 0; 
}


