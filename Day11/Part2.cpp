#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<long long, long long> v;
    long long int num;

    ifstream file("input.txt");

    while (file >> num) 
    {
        v[num]++;
    }

    for (int i = 0; i < 75; i++) 
    {
        map<long long, long long> temp;
        for (auto pp : v) 
        {
            if (pp.first == 0) 
            {
                temp[1] += pp.second;
            } 
            else if (to_string(pp.first).length() % 2 == 0) 
            {
                string num_str = to_string(pp.first);
                long long part1 = stoll(num_str.substr(0, num_str.length() / 2));
                long long part2 = stoll(num_str.substr(num_str.length() / 2));
                temp[part1] += pp.second;
                temp[part2] += pp.second;
            } 
            else 
            {
                temp[2024 * pp.first] += pp.second;
            }
        }
        v = temp;
    }

    long long int count = 0;
    for (auto pp : v) 
    {
        count += pp.second;
    }

    cout << "Size: " << count << endl;
    return 0;
}
