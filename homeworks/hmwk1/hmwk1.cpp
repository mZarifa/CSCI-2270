// CS2270 Spring 2020
// Author: Matthew Zarifa

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

int insertIntoSortedArray(float myArray[], int numEntries, float newValue)
{
    myArray[numEntries] = newValue;
    float tempValue;
    for(int i = 0; i < numEntries + 1 ; i++)
	{
		for(int j = i+1; j < numEntries + 1; j++)
		{
			if(myArray[i] < myArray[j])
			{
				tempValue = myArray[i];
				myArray[i] = myArray[j];
				myArray[j] = tempValue;
			}
		}
	}
    return numEntries + 1;
}


int main (int argc, char **argv)
{
    string line;  //creates a string called 'line' and makes it blank. 
    int arrPos = 0; //creates an int to count the position of the array. 
    float myArray[100];
    
    ifstream in_file; //declares the file input variable
    string fileName = argv[1]; //filename
    in_file.open(fileName); //opens the file in in_file
    
    if(in_file.is_open())
    {
        while (getline(in_file,line) && arrPos < 100)
        { //while getline can read a line and the arrayPos is less than the length of the array
            
            if(line != "")
            { //if the index is 0, and if the line isn't empty
                insertIntoSortedArray(myArray, arrPos, stof(line));
                for(int i = 0; i < arrPos + 1; i++)
                {
                    if(i != arrPos)
                    {
                        cout << myArray[i];
                        cout << ",";
                    }
                    else
                    {
                        cout << myArray[i];
                    }
                }
                cout << endl;
                arrPos++; //add one to the array's position
            }
        }
        in_file.close(); //close the file.
    }
    else
    {
        cout << "Failed to open the file." << endl;
    }
} 


/* int main()
{
    float testArray[] = {6,3,22,2,3};
    insertIntoSortedArray(testArray, 5, 4);      
} */