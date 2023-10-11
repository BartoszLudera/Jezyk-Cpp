#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <iterator>
#include <numeric>
#include <string>

using namespace std;

int main()
{
    map<int,string> mis {{0, "zero"}, {1,"jeden"}, {2,"dwa"}, {3,"trzy"}, {4,"cztery"}, {5,"piec"}, {6,"szesc"}, {7,"siedem"}, {8,"osiem"}, {9,"dziewiec"}};
    vector<int> vec(10);
    iota(vec.begin(), vec.end(), 0);
    transform(vec.begin(), vec.end(),ostream_iterator<string>(cout,"\n"), 
    [mis] (int i){return mis.at(i);});

}
