// CS2270 Spring 2020
// Author: Matthew Zarifa

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include <vector>
#include <stdio.h>
#include <sstream>

using namespace std;

struct Park
{
    string parkname;
    string state;
    int area;
};


void addPark(Park parks[], string parkname, string state, int area, int length)
{
    Park park;
    park.parkname = parkname;
    park.state = state;
    park.area = area;
    parks[length] = park;
    length++;
}

void printList(const Park parks[], int length)
{
    for(int i = 0; i < length; i++)
    {
        cout << parks[i].parkname << " [" << parks[i].state << "] " << "area: " << parks[i].area << endl;
    }
}

int main(int argc, char* argv[])
{
    Park bigPark[100];
    string line = ""; //initializes line as empty
    int arrIndex =0;
    string parkname;
    string state;
    string area;

    ifstream in_file;  //creates io stream name
    ofstream out_file;

    in_file.open(argv[2]); //opens file in in_file
    out_file.open(argv[3]); //opens file in out_file

    if(in_file.is_open())
    { //makes sure the file is open
        while (getline(in_file,line,','))
        {
            istringstream park2(line);
            if(line!="")
            {
                park2 >> parkname>>state>>area;

                if(stoi(area) >= stoi(argv[4]) && stoi(area) <= stoi(argv[5]))
                {
                    arrIndex++;
                    addPark(bigPark, parkname,state,stoi(area), arrIndex);
                    printList(bigPark,arrIndex);
                    out_file << parkname<<","<<state<<","<<area<<endl;
                }
            }
            arrIndex++;
        }
        in_file.close(); //closes file
        out_file.close(); //closes file
        
        
    }
    else if (!in_file.is_open())
        cout << "Failed to open the file." << endl;\
}