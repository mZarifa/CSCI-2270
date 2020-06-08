#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

/*int counter = 0;

int main()
{
string s = "aeiou";
string input = "Fucking kill me";
for(int i = 0; i < s.length(); i++)
{
    for(int j = 0; j < input.length(); j++)
    {
        if (s[i] == input[j])
        counter++;
    }
}
cout << counter << endl;
}*/

int main()
{
    int x = 3;
    int &y = x;
    y = 4;
    cout << x << endl;
}