#include <iostream>
#include <time.h>
using namespace std;

//funkcja liczaca ciag fib rekurencja
unsigned long long fibRekurencja(unsigned long long i)
{
    if (i < 3)
        return 1;

    return fibRekurencja(i - 2) + fibRekurencja(i - 1);
}

//funkcja liczaca ciag fib iteracja
unsigned long long fibIteracja(unsigned long long i)
{
    unsigned long long a = 0, b = 1;
    for (int j = 1; j < i; j++)
    {
        b += a;
        a = b - a;
    }
    return b;
}

int main()
{
    clock_t start, end;//funkcja liczaca czas

    char type;
    unsigned long long k;
    cout<<"Podaj ile wyrazow z ciagu fib obliczyc: ";
    cin>>k;

    cout << "Obliczbyc iteracyjnie czy rekurencyjnie? wpisz [i/r] ";
    cin >> type;

    if (type == 'i')
    {
        cout << "Wybrano metode iteracyjna." << endl;
        start = clock();
        for (unsigned long long i = 1; i <= k; ++i)
        {
            cout <<i<<". "<< fibIteracja(i) << endl;
        }
        end = clock();
    }
    else if (type == 'r')
    {
        cout << "Wybrano metode rekurncyjna." << endl;
        start = clock();
        for (unsigned long long i = 1; i <= k; ++i)
        {
            cout <<i<<". "<< fibRekurencja(i) << endl;
        }
        end = clock();
    }
    else
    {
        cout << "Bledne dane!!!" << endl;
        return 0;
    }

    //obliczanie czasu w jaki wykonana zostala dana funkcja
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Czas w jakim funkcja zostala wykonana : " << fixed << time_taken;
    cout << " sec " << endl;
    return 0;
}