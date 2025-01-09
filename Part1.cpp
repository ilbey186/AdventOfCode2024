#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <sstream>

using namespace std;

long long int insertOperation(const long long int result, int* array, int size);
void addToArray(int*& array, int& size, const int number);
void printArray(int* array, int size);

int main()
{
    ifstream file("input.txt");
    string line;
    string s;
    long long int total = 0;
    while(getline(file, line))
    {   
        cout << line << endl;
        long long  int result;
        for(int i = 0; i < line.length(); i++)
        {
            if(line[i] != ':')
            {
                s += line[i];
            }
            else
            {
                result = stoll(s);
                line = line.substr(i + 2, line.length() - (i + 2));   
            }
        }
        string number;
        int* numbers = nullptr;
        int size = 0;
        for(int j = 0; j < line.length(); j++)
        {
            if(!isspace(line[j]))
            {
                number += line[j];
            }
            else
            {
                addToArray(numbers, size, stoi(number));
                number = "";
            }
                
        }
        addToArray(numbers, size, stoi(number));
        total += insertOperation(result, numbers, size);

        printArray(numbers,size);
        s.clear();
        line.clear();
        delete[] numbers;
    }
    cout << "Total is " << total;
    return 0;
}

long long int insertOperation(const long long int result, int* array, int size)
{
    long long int value = 0;
    int possibilities = pow(2, size - 1);
    for(int i = 0; i < possibilities; i++)
    {
        long long int current = array[0];
        for(int j = 0; j < size - 1; j++)
        {
            if (i % static_cast<int>(pow(2, j + 1)) < static_cast<int>(pow(2, j)))
            {
                current *= array[j+1];
            }
            else
            {
                current += array[j+1];
            }
        }
        if(current == result)
        {
            return current;
        }
    }
    return 0;
}

void addToArray(int*& array, int& size, const int number)
{
    int* newArray = new int[size + 1];
    for(int i = 0; i < size; i++)
    {
        newArray[i] = array[i];
    }
    newArray[size] = number;
    delete[] array;
    array = newArray;
    newArray = nullptr;
    size++;
}

void printArray(int* array, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}


