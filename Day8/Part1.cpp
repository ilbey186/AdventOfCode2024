#include <fstream>
#include <iostream>

using namespace std;

void printTable(char** array, const int row, const int column);
bool existsInArray(const char* array, const int size, const char c);
void addToArray(char*& array, int& size, const char x);

int main()
{
    char** input = nullptr;
    char** frequencyTable = nullptr;

    ifstream file("input.txt");
    string s;
    int row = 0;
    int column = 0;
    while (getline(file, s)) 
    {
        if (column == 0) 
        {
            column = s.length();
        }
        row++;
    }
    file.clear();
    file.seekg(0, ios::beg);

    input = new char*[row];
    frequencyTable = new char*[row];
    for (int i = 0; i < row; i++) 
    {
        input[i] = new char[column];
        frequencyTable[i] = new char[column];
    }

    int i = 0;
    while (getline(file, s)) 
    {
        for (int j = 0; j < column; j++) 
        {
            input[i][j] = s[j];
            frequencyTable[i][j] = '.';
        }
        i++;
    }
    file.close();

    char* checkedAntenna = nullptr;
    int size = 0;

    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < column; j++) 
        {
            char freq = input[i][j];
            if (freq != '.' && !existsInArray(checkedAntenna, size, freq)) 
            {
             
                for (int x = 0; x < row; x++) 
                {
                    for (int y = 0; y < column; y++) 
                    {
                        if (input[x][y] == freq) 
                        {
                            for (int k = 0; k < row; k++) 
                            {
                                for (int l = 0; l < column; l++) 
                                {
                                    if (input[k][l] == freq && !(k == x && l == y)) 
                                    {
                                     
                                        int antinode1I = 2 * x - k;
                                        int antinode1J = 2 * y - l;
                                        int antinode2I = 2 * k - x;
                                        int antinode2J = 2 * l - y;

                                      
                                        if(antinode1I >= 0 && antinode1I < row && antinode1J >= 0 && antinode1J < column) 
                                        {
                                            frequencyTable[antinode1I][antinode1J] = '#';
                                        }
                                        if (antinode2I >= 0 && antinode2I < row && antinode2J >= 0 && antinode2J < column) 
                                        {
                                            frequencyTable[antinode2I][antinode2J] = '#';
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
           
                addToArray(checkedAntenna, size, freq);
            }
        }
    }

    int count = 0;
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < column; j++) 
        {
            if (frequencyTable[i][j] == '#') 
            {
                count++;
            }
        }
    }

    cout << count << endl;


    printTable(input, row, column);
    cout << endl << endl << endl;
    printTable(frequencyTable, row, column);

    for (int i = 0; i < row; i++) 
    {
        delete[] input[i];
        delete[] frequencyTable[i];
    }
    delete[] input;
    delete[] frequencyTable;
    delete[] checkedAntenna;

    return 0;
}

void printTable(char** array, const int row, const int column)
{
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < column; j++) 
        {
            cout << array[i][j];
        }
        cout << endl;
    }
}

bool existsInArray(const char* array, const int size, const char c)
{
    for (int i = 0; i < size; i++) 
    {
        if (array[i] == c) 
        {
            return true;
        }
    }
    return false;
}

void addToArray(char*& array, int& size, const char x)
{
    char* newArray = new char[size + 1];
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }
    newArray[size] = x;
    delete[] array;
    array = newArray;
    size++;
}
