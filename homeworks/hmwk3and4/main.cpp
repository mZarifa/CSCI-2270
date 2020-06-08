/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

void displayMenu();
int state = 0;
string Cdelete, newCountry, prevCountry;
CountryNetwork CountryNet;

CountryNetwork CountryNet;

int main(int argc, char* argv[])
{
    displayMenu();
    // Object representing our network of cities.
    // (Linked list representation is in CountryNetwork)

    return 0;
}


/*
 * Purpose; displays a menu with options
 */
void displayMenu()
{
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Add Country " << endl;
    cout << " 4. Delete Country " << endl;
    cout << " 5. Reverse Network" << endl;
    cout << " 6. Rotate Network" << endl;
    cout << " 7. Clear Network " << endl;
    cout << " 8. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
    int input;
    cin >> input;

    if (input == 1)
    {
        CountryNet.loadDefaultSetup();
        cout << "== CURRENT PATH ==" << endl;
        CountryNet.printPath();
        cout << "===" << endl;
        displayMenu();
    }
    if (input == 2)
    {
        cout << "== CURRENT PATH ==" << endl;
        if(CountryNet.searchNetwork("United States") == NULL)
        {
            cout << "nothing in path" << endl;
            cout << "===" << endl;
            
        }
        else
        {
            CountryNet.printPath();
            cout << "===" << endl;
        }
        displayMenu();
    }

    if (input == 3)
    {
        string newCountry;
        string prevCountry;
        cout << "Enter a new country name:" << endl;
        cin >> newCountry;
        cout << "Enter the previous country name (or First):" << endl;
        cin.ignore();
        getline(cin, prevCountry);
        while(NULL == CountryNet.searchNetwork(prevCountry) && prevCountry != "First")
        {
            cout << "INVALID(previous country name)...Please enter a VALID previous country name!" << endl;
            getline(cin, prevCountry);
        }
        if(prevCountry == "First" || CountryNet.searchNetwork(prevCountry)->name == prevCountry)
        {
            Country* bigName;
            bigName = CountryNet.searchNetwork(prevCountry);
            CountryNet.insertCountry(bigName, newCountry);
            cout << "== CURRENT PATH ==" << endl;
            CountryNet.printPath();
            cout << "===" << endl;
        }
        displayMenu();
    }

    if (input == 8)
    {
        cout << "Quitting..." << endl;
        cout << "Goodbye!" << endl;
        return;
    }
}
