#include <iostream>
using namespace std;

int main()
{
    int inside, outside, border;
    bool isBorder;

    cout << "\nPodaj rozmiar zawnetrzny: ";
    cin >> outside;
    cout << "Podaj rozmiar wewnetrzny (musi miec ta sama parzystosc co r. zewnietrzny): ";
    cin >> inside;

    border = ((outside - inside) / 2);

    if (inside <= 0 || outside <= 0 || ((inside + outside) % 2) != 0)
    {
        cout << "Bledne dane!!!\n";
        return 0;
    }

    for (int i = 0; i < outside; i++)
    {
        for (int j = 0; j < outside; j++)
        {
            isBorder = false;
            if (i < border || i > outside - border - 1 || j < border || j > outside - border - 1)
            {
                isBorder = true;
            }

            if (isBorder == true)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << "\n";
    }
}
