/*Nie byłem pewny czy program ma wypisywać wszystkie wyrazy z ciągu czy jedynie wyraz o numerze który wpisze użytkowynik
dlatego napisałem 2 wersje tego zadania:
(1) wypisuje tylko 1 wyraz o numerze podanym przez użytkownika
(2) wypusyje cały ciąg od 1 wyrazu do wyrazu o numerze podanym przez użytkownika
*/


/*(1)*/
#include <iostream>
using namespace std;

unsigned long long fib[1000];//pamiec do ktorej beda wpisywane liczby z ciagu fib


unsigned long long fibIteracja(unsigned long long k, unsigned long long maxk)
{
    unsigned long long j;
    for (j = maxk+1; j <= k; j++)
    {
        fib[j]=fib[j-1]+fib[j-2];
    }
    return fib[k];
}

int main()
{
    fib[0]=0;
    fib[1]=1;
    int maxk = 1;

    while (true)
    {
        int k, p=0, counter = 0;

        cout << "Podaj liczbe (ctrl+c by przerwac): ";
        cin >> k;

        if (k <= maxk)
        {
            cout << "[pamiec]  : "<<fib[k] << endl;
        }
        else
        {
            cout<< "[liczone]  : "<<fibIteracja(k,maxk)<< endl;
        }

        if(maxk<k)//ustawia nowy maxk
        {
            maxk=k;
        }
    }
}


/*(2)*/

// #include <iostream>
// using namespace std;


// int main()
// {
//     unsigned long long fib[1000];//pamiec do ktorej beda wpisywane liczby z ciagu fib

//     int maxk = 0;

//     while (true)
//     {
//         unsigned long long a = 0, b = 1;
//         int k, p=0, counter = 0;

//         cout << "Podaj liczbe: ";
//         cin >> k;

//         if (k <= maxk)
//         {
//             for (p = 0; p < k; p++)//petla ktora wypisuje zapamietane wczesniej wartosci
//             {
//                 cout << "[pamiec]  : "<<fib[counter] << endl;
//                 counter++;
//             }
//         }
//         else if(p<k)
//         {
//             for (int j = p; j < k; j++)//petla ktora tworzy i zapisuje w pamieic nowe liczby ciagu
//             {
//                 b += a;
//                 a = b - a;
//                 fib[j] = a;
//                 cout << "[liczone] : " << fib[counter] << endl;
//                 counter++;
//             }
//         }

//         if(k>maxk)//ustawia nowy maxk
//         {
//             maxk=k;
//         }
//     }
// }

