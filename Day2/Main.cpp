#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void addToArray(int*& array, int& size, int x );
bool isSafe(const int* array, const int size);
void printArray(int* array, int size);
void deleteIndex(int*& array, int& size, int index);
bool isSafeWithAtLeast1(const int* array ,const int size);

int main() 
{
    int* row = nullptr;
    int rowNumberCount = 0;
    ifstream file("input.txt");

    string line;
    int safeReportCount = 0;
    int i = 1;
    while (getline(file, line)) {
        istringstream stream(line);
        int num;
        

        while (stream >> num) 
        {
            addToArray(row, rowNumberCount, num);
        }

        //if (isSafe(row, rowNumberCount)) 
            //safeReportCount++;

        if (isSafeWithAtLeast1(row, rowNumberCount)) 
            safeReportCount++; 
         

        cout << i << "] ";
        i++;
        if (isSafeWithAtLeast1(row, rowNumberCount)) 
            cout << "*";
        printArray(row, rowNumberCount);
        

        delete[] row;
        row = nullptr;
        rowNumberCount = 0;
    }

    cout << "Safe Report Count: " << safeReportCount << endl;
    return 0;
}

void addToArray(int*& array, int& size, int x )
{
    int* newArray = new int[size+1];
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

bool isSafe(const int* array, const int size)
{
    if(array[0] > array[1])
    {
        for(int i = 0; i < size - 1; i++)
        {
            if(array[i] <= array[i+1] || array[i] - array[i + 1] > 3 )
                return false;
        }
        return true;
    }
    else if(array[0] < array[1])
    {
        for(int i = 0; i < size - 1; i++)
        {
            if(array[i] >= array[i+1] || array[i + 1] - array[i] > 3)
                return false;
        }
        return true;
    }
    else
    {
        return false;
    }   
}

bool isSafeWithAtLeast1(const int* array, const int size)
{
    
    if (isSafe(array, size)) {
        return true;
    }

    for (int i = 0; i < size; i++)
    {
        int* newArray = new int[size - 1];
        int newSize = size - 1;
        
        for (int j = 0, k = 0; j < size; j++) 
        {
            if (j != i) 
            { 
                newArray[k++] = array[j];
            }
        }

       if (isSafe(newArray, newSize)) {
            delete[] newArray;
            return true;  
        }

        delete[] newArray;
    }

    return false;
}
void deleteIndex(int*& array, int& size, int index)
{
    if (size <= 1) 
    {
        delete[] array; 
        array = nullptr;
        size = 0;
        return;
    }

    int* newArray = new int[size - 1]; 
    for (int j = 0, k = 0; j < size; j++) 
    {
        if (j != index) 
        {  
            newArray[k++] = array[j];
        }
    }

    delete[] array;  
    array = newArray; 
    size--;  
}

void printArray(int* array, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}