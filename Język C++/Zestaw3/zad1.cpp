//uruchumienie przez powloke: g++ -D DEBUG -o zad1 zad1.cpp

/* 
Niestety nie zrozumiałem polecenia co do tego zadania i nie jestem pewny czy powinno tak działać.
*/


#include <iostream>
#include <string>

using namespace std;

class TString
{
private:
    string wyraz;

public:
    TString(string s) : wyraz{""}
    {
        wyraz = s;
#ifdef DEBUG
        cout << "TString konstruktor " << wyraz << endl;
#endif
    };
    TString(const TString &s)
    {
        wyraz = s.wyraz;
#ifdef DEBUG
        cout << "TString konstruktor kopiujacy " << wyraz << endl;
#endif
    }
    TString(TString &&s) : wyraz{s.wyraz}
    {
        wyraz = "";

#ifdef DEBUG
        cout << "TString konsruktor przenosacy " << wyraz << endl;
#endif
    }

    ~TString()
    {
#ifdef DEBUG
        cout << "TString destruktor " << wyraz << endl;

#endif
    };

    TString &operator=(const TString &s)
    {
        if (this != &s)
        {
            wyraz = s.wyraz;
        }
#ifdef DEBUG
        cout << "TString cp operator= " << wyraz << endl;
#endif
        return *this;
    }
    TString &operator=(TString &&s)
    {
        if (this != &s)
        {
            wyraz = s.wyraz;
            s.wyraz = "";
        }
#ifdef DEBUG
        cout << "TString mv operator= " << wyraz << endl;
#endif
        return *this;
    }
    TString &operator=(string s)
    {
        if (this->wyraz != s)
        {
            wyraz = s;
        }
#ifdef DEBUG
        cout << "TString mv operator= " << wyraz << endl;
#endif
        return *this;
    }
};

int main()
{
    TString wyraz{"ABRAKADABRA"};
    TString b{wyraz}, c{"REKURECJA"};

    wyraz = c;
    wyraz = "WITAJ";
    cout << string(50, '-') << endl;
}