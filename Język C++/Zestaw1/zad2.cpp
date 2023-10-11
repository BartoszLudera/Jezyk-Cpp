#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{

    char tablicaA[1000];
    char tablicaB[1000];
    cout << "Podaj wyraz A: ";
    cin.getline(tablicaA, 999);
    cout << "Podaj wyraz B: ";
    cin.getline(tablicaB, 999);


    int lenghtOfTabA = strlen(tablicaA);

    for (int a = 0; a < lenghtOfTabA; a++)//zamiana duzych liter na male
    {
        tablicaA[a]=tolower(tablicaA[a]);
    }


    int lenghtOfTabB = strlen(tablicaB);

    for (int b = 0; b < lenghtOfTabB; b++)//zamiana duzych liter na male
    {
        tablicaB[b]=tolower(tablicaB[b]);
    }

    //porownanie 2 cigow znakow ze soba
    int counter=0;
    for (int x = 0; x < lenghtOfTabB; x++)
    {
        if (tablicaA[x] != tablicaB[x])
        {
            cout << "Ciagi znakow nie sa rowne!\n";
            return 0;
        }
        else
        {
            counter++;
        }
    }

    if(counter==lenghtOfTabB)
    {
        cout<<"Ciagi sa rowne!\n";
        return 0;
    }
}