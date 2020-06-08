//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include <vector>
#include <stdio.h>

#include"MovieTree.hpp"

using namespace std;

int main()
{
ifstream inFile;

int ranking;
string title;
int year;
float rating;
MovieTree movies;
movies.addMovieNode(6,"Pulp Fiction",1994,8.9);
movies.addMovieNode(55,"Casablanca",1942,8.5);
movies.addMovieNode(1,"Shawshank Redemption",1994,9.3);
movies.addMovieNode(50,"Apocalypse Now",1979,8.5);
movies.addMovieNode(11,"Fight Club",1999,8.8);
movies.addMovieNode(49,"Raiders of the Lost Ark",1981,8.5);
movies.addMovieNode(4,"The Godfather",1972,9.2);
movies.printMovieInventory();
return 0;
}

// inFile.open("Movies.csv");
// if (inFile.is_open())
// {
//     cout << "File has been opened" << endl;
// }
// else
// {
//     cout << "NO FILE HAS BEEN OPENED" << endl;
// }
//
//
// //while (!inFile.eof())
// //{
//   for (int i = 0; i < 4; i++)
//   {
//     getline (inFile, ranking);
//     getline (inFile, title);
//     getline (inFile, year);
//     inFile >> rating;
//     cout << "ranking: " << ranking;
//     cout << " title: " << title;
//     cout << " year: " << year;
//     cout << " rating: " << rating << endl;
//   }
// //}
// inFile.close();
// system("pause");
