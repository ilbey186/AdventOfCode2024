#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void printTable(char** array, const int& row, const int& column);

int main()
{
    char ** table = nullptr;
    int row = 130;
    int column = 130;

    table = new char*[row];
    for(int i = 0; i < row; i++)
    {
        table[i] = new char[column];
    }

    ifstream file("input.txt");
    string s;
    int guardPosI = 0;
    int guardPosJ = 0;
    for(int i = 0 ; getline(file,s); i++)
    {
        for(int j = 0; j < column; j++)
        {
            if(s[j] == '^')
            {
                guardPosI = i;
                guardPosJ = j;
            }
            table[i][j] = s[j];
        }
    }

    int initialI = guardPosI;
    int initialJ = guardPosJ;
    int loopCount = 0;
    
    bool inside = true;

    for(int i = 0; i < row;i++)
    {
        for(int j = 0; j < column; j++)
        {
            inside = true;
            
            if(table[i][j] == '.' )
            {
                table[i][j] = 'O';
            
                for(int k = 0; k < row * column + 1 && inside; k++) 
                {
                    if(table[guardPosI][guardPosJ] == '^')
                    {
                        if(table[guardPosI - 1][guardPosJ] != '#' && table[guardPosI - 1][guardPosJ] != 'O')
                        {
                            table[guardPosI][guardPosJ] = '.';
                            table[guardPosI - 1][guardPosJ] = '^';
                            guardPosI--;
                            if(guardPosI == 0)
                            {
                                inside = false;
                                table[guardPosI][guardPosJ] = '.';
                            }
                        }
                        else
                        {
                        table[guardPosI][guardPosJ] = '>';
                        }
                    }
                    else if(table[guardPosI][guardPosJ] == '>')
                    {
                        if(table[guardPosI][guardPosJ + 1] != '#' && table[guardPosI][guardPosJ + 1] != 'O')
                        {
                            table[guardPosI][guardPosJ] = '.';
                            table[guardPosI][guardPosJ + 1] = '>';
                            guardPosJ++;
                            if(guardPosJ == column - 1)
                            {
                                inside = false;
                                table[guardPosI][guardPosJ] = '.';
                            }
                        }
                        else
                        {
                            table[guardPosI][guardPosJ] = 'v';
                        }
                    }
                    else if(table[guardPosI][guardPosJ] == 'v')
                    {
                        if(table[guardPosI + 1][guardPosJ] != '#' && table[guardPosI + 1][guardPosJ] != 'O')
                        {
                            table[guardPosI][guardPosJ] = '.';
                            table[guardPosI + 1][guardPosJ] = 'v';
                            guardPosI++;
                            if(guardPosI == row - 1)
                            {
                                inside = false;
                                table[guardPosI][guardPosJ] = '.';
                            }
                        }
                        else
                        {
                        table[guardPosI][guardPosJ] = '<';
                        }
                    }
                    else if(table[guardPosI][guardPosJ] == '<')
                    {
                        if(table[guardPosI][guardPosJ - 1] != '#' && table[guardPosI][guardPosJ - 1] != 'O')
                        {
                            table[guardPosI][guardPosJ] = '.';
                            table[guardPosI][guardPosJ - 1] = '<';
                            guardPosJ--;
                            if(guardPosJ == 0)
                            {
                                inside = false;
                                table[guardPosI][guardPosJ] = '.';
                            }
                        }
                        else
                        {
                            table[guardPosI][guardPosJ] = '^';
                        }
                    }
                   
                }
                if(inside)
                { 
                    loopCount++;
                }
            
                table[i][j] = '.';
                table[guardPosI][guardPosJ] = '.';
                guardPosI = initialI;
                guardPosJ = initialJ;
                table[initialI][initialJ] = '^';
            }
        }
    }
    cout << "Looped " << loopCount << " times.";
}

void printTable(char** array, const int& row, const int& column)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            cout << array[i][j];
        }
        cout << endl;
    }
}