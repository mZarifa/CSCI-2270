#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include <vector>
#include <stdio.h>
#include "arrayHelper.hpp"

using namespace std;

arrayHelper:: arrayHelper() //class def
{
}
void arrayHelper::setTestArray(int value, int position) //set the testArray at a set position to a set value
{
    testDataArray[position] = value;
}

int arrayHelper::getTestArray(int i) //return the value of a certain array.
{
    return testDataArray[i];
}

void arrayHelper::openAndRead(string input) //function to read the file and insert it into the public array.
{
    int i = 0;
    ifstream inFile;
    inFile.open(input);
    string holdString;
    if (inFile.is_open())
    {
        cout << "File has been opened sucessfully." << endl;
        while (!inFile.eof())
        {
            getline(inFile, holdString , ',');
            testDataArray[i] = stoi(holdString); //actual insert of the line into the testDataArray
            i++;
        }
        cout << input << " has been initilized sucessfully." << endl;
        inFile.close();
    }
    else
    {
        cout << "NO FILE HAS BEEN OPENED" << endl;
    }
}

void arrayHelper::outputArray() //reads the entire contents of the testDataArray
{
    for (int i = 0; i < 40000; i++)
    {
        cout << testDataArray[i] << endl;
    }
}
