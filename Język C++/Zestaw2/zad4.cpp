/*
niestety nie do końca zrozumiałem działanie switch'a pokazanego na labolatoriach
używającego <filesytem> (ciągle trafiałem na błędy podczas kompilacji) więc
zrobiłem całośc swoją metodą bazując na tym co było na labolatoriach

do kompilacji trzeba użyć:

g++ zad4.cpp -o zad4 -lstdc++fs

*/



#include <string>
#include <iostream>
#include <experimental/filesystem>

using namespace std;
namespace fs = experimental::filesystem;

int main()
{
    int counter=0;
    string path;
    cout<<"Podaj sciezke do katalogu: ";
    cin>>path;
    cout<<endl;
    for (auto & p : fs::directory_iterator(path))//pobieranie pliku z podanej sciezki
    {
        cout << " - "<<p << endl;
        counter++;
    }


    cout<<endl<<"liczba plikow wynosi: "<<counter<<endl;
}