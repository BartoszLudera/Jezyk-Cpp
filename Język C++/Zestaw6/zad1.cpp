/*
zakomentowane fragmenty to próba napisania struktury niestety bez skutecznie
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <random>
#include <algorithm>

using namespace std;

vector<int> vec(100);

void print()
{
    cout << "numbers:";
    for (int i = 0; i < 100; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

// struct MyStruct
// {
//     int key;
//     int intValue;

//     MyStruct(int k, const int &i) : key(k), intValue(i) {}

//     bool operator>(const MyStruct &str) const
//     {
//         return (key > str.key);
//     }
// };

// struct X
// {
//     int x;
//     bool operator<(const X &val) const
//     {
//         return x < val.x;
//     }
// };

// struct Xgreater
// {
//     bool operator()(const X &lx, const X &rx) const
//     {
//         return lx.x < rx.x;
//     }
// };

struct Sorting
{

    int number;

    bool operator<(const Sorting &a) const
    {
        return a.number > a.number;
    }
};

int main()
{

    iota(vec.begin(), vec.end(), 1);

    auto rng = default_random_engine{};
    shuffle(begin(vec), end(vec), rng);

    print();

    sort(vec.begin(), vec.end(), greater<int>());

    print();

    shuffle(begin(vec), end(vec), rng);

    print();

    //sort(vec.begin(), vec.end(), Sorting());

    sort(begin(vec), end(vec), [](int a, int b) { return a > b; });

    print();

    // cout << "numbers:";
    // for (int i = 0; i < 100; i++)
    // {
    //     cout << vec[i] << " ";
    // }
}
