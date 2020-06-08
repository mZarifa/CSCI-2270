/****************************************************************/
/*                   Assignment 4 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
// you may include more libraries as needed
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

void displayMenu();
int choice, rotNum;
int state = 0;
string Cdelete, newCountry, prevCountry;
CountryNetwork CountryNet;

int main(int argc, char* argv[])
{
    // Object representing our network of cities.
    // (Linked list representation is in CountryNetwork)
    displayMenu();
    return 0;
}

/*
 * Purpose; displays a menu with options
 */

void displayMenu()
{
    while (state != 1)
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
    cin >> choice;
    if (choice == 1)
    {
      CountryNet.loadDefaultSetup();
      CountryNet.printPath();
    }
    if (choice == 2)
    {
      CountryNet.printPath();
    }
    if (choice == 3)
    {
      cout << "Enter a new country name:" << endl;
      cin.ignore();
      newCountry = "";
      getline (cin, newCountry);
      cout << "Enter the previous country name (or First):" << endl;
      prevCountry = "";
      getline (cin, prevCountry);
      if (prevCountry == "First")
      {
        CountryNet.insertCountry(NULL, newCountry);
      }
      if (CountryNet.searchNetwork(prevCountry) != 0 && prevCountry != "First")
      {
          CountryNet.insertCountry(CountryNet.searchNetwork(prevCountry), newCountry);
      }
      if (CountryNet.searchNetwork(prevCountry) == 0 && prevCountry != "First")
      {
      while (CountryNet.searchNetwork(prevCountry) == 0)
      {
        cout << "INVALID country...Please enter a VALID previous countryname:" << endl;
        getline (cin, prevCountry);
        CountryNet.searchNetwork(prevCountry);
        if (CountryNet.searchNetwork(prevCountry) != 0)
        {
          CountryNet.insertCountry(CountryNet.searchNetwork(prevCountry), newCountry);
        }
      }
    }
    CountryNet.printPath();
    }
    if (choice == 4)
    {
      cout << "Enter a country name: " << endl;
      cin.ignore();
      getline(cin, Cdelete);
      CountryNet.deleteCountry(Cdelete);
      CountryNet.printPath();
    }
    if (choice == 5)
    {
      CountryNet.reverseEntireNetwork();
      CountryNet.printPath();
    }
    if (choice == 6)
    {
      cout << "Enter the count of values to be rotated:" << endl;
      cin >> rotNum;
      CountryNet.rotateNetwork(rotNum);
      CountryNet.printPath();
    }
    if (choice == 7)
    {
      cout << "Network before deletion" << endl;
      CountryNet.printPath();
      CountryNet.deleteEntireNetwork();
      cout << "Network after deletion" << endl;
      CountryNet.printPath();
    }
    if (choice == 8)
    {
      cout << "Quitting... cleaning up path: " << endl;
      CountryNet.printPath();
      CountryNet.isEmpty();
      if(CountryNet.isEmpty() == true)
      {
        cout << "Path cleaned" << endl;
      }
      else if (CountryNet.isEmpty() == false)
      {
        CountryNet.deleteEntireNetwork();
        cout << "Path cleaned" << endl;
      }
      cout << "Goodbye!" << endl;
      state = 1;
    }
}
}
