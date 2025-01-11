#include <fstream>
#include <iostream>
#include <cmath>

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
        for (int j = 0; j < column; j++) {
            frequencyTable[i][j] = '.';
        }
    }

    int i = 0;
    while (getline(file, s)) 
    {
        for (int j = 0; j < column; j++) 
        {
            input[i][j] = s[j];
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
                for (int x1 = 0; x1 < row; x1++) 
                {
                    for (int y1 = 0; y1 < column; y1++) 
                    {
                        if (input[x1][y1] == freq) 
                        {
                            for (int x2 = 0; x2 < row; x2++) 
                            {
                                for (int y2 = 0; y2 < column; y2++) 
                                {
                                    if (input[x2][y2] == freq && !(x1 == x2 && y1 == y2)) 
                                    {
                                        int dx = x2 - x1;
                                        int dy = y2 - y1;

                                        int nx = x2 + dx;
                                        int ny = y2 + dy;
                                        while (nx >= 0 && nx < row && ny >= 0 && ny < column) 
                                        {
                                            frequencyTable[nx][ny] = '#';
                                            nx += dx;
                                            ny += dy;
                                        }

                                        nx = x1 - dx;
                                        ny = y1 - dy;
                                        while (nx >= 0 && nx < row && ny >= 0 && ny < column) 
                                        {
                                            frequencyTable[nx][ny] = '#';
                                            nx -= dx;
                                            ny -= dy;
                                        }
                                        frequencyTable[x1][y1] = '#';
                                        frequencyTable[x2][y2] = '#';
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
