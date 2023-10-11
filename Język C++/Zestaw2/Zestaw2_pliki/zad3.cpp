#include <initializer_list>
#include <cstdio>
#include <iostream>

using namespace std;

auto fun(const std::initializer_list<int> &lista)
{
    int suma = 0;
    for (auto it = lista.begin(); it != lista.end(); ++it)
    {
        suma += *it;
    }
    return suma;
}

int main()
{
    auto arg = {1, 2, 3, 4, 5};//tablica do ktorej wpisuje sie liczby do dodania do siebie
    cout << fun(arg) << endl;
}