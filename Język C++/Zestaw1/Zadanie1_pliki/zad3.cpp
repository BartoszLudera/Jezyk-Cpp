#include <iostream>
#include <algorithm>

using namespace std;

string removeSpace(string str)//funkcja usuwajaca spacje z podanago stringa
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

void isPalindrom(string text)//funkcja sprawdzajaca czy dany tekst jest palindromem
{
    int i,j;
    for (i = 0, j = text.size() - 1; i < j; i++, j--)
    {
        if (text[i] != text[j])
            break;
    }
    if (i < j)
        cout<<"Podany ciag nie jest palindromem!"<<endl;
        
    else
        cout<<"Podany ciag jest palindromem!"<<endl;
        
}

int main()
{
    string input;             //string z wczytanymi danymi ze spacjami itd od uzytkownika
    string text;              //text wczytany od uzytkownika, bez spacji, ze wszystkimi malymi znakami
    cout << "Podaj swoj tekst do sprawdzenia: ";
    getline(cin, input);//pobranie ciagu tekstu od uzytkownika

    text = removeSpace(input);//funckja usuwa spacje
    transform(text.begin(), text.end(), text.begin(), ::tolower);//zamiana duzych liter na miale
    isPalindrom(text);
}