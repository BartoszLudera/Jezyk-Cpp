#include <iostream>

using namespace std;

class Konwerter
{
private:
    unsigned long m_n{};

public:
    Konwerter() : m_n(0) {}

    void operator()(string s)
    {
        m_n = 0;
        for (const char &i : s)
            m_n += i;
    }

    void operator()(char c)
    {
        m_n = c;
    }

    void operator()(const char *s)
    {
        m_n = 0;
        int i = -1;
        while (s[++i] != '\0')
        {
            m_n += s[i];
        }
    }

    friend ostream &operator<<(ostream &os, const Konwerter &k)
    {
        os << k.m_n;
        return os;
    }

    friend istream &operator>>(istream &is, Konwerter &k)
    {
        is >> k.m_n;
        return is;
    }
};

int main()
{
    Konwerter conv;
    cout << "Podaj liczbe(char): " << endl;
    conv('8');
    cout << "char : " << conv << endl;
    conv("28312");
    cout << "const char : " << conv << endl;
    string str("4565464564");
    conv(str);
    cout << "string : " << conv << endl;
}