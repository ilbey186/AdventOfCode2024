#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool isInt(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    ifstream file("input.txt");
    if (!file) 
    {
        cerr << "Error: input.txt could not be opened." << endl;
    }

    char c;
    string s;
    int sum = 0;
    bool canRead = true;

    while (file.get(c)) {
        int num1 = 0, num2 = 0;
        if (c == 'm' && file.get(c) && c == 'u' && file.get(c) && c == 'l' && file.get(c) && c == '(') 
        {
            if (file.get(c) && isInt(c)) 
            {
                s = c;
                while (file.get(c) && isInt(c)) 
                {
                    s += c;
                }
                num1 = stoi(s);

                if (c == ',' && file.get(c) && isInt(c)) 
                {
                    s = c;
                    while (file.get(c) && isInt(c)) 
                    {
                        s += c;
                    }
                    num2 = stoi(s);

                    if (c == ')' && canRead) 
                    {
                        sum += num1 * num2;
                    }
                }
            }
        }
        else if(c == 'd' && file.get(c) && c == 'o')
        {
            canRead = true;
            if( file.get(c) && c == 'n' && file.get(c) && c == 39 && file.get(c) && c == 't') 
            {
                canRead = false;
            }
        }
    }

    cout << "Sum: " << sum << endl;
    return 0;
}