#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void splitAtIndex(vector<long long int>& vec, long long int index);
void printArray(const vector<long long int>& vec);

int main()
{
    vector<long long int> stoneLine;
    long long int num;

    ifstream file("input.txt");
    while (file >> num)
    {
        stoneLine.push_back(num);
    }

    for (int i = 0; i < 25; i++)
    {
        for (long long int j = 0; j < stoneLine.size(); j++)
        {
            if (stoneLine[j] == 0)
            {
                stoneLine[j] = 1;
            }
            else if (to_string(stoneLine[j]).length() % 2 == 0)
            {
                splitAtIndex(stoneLine, j);
                j++;
            }
            else if (to_string(stoneLine[j]).length() % 2 == 1)
            {
                stoneLine[j] *= 2024;
            }
        }
    }
    cout << "Size: " << stoneLine.size();
}

void splitAtIndex(vector<long long int>& vec, long long int index)
{
    string number = to_string(vec[index]);

    string firstHalf = number.substr(0, number.length() / 2);
    string secondHalf = number.substr(number.length() / 2);

    vec.insert(vec.begin() + index, stoll(firstHalf));
    vec[index + 1] = stoll(secondHalf);
}

void printArray(const vector<long long int>& vec)
{
    for (const auto& val : vec)
    {
        cout << val << " ";
    }
}
