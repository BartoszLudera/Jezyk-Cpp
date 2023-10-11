#include <iostream>
using namespace std;

class A
{
public:
    void f() { cout << "arbuz" << endl; };
};

class SmartPrt
{
    A *ptr{nullptr};

public:
    SmartPrt(A *prt = nullptr) : ptr(prt) {}
    A *operator->() { return ptr; }
    A &operator*() { return *(operator->()); }
};

int main()
{
    A arbuz;
    SmartPrt pointer = &arbuz;
    pointer->f();
    (*pointer).f();
}