#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string str, text;
    size_t textLenght;
    int columnSize;

    cout<<"Do jakiej szerekosci kolumn wyrownac tekst: ";
    cin>>columnSize;

    ifstream file("zad1text.txt");//wczytanie danych z pliku
    if (!file)
    {
        cerr << "File ERROR!\n";
        exit(1);
    }
    while (!file.eof())
    {
        getline(file, str);
        text += str + '\n';
    }

    textLenght=text.size();

    for (int i = 0; i <= textLenght; ++i)//dzielenie tektu na koluny o danym rozmiarze
    {

        if (i%columnSize==0)
        {
            cout << endl <<text[i];
        }
        else
        {
            cout << text[i];
        }
    }
}