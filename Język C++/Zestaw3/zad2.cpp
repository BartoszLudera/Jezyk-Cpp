#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

bool isSmaller(string str1, string str2)
{
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;

    for (int i = 0; i < n1; i++)
    {
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;
    }
    return false;
}

class BigInt
{
public:
    string number;

public:
    BigInt(string s) : number{""}
    {
        number = s;
    }
    BigInt &operator=(const BigInt s)
    {
        if (this->number != s.number)
            this->number = s.number;
        return *this;
    }
    string add(BigInt x)
    {

        string result = ""; 

        int n1 = number.length(), n2 = x.number.length();

        reverse(number.begin(), number.end());
        reverse(x.number.begin(), x.number.end());

        int carry = 0;
        for (int i = 0; i < n1; i++)
        {

            int sum = ((number[i] - '0') + (x.number[i] - '0') + carry);
            result.push_back(sum % 10 + '0');

            carry = sum / 10;
        }

        for (int i = n1; i < n2; i++)
        {
            int sum = ((x.number[i] - '0') + carry);
            result.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        if (carry)
            result.push_back(carry + '0');

        reverse(result.begin(), result.end());

        return result;
    }

    string subtract(BigInt str2)
    {
        string result = "";

        int n1 = number.length(), n2 = str2.number.length();
        int substract = n1 - n2;

        int carry = 0;

        for (int i = n2 - 1; i >= 0; i--)
        {

            int sub = ((number[i + substract] - '0') - (str2.number[i] - '0') - carry);
            if (sub < 0)
            {
                sub = sub + 10;
                carry = 1;
            }
            else
                carry = 0;

            result.push_back(sub + '0');
        }

        for (int i = n1 - n2 - 1; i >= 0; i--)
        {
            if (number[i] == '0' && carry)
            {
                result.push_back('9');
                continue;
            }
            int sub = ((number[i] - '0') - carry);
            if (i > 0 || sub > 0) 
                result.push_back(sub + '0');
            carry = 0;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

int main()
{
    BigInt n1{""}, n2{""}, n3{""}, n4{""};

    cout << "\nDodawanie liczb: \n";

    cout << "Podaj wartosc 1 liczby: ";
    cin >> n1.number;

    cout << "Podaj wartosc 2 liczby: ";
    cin >> n2.number;

    if (n1.number.length() <= n2.number.length())
        cout << "\n"
             << n1.add(n2) << endl;
    else
        cout << "\n"
             << n2.add(n1) << endl;

    cout << "\nOdejmowanie liczby wiekszej od mniejszej: \n";
    
    cout << "Podaj wartosc 1 liczby: ";
    cin >> n3.number;

    cout << "Podaj wartosc 2 liczby: ";
    cin >> n4.number;
    if (isSmaller(n3.number, n4.number))
        cout << "\n"
             << n4.subtract(n3) << endl;
    else
        cout << "\n"
             << n3.subtract(n4) << endl;

    return 0;
}