/****************************************************************/
/*                  RPN Calculator Driver File                  */
/****************************************************************/
/*      TODO: Implement driver as described in the writeup      */
/****************************************************************/

#include "RPNCalculator.hpp"
#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

bool isNumber(string s)
{
    if(s.size() == 1 && s == "-") return false;
    else if(s.size() > 1 && s[0] == '-') s = s.substr(1);

    bool point = false;
    for(int i = 0; i < s.size(); i++)
    {
        if(!isdigit(s[i]) && s[i] != '.') return false;
        if(s[i]=='.' and !point) point = true;
        else if(s[i]=='.' and point) return false;
    }

    return true;
}

int main()
{
    RPNCalculator calculate;
    string input;
    cout << "Enter the operators and operands ('+', '*') in a postfix format " << endl;

    while (input != "=")
    {
        cout << "#> ";
        getline(cin,input);

        if(input != "=")
        {
            if(isNumber(input))
            {
                calculate.push(stof(input));
            }
            else if(!isNumber(input))
            {
                calculate.compute(input);
                if(calculate.isEmpty())
                {
                    cout << "No operands: Nothing to evaluate" << endl;
                    return 0;
                }
            }
        }
    }
    if(calculate.isEmpty())
    {
        cout << "No operands: Nothing to evaluate" << endl;
        return 0;
    }

    Operand *temp = calculate.peek();
    float num = temp->number;
    calculate.pop();

    if(!calculate.isEmpty())
    {
        cout << "Invalid expression" << endl;
    }
    else
    {
        cout << num << endl;
    }
    return 0;
}