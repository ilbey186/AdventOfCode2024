#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void swap(string*& array, const int index1, const int index2);
void addToArray(string*& array, int& size, const string& character);
void printArray(const string* array, int size);

int main()
{
    ifstream file("input.txt");

    string* list = nullptr;
    int size = 0;
    char c;
    int id = 0;
    int block = 0;

    while (file.get(c)) 
    {
        int count = c - '0';
        string value = (block % 2 == 0) ? to_string(id++) : ".";
        for (int k = 0; k < count; k++) 
        {
            addToArray(list, size, value);
        }
        block++;
    }


    for (int currentID = id - 1; currentID >= 0; currentID--) 
    {
        string currentIDStr = to_string(currentID);
        int objectSize = 0;
        int objectEndIndex = -1;


        for (int i = size - 1; i >= 0; i--) 
        {
            if (list[i] == currentIDStr) 
            {
                if (objectEndIndex == -1) 
                {
                    objectEndIndex = i;
                }
                objectSize++;
            }
        }

        for (int i = 0; i <= objectEndIndex - objectSize; i++) 
        {
            bool hasSpace = true;
            for (int j = 0; j < objectSize; j++) 
            {
                if (list[i + j] != ".") 
                {
                    hasSpace = false;
                    break;
                }
            }
            if (hasSpace) 
            {
                for (int j = 0; j < objectSize; j++) 
                {
                    swap(list[i + j], list[objectEndIndex - objectSize + 1 + j]);
                }
                break;
            }
        }
    }

    long long int total = 0;
    for (int i = 0; i < size; i++) 
    {
        if(list[i] != ".")
            total += stoll(list[i]) * i;
    }

    printArray(list, size);
    cout << endl << "Total is " << total << endl;

    delete[] list;
    return 0;
}

void swap(string& a, string& b)
{
    string temp = a;
    a = b;
    b = temp;
}

void addToArray(string*& array, int& size, const string& character)
{
    string* newArray = new string[size + 1];
    for (int i = 0; i < size; i++) 
    {
        newArray[i] = array[i];
    }
    newArray[size] = character;
    delete[] array;
    array = newArray;
    size++;
}

void printArray(const string* array, int size)
{
    for (int i = 0; i < size; i++) 
    {
        cout << array[i];
    }
    cout << endl;
}