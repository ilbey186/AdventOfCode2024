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
    char c;
    string s;
    int guardPosI = 0;
    int guardPosJ = 0;
    string guardDir = "up";
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

    bool inside = true;
    int i = 1;
    while(inside)
    {
        if(table[guardPosI][guardPosJ] == '^')
        {
            if(table[guardPosI - 1][guardPosJ] != '#')
            {
                table[guardPosI][guardPosJ] = 'X';
                table[guardPosI - 1][guardPosJ] = '^';
                guardPosI--;
                if(guardPosI == 0)
                {
                    inside = false;
                    table[guardPosI][guardPosJ] = 'X';
                }
            }
            else
            {
                table[guardPosI][guardPosJ] = '>';
            }
        }
        else if(table[guardPosI][guardPosJ] == '>')
        {
            if(table[guardPosI][guardPosJ + 1] != '#')
            {
                table[guardPosI][guardPosJ] = 'X';
                table[guardPosI][guardPosJ + 1] = '>';
                guardPosJ++;
                if(guardPosJ == column - 1)
                {
                    inside = false;
                    table[guardPosI][guardPosJ] = 'X';
                }
            }
            else
            {
                table[guardPosI][guardPosJ] = 'v';
            }
        }
        else if(table[guardPosI][guardPosJ] == 'v')
        {
            if(table[guardPosI + 1][guardPosJ] != '#')
            {
                table[guardPosI][guardPosJ] = 'X';
                table[guardPosI + 1][guardPosJ] = 'v';
                guardPosI++;
                if(guardPosI == row - 1)
                {
                    inside = false;
                    table[guardPosI][guardPosJ] = 'X';
                }
            }
            else
            {
                table[guardPosI][guardPosJ] = '<';
            }
        }
        else if(table[guardPosI][guardPosJ] == '<')
        {
            if(table[guardPosI][guardPosJ - 1] != '#')
            {
                table[guardPosI][guardPosJ] = 'X';
                table[guardPosI][guardPosJ - 1] = '<';
                guardPosJ--;
                if(guardPosJ == 0)
                {
                    inside = false;
                    table[guardPosI][guardPosJ] = 'X';
                }
            }
            else
            {
                table[guardPosI][guardPosJ] = '^';
            }
        }
        cout << i << "    " << guardPosI + 1 << "    " <<  guardPosJ + 1 << "    "<< table[guardPosI][guardPosJ] << endl;
        i++;
    }

    int XCount = 0;

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            if(table[i][j] == 'X')
                XCount++;
        }
    }
    cout << endl;
    cout << "Distinct X count: " << XCount;

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