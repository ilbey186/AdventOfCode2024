#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int checkEightDir(char** array, int row, int column, int i, int j);
int checkxMas(char** array, int row, int column, int i, int j);

int main() {
    ifstream file("input.txt");
    if (!file) {
        cerr << "Error: input.txt could not be opened." << endl;
        return 1;
    }

    int row = 140, column = 140, occurence = 0;
    char** table = new char*[row];

    for (int i = 0; i < row; i++) {
        table[i] = new char[column];
    }

    for (int i = 0; i < row && !file.eof(); i++) {
        for (int j = 0; j < column && !file.eof(); j++) {
            file.get(table[i][j]);
            if (table[i][j] == '\n' || table[i][j] == ' ') {
                j--;
            }
        }
    }

    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < column; j++)
        {
            if (table[i][j] == 'A') 
            {
                occurence += checkxMas(table, row, column, i, j);
            }
        }
    }

    cout << "Occurrence: " << occurence << endl;

    for (int i = 0; i < row; i++) {
        delete[] table[i];
    }
    delete[] table;

    return 0;
}

/* int checkEightDir(char** array, int row, int column, int i, int j) {
    int occurence = 0;

    const int di[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    const int dj[] = {0, 1, 1, 1, 0, -1, -1, -1};

    for (int dir = 0; dir < 8; dir++) {
        int ni = i, nj = j;
        bool match = true;

        for (int k = 1; k <= 3; k++) {
            ni += di[dir];
            nj += dj[dir];

            if (ni < 0 || ni >= row || nj < 0 || nj >= column || 
                (k == 1 && array[ni][nj] != 'M') || 
                (k == 2 && array[ni][nj] != 'A') || 
                (k == 3 && array[ni][nj] != 'S')) {
                match = false;
                break;
            }
        }
        if (match) {
            occurence++;
        }
    }

    return occurence;
} */

int checkEightDir(char** array, int row, int column, int i, int j)
{
    int occurence = 0;
    if(i >= 3)
    {
        if(array[i-1][j] == 'M' && array[i-2][j] == 'A' && array[i-3][j] == 'S') // Direction 0
            occurence++;
    }
    if(i >= 3 && j <= column - 4)
    {
        if(array[i-1][j+1] == 'M' && array[i-2][j+2] == 'A' && array[i-3][j+3] == 'S') // Direction 1
            occurence++;
    }
    if(j <= column - 4)
    {
        if(array[i][j + 1] == 'M' && array[i][j+2] == 'A' && array[i][j+3] == 'S') // Direction 2
            occurence++;
    }
    if(i <= row - 4 && j <= column - 4)
    {
        if(array[i+1][j+1] == 'M' && array[i+2][j+2] == 'A' && array[i+3][j+3] == 'S') // Direction 3
            occurence++;
    }
    if(i <= row - 4)
    {
        if(array[i+1][j] == 'M' && array[i+2][j] == 'A' && array[i+3][j] == 'S') // Direction 4
            occurence++;
    }
    if(j >= 3  && i <= row - 4)
    {
        if(array[i+1][j-1] == 'M' && array[i+2][j-2] == 'A' && array[i+3][j-3] == 'S') // Direction 5
            occurence++;
    }
    if(j >= 3)
    {
        if(array[i][j-1] == 'M' && array[i][j-2] == 'A' && array[i][j-3] == 'S') // Direction 6
            occurence++;
    }
    if(i >= 3 && j >= 3)
    {
        if(array[i-1][j-1] == 'M' && array[i-2][j-2] == 'A' && array[i-3][j-3] == 'S') // Direction 7
            occurence++;
    }
    return occurence;
}

int checkxMas(char** array, int row, int column, int i, int j) {
    int occurrence = 0;

   
    if (i >= 1 && j >= 1 && i < row - 1 && j < column - 1) {
      
        if (((array[i - 1][j - 1] == 'S' && array[i + 1][j + 1] == 'M') || (array[i - 1][j - 1] == 'M' && array[i + 1][j + 1] == 'S')) && ((array[i - 1][j + 1] == 'S' && array[i + 1][j - 1] == 'M') || (array[i - 1][j + 1] == 'M' && array[i + 1][j - 1] == 'S')) ) {
            occurrence++;
        }
    }

    return occurrence;
}