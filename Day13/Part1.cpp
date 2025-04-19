#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

int findTokenForMachine(string line1, string line2, string line3);

int main()
{
    ifstream file("input2.txt"); 
    string s1, s2, s3;
    int total = 0;
    
    while (getline(file, s1)) 
    {
        if (s1.empty()) continue; 
        getline(file, s2);
        getline(file, s3);
        
        total += findTokenForMachine(s1, s2, s3);
        cout << "machine done" << endl;
    }
    
    cout << total << endl;
}

int findTokenForMachine(string line1, string line2, string line3)
{
    int aX, aY, bX, bY, targetX, targetY;
    
    if (line1[7] == 'A') {
        for (int i = 7; i < line1.size(); i++) 
        {
            if (line1.substr(i, 2) == "X+") 
            {
                int j = 0;
                string word = "";
                
                while (isdigit(line1[i + j + 2])) 
                {
                    word += line1[i + j + 2];
                    j++;
                }
                
                aX = stoi(word);
            }
            if (line1.substr(i, 2) == "Y+") 
            {
                int j = 0;
                string word = "";
                
                while (isdigit(line1[i + j + 2])) 
                {
                    word += line1[i + j + 2];
                    j++;
                }
                
                aY = stoi(word);
            }
        }
    }

   
    if (line2[7] == 'B') 
    {
        for (int i = 7; i < line2.size(); i++) 
        {
            if (line2.substr(i, 2) == "X+") 
            {
                int j = 0;
                string word = "";
                
                while (isdigit(line2[i + j + 2])) 
                {
                    word += line2[i + j + 2];
                    j++;
                }
                
                bX = stoi(word);
            }
            if (line2.substr(i, 2) == "Y+") 
            {
                int j = 0;
                string word = "";
                
                while (isdigit(line2[i + j + 2])) 
                {
                    word += line2[i + j + 2];
                    j++;
                }
                
                bY = stoi(word);
            }
        }
    }

  
    if (line3[7] == 'X') 
    {
        for (int i = 0; i < line3.size(); i++) 
        {
            
            if (line3.substr(i, 2) == "X=") 
            {
                i += 2;
                string num = "";
                
                while (i < line3.size() && isdigit(line3[i])) 
                {
                    num += line3[i++];
                }
                targetX = stoi(num);
            }
            if (line3.substr(i, 2) == "Y=") 
            {
                i += 2;
                string num = "";
                
                while (i < line3.size() && isdigit(line3[i])) 
                {
                    num += line3[i++];
                }
                
                targetY = stoi(num);
            }
        }
    }

   
    int detA = aX * bY - aY * bX;

  
    if (detA == 0) {
        cout << "No solution found!" << endl;
        return 0;
    }

   
    if ((bY * targetX - bX * targetY) % detA != 0 || (-aY * targetX + aX * targetY) % detA != 0) {
        cout << "No valid solution!" << endl;
        return 0;
    }

    int cA = (bY * targetX - bX * targetY) / detA;
    int cB = (-aY * targetX + aX * targetY) / detA;

    if (cA < 0 || cB < 0) {
        cout << "No valid solution!" << endl;
        return 0;
    }

    return 3 * cA + cB;
}
