#include <iostream>
#include <random>
#include <vector>

using namespace std;

vector<int> numbers;

void randomNumbersGenrator()
{
    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<> distrib(1, 10000);//użycie genereatora

    for (int n = 0; n < 10000; ++n)
    {
        numbers.push_back(distrib(gen));//wpisanie nieposortowaych liczb do kontenera 
    }
}

int partition(vector<int> &vector, int start, int end)//funckja ustawiajaca podzial
{

    int pivot = end;
    int j = start;
    for (int i = start; i < end; ++i)
    {
        if (vector[i] < vector[pivot])
        {
            swap(vector[i], vector[j]);
            ++j;
        }
    }
    swap(vector[j], vector[pivot]);
    return j;
}

void quicksort(vector<int> &vector, int start, int end)//funkcja quicksort
{

    if (start < end)
    {
        int p = partition(vector, start, end);
        quicksort(vector, start, p - 1);
        quicksort(vector, p + 1, end);
    }
}

void printVector(vector<int> vector)//funkcja wypisujaca wszystkie liczby znajdujace sie w kontenerze
{
    for (int i = 0; i < vector.size(); ++i)
    {
        cout << vector[i] << ' ';
    }
    cout << endl;
}

int main()
{
    randomNumbersGenrator();//funkcja generujaca 10000 liczb z przedzialu 0-10000
    cout << "Vector Before Sorting: " << endl;
    printVector(numbers);//funckja wypisuje wszystkie elementy tablicy
    quicksort(numbers, 0, numbers.size() - 1);//funkcja quicksort
    cout << "Vector After Sorting: " << endl;
    printVector(numbers);//funckja wypisuje wszystkie elementy tablicy
}