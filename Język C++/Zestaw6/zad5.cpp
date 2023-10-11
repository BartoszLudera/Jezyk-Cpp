#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <string>
#include <list>

using namespace std;

int main(){
    list<char> lista{'a', 'c', 'b', 'd','f', 'e', 'h', 'g'};

    auto sort=[lista](const auto& a, const auto& b){
        auto iter=lista.begin();
    while(*iter!=a){iter++;}
    if (*(iter++)==b) return true; else return false;};

    using set_z_lambda = set<char, decltype(sort)>;
    set_z_lambda  mySet ({'a', 'a' , 'a', 'g', 'c', 'b', 'f', 'h', 'c', 'e', 'd', 'e'},sort);
    

    for (auto c:mySet) cout << c;
}


  