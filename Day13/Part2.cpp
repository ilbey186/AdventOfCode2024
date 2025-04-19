#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdint> 

using namespace std;

long long int findTokenForMachine(string line1, string line2, string line3);

int main()
{
    ifstream file("input2.txt"); 
    string s1, s2, s3;
    long long int total = 0;
    
    while (getline(file, s1)) 
    {
        if (s1.empty()) continue; 
        getline(file, s2);
        getline(file, s3);
        
        total += findTokenForMachine(s1, s2, s3);
        cout << "Machine done" << endl;
    }
    
    cout << "Total tokens: " << total << endl;
}

long long int findTokenForMachine(string line1, string line2, string line3)
{
    long long int aX, aY, bX, bY, targetX, targetY;
    
    if (line1[7] == 'A') 
    {
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
                
                aX = stoll(word); 
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
                aY = stoll(word); 
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
                
                bX = stoll(word);  
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
                
                bY = stoll(word);  
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
                targetX = stoll(num);  
            }
            if (line3.substr(i, 2) == "Y=") 
            {
                i += 2;
                string num = "";
                
                while (i < line3.size() && isdigit(line3[i])) 
                {
                    num += line3[i++];
                }
                
                targetY = stoll(num);  
            }
        }
    }

   
    targetX += 10000000000000;
    targetY += 10000000000000;
 
    long long int detA = aX * bY - aY * bX;


    if (detA == 0) {
        cout << "No solution!" << endl;
        return 0;
    }

   
    if ((bY * targetX - bX * targetY) % detA != 0 || (-aY * targetX + aX * targetY) % detA != 0) 
    {
        cout << "No valid solution!" << endl;
        return 0;
    }

    long long int cA = (bY * targetX - bX * targetY) / detA;
    long long int cB = (-aY * targetX + aX * targetY) / detA;

    if (cA < 0 || cB < 0) 
    {
        cout << "No valid solution!" << endl;
        return 0;
    }

    return 3 * cA + cB;
}
