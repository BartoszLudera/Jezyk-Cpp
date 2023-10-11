#include <iostream>
using namespace std;


int main()
{
    unsigned long long fib[300];//pamiec do ktorej beda wpisywane liczby z ciagu fib

    int maxk = 0;

    while (true)
    {
        unsigned long long a = 0, b = 1;
        int k, p=0, counter = 0;

        cout << "Podaj liczbe: ";
        cin >> k;

        if (k <= maxk)
        {
            for (p = 0; p < k; p++)//petla ktora wypisuje zapamietane wczesniej wartosci
            {
                cout << "[pamiec]  : "<<fib[counter] << endl;
                counter++;
            }
        }
        else if(p<k)
        {
            for (int j = p; j < k; j++)//petla ktora tworzy i zapisuje w pamieic nowe liczby ciagu
            {
                b += a;
                a = b - a;
                fib[j] = a;
                cout << "[liczone] : " << fib[counter] << endl;
                counter++;
            }
        }

        if(k>maxk)
        {
            maxk=k;
        }
    }
}