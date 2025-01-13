#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void swap(string*& array, const int index1, const int index2);
void addToArray(string*& array, int& size, string stringacter);
void printArray(const string* array, int size);

int main()
{
    ifstream file("input.txt");
    string* list = nullptr;
    int size = 0;
    char c;
    int id = 0;
    int block = 0;
    while(file.get(c))
    {
        if(block % 2 == 0)
        {
            for(int k = 0; k < c - '0'; k++)
            {
                addToArray(list, size, to_string(id));  
            }
            id++;
        }
        else
        {
            for(int k = 0; k < c  - '0'; k++)
            {
                addToArray(list, size, ".");  
            }
        }
        block++;
    }

    for(int i = 0; i < size; i++)
    {
        if(list[i] == ".")
        {
            for(int j = size - 1; j >= i; j--)
            {
                if(list[j] != ".")
                {
                    swap(list, i ,j);
                    break;
                }
            }
        }
    }

    long long int total = 0;

    for(int i = 0; i < size && list[i] != "."; i++)
    {
        total += stoll(list[i]) * i;
    }

    printArray(list,size);
    cout << endl << endl << endl << "Total is " << total;
    return 0;
}

void swap(string*& array, const int index1, const int index2)
{
    string temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

void addToArray(string*& array, int& size, string character)
{
    string* newArray = new string[size + 1];
    for(int i = 0; i < size; i++)
    {
        newArray[i] = array[i];
    }
    newArray[size] = character;
    delete[] array;
    array = newArray;
    newArray = nullptr;
    size++;
}

void printArray(const string* array, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << " " ;
    }
}