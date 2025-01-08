#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;


void deleteIndex(int*& array, int& size,const int i);
void addToArray(int*& array,  int& size, const int x );
void printArray(int*& array, const int size);
int comparison(int*& array1, int& size1, int*& array2 , int& size2);
int similarityScore(int*& array1, int& size1, int*& array2, int& size2 );

int main() {
    int* firstList = nullptr;
    int size1 = 0;
    int* secondList = nullptr;
    int size2 = 0;

    ifstream file("input.txt");

    string first, second;
    while (file >> first >> second) 
    {
        addToArray(firstList, size1, stoi(first));
        addToArray(secondList, size2, stoi(second));
    }

    //cout << comparison(firstList, size1, secondList, size2);
    cout << similarityScore(firstList, size1, secondList, size2);
    delete[] firstList;
    delete[] secondList;

    return 0;
}

void deleteIndex(int*& array, int& size,const int i)
{
    if(size == 1)
    {
        delete[] array;
        array = nullptr;
    }
    else
    {
       int* newArray = new int[size - 1];
        for(int j = 0; j < size; j++)
        {
            if(i > j)
            {
                newArray[j] = array[j];
            }
            else if(j > i)
            {
                newArray[j-1] = array[j];
            }
        }
        delete[] array;
        array = newArray;
        newArray = nullptr;
        size--;
    }
}

void addToArray(int*& array,  int& size, const int x )
{
    int* newArray = new int[size + 1];
    for(int i = 0; i < size; i++)
    {
        newArray[i] = array[i];
    }
    newArray[size] = x;
    delete[] array;
    array = newArray;
    newArray = nullptr;
    size++;
}

void printArray(int*& array, const int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << endl;
    }
}

int comparison(int*& array1, int& size1, int*& array2 , int& size2)
{
    int large1index = 0;
    int large2index = 0;
    int sum = 0;
    for(int j = 0; j < 1000 ; j++) 
    {
        for(int i = 0; i < size1; i++)
        {
            if(array1[i] > array1[large1index])
                large1index = i;
        }

        for(int i = 0; i < size2; i++)
        {
            if(array2[i] > array2[large2index])
                large2index = i;
        }
        sum += abs(array1[large1index] - array2[large2index]);
        deleteIndex(array1, size1,large1index);
        
        deleteIndex(array2, size2,large2index);
        
        large1index = 0;
        large2index = 0;
    }
    return sum;
}

int similarityScore(int*& array1, int& size1, int*& array2, int& size2 )
{
    int score = 0;
    for(int i = 0; i < size1; i++)
    {
        int first = array1[i];
        int times = 0;
        for(int j = 0; j < size2; j++)
        {
            int second = array2[j];
            if(first == second)
                times++;
        }
        score += first * times;
    }
    return score;
}