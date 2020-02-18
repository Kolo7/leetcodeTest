#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class A {
public:
    explicit A() {
        std::cout << "default" << endl;
    };
    A(const A& a) {
        std::cout << "copy" << endl;
        this->a = a.a;
    }

    const A& operator=(const A& a) {
        std::cout << "operatior=" << endl;
        this->a = a.a;
        return a;
    }
private:
    int a;
};

void  func(A a) {
    return;
}

int main()
{
    A a;
    A b = a;
    A c(a);
    c = b;
    func(a);
    return 0;
}