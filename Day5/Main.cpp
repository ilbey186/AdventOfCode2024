#include <fstream>
#include <iostream>
#include <chrono>


using namespace std;

bool existsInArray(int* array,int x);
void printTable(int** array);
void addToArray(int*& array, int& size, int x);
void printArray(int* array, int size);

int main()
{

    int** table = nullptr;
    table = new int*[100];
    for(int i = 0; i < 100; i++)
    {
        table[i] = new int[100];
        for(int j = 0; j < 100; j++)
        {
            table[i][j] = 0;
        }
    }
    ifstream file("input.txt");
    string s;
    while(getline(file, s) && s != "")
    {
        int x = stoi(s.substr(0,2));
        int y = stoi(s.substr(3,2));
        for(int i = 0; i < 100;i++)
        {
            if(table[x][i] == 0)
            {
                table[x][i] = y;
                break;
            }
        }
        
    }

    int sum = 0;
    int sumUnordered = 0;

    while(getline(file,s) && s != "")
    {
        bool rightOrder = true;
        int numberCount = 0;
        int* array = nullptr;
        int lastNumber;
        for(int i = 0; s.substr(i + 2,2) != ""; i+=3)
        {
            int number1 = stoi(s.substr(i,2));
            int number2 = stoi(s.substr(i+3,2));
            addToArray(array,numberCount,number1);
           
            lastNumber = number2;
           
            if(!existsInArray(table[number1],number2))
            {
                rightOrder = false;
            }

        }
        addToArray(array, numberCount,lastNumber);
        //printArray(array, numberCount);
        if(rightOrder)
        {
            int indexCount = 3*(numberCount) - 2;
            sum += stoi(s.substr(indexCount/2,2));
        }
        else
        {
            for(int i = 0; i < numberCount;i++)
            {
                int rightHandCount = 0;
                for(int j = 0; j < numberCount; j++)
                {
                    if(existsInArray(table[array[i]],array[j]))
                    {
                        rightHandCount++;
                    }

                }
                if(rightHandCount == numberCount/2 )
                {
                    sumUnordered += array[i];
                    break;
                }
            }
        }
    }

    cout << "Ordered Sum: " << sum << endl;
    cout << "Unordered Sum: "<< sumUnordered;

    for(int i = 0; i < 100;i++)
    {
        delete[] table[i];
    }
    delete[] table;

    return 0;
}

bool existsInArray(int* array,int x)
{
    for(int i = 0; i < 100;i++)
    {
        if(array[i] == x)
            return true;
    }
    return false;
}

void addToArray(int*& array, int& size, int x)
{
    int* newArray = new int[size+1];
    for(int i = 0; i < size;i++)
    {
        newArray[i] = array[i];
    }
    newArray[size] = x;
    delete[] array;
    array = newArray;
    newArray = nullptr;
    size++;
    
}

void printTable(int** array)
{
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            if(array[i][j] != 0)
                cout << array[i][j] << " ";
        }
        cout << endl << endl << endl;
    }

}

void printArray(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    
    cout << endl;
}