#include <iostream>
  
using namespace std; 

    string arabic_to_roman(int n) //funkcja zamieniajaca liczby arabskie na rzymskie 
    {

        string romansNumbers[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        string roman;

        for (int i = 0; i < 13; ++i)
        {
            while(n - values[i] >= 0)
            {
                roman += romansNumbers[i];//od liczby w systemie arabskim odejmuje sie tyle ile sie zmisci z tablcy values
                n -= values[i];
            }
        }

        return roman;
    }

  
int main()  
{  
    int arabic;
    cout<<"Podaj liczbe do zamiany w systemie arabskim: ";
    cin>>arabic;
	cout << "Twoja liczba po zamiania to: "<< arabic_to_roman(arabic) << endl;
}  