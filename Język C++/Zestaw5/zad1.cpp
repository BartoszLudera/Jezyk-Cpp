#include <iostream>
using namespace std;

#define P(x) std::cout << x << std::endl

class A1
{
private:
    int i{5};

public:
    A1() = default;
    A1(bool) { P("A1 c-tor"); }
    virtual ~A1() { P("A1 d-tor"); }
    int get() const { return i; }
};

class V1 : virtual public A1
{
public:
    V1() = default;
    V1(bool) : A1(true) { P("V1 c-tor"); }
    virtual ~V1() override { P("V1 d-tor"); }
};

class C1 : virtual public V1
{
public:
    C1() = default;
    C1(bool) : V1(true) { P("C1 c-tor"); }
    virtual ~C1() override { P("C1 d-tor"); }
};

class B2
{
private:
    int i{5};

public:
    B2() = default;
    B2(bool) { P("B2 c-tor"); }
    ~B2() { P("B2 d-tor"); }
    int get() const { return i; }
};

class B3
{
private:
    int i{5};

public:
    B3() = default;
    B3(bool) { P("B3 c-tor"); }
    ~B3() { P("B3 d-tor"); }
    int get() const { return i; }
};

///////////////////////////////////////////////
class V2 : virtual public A1, public B2
{
public:
    V2() = default;
    V2(bool) : A1(true) { P("V2 c-tor"); }
    virtual ~V2() override { P("V2 d-tor"); }
};

class C2 : virtual public V2, public B3
{
public:
    C2() = default;
    C2(bool) : V2(true) { P("C2 c-tor"); }
    virtual ~C2() override { P("C2 d-tor"); }
};

class M1
{
private:
    int i{5};

public:
    M1() = default;
    M1(bool) { P("M1 c-tor"); }
    ~M1() { P("M1 d-tor"); }
    int get() const { return i; }
};

class M2
{
private:
    int i{5};

public:
    M2() = default;
    M2(bool) { P("M2 c-tor"); }
    ~M2() { P("M2 d-tor"); }
    int get() const { return i; }
};

class X : public C1, public C2
{
    M1 m1;
    M2 m2;

public:
    X() = default;
    X(bool) { P("X2 c-tor"); }
    ~X()
    {
        P("M2 d-tor");
    }
};

int main()
{
    A1 *pa = new X;
    cout << pa->get() << endl; // zakomentować gdy public A1
    delete pa;
}
