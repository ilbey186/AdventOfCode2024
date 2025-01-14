#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void dfs(int x, int y, int& score);
bool inside(int i, int j);
void resetVisited();

int** map = nullptr;
bool** visited = nullptr;
int row = 0, column = 0;
int directions[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int main() 
{
    ifstream file("input.txt");
    string line;
    while (getline(file, line)) 
    {
        if (column == 0) 
        {
            column = line.length();
        }
        row++;
    }
    file.clear();
    file.seekg(0, ios::beg);

    map = new int*[row];
    visited = new bool*[row];
    for (int i = 0; i < row; i++) 
    {
        map[i] = new int[column];
        visited[i] = new bool[column];
    }

    int i = 0;
    while (getline(file, line)) 
    {
        for (int j = 0; j < column; j++) 
        {
            map[i][j] = line[j] - '0';
            visited[i][j] = false;
        }
        i++;
    }
    file.close();

    int totalScore = 0;
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < column; j++) 
        {
            if (map[i][j] == 0) 
            {
                int score = 0;
                resetVisited();
                dfs(i, j, score);
                totalScore += score;
            }
        }
    }

    cout << "Total: " << totalScore << endl;

    for (int i = 0; i < row; i++) 
    {
        delete[] map[i];
        delete[] visited[i];
    }
    delete[] map;
    delete[] visited;

    return 0;
}

void dfs(int x, int y, int& score) 
{
    if (map[x][y] == 9) 
    {
        score++;
        return;
    }

    visited[x][y] = true;

    for (int d = 0; d < 4; d++) 
    {
        int nx = x + directions[d][0];
        int ny = y + directions[d][1];
        if (inside(nx, ny) && !visited[nx][ny] && map[nx][ny] == map[x][y] + 1) 
        {
            dfs(nx, ny, score);
        }
    }

    visited[x][y] = false;
}

bool inside(int i, int j) 
{
    return (i >= 0 && i < row && j >= 0 && j < column);
}

void resetVisited() 
{
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < column; j++) 
        {
            visited[i][j] = false;
        }
    }
}