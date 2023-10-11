#include <iostream>

using namespace std;

class Int
{
private:
    int m_value{0};

public:
    Int(int num = 0) : m_value{num}
    {
    }

    Int operator+(int num)
    {
        return m_value += num;
    }

    Int operator-(int num)
    {
        return m_value -= num;
    }


    Int operator++()//pre increment
    {
        return ++m_value;
    }

    Int operator--()//pre decrement
    {
        const int temp=--m_value;
        return temp;
    }

    Int operator++(int) //post increment
    {
        Int temp{*this};
        ++(*this);
        return temp;
    }

    Int operator--(int) //post decrement
    {
        Int temp{*this};
        --(*this);
        return temp;
    }

    friend ostream &operator<<(ostream &out, const Int &obj)
    {
        out << obj.m_value;
        return out;
    }
};

int main()
{
    Int a{8};
    a++;//9
    a+1;//10
    ++a;//11
    ++++++a;//12
    ++++++++++++++++++++++++++++++++a;//13
    a--------------;//12
    cout << a << endl;

/*
 Ile maksymalnie znaków + (-) można postawić przed lub
za obiektem typu A, żeby kod był nadal ważny i działający?

Przed i za obiektem można postawić dowolnie parzystą ilość znaków + lub - 
jednak i tak liczba zostanie podniesiona tylko o 1.

*/
}