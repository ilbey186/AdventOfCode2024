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
                addToArray(numbers, size, stoll(number));
                number = "";
            }
                
        }
        addToArray(numbers, size, stoll(number));
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
    int possibilities = static_cast<int>(pow(3, size - 1)); 

    for (int i = 0; i < possibilities; ++i) 
    {
        long long int current = array[0];
        int operation = i;

        for (int j = 1; j < size; ++j) {
            int op = operation % 3;
            operation /= 3;

            if (op == 0) 
            {
                
                current += array[j];
            } 
            else if (op == 1) 
            {
                
                current *= array[j];
            } 
            else if (op == 2) 
            {
                int num_digits = static_cast<int>(log10(array[j])) + 1;
                if (array[j] == 0) num_digits = 1; 
                    current = current * static_cast<long long int>(pow(10, num_digits)) + array[j];
            }
        }

        if (current == result) {
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
