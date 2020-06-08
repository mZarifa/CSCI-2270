#include "MovieTree.hpp"
#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include <vector>
#include <stdio.h>
#include <sstream>
using namespace std;

static void printMovieInventoryHelper(MovieNode* node);
MovieNode* search(string title, MovieNode* node);
MovieNode* queryMoviesHelper(float rating,int year, MovieNode* node);
float averageRatingHelper(MovieNode* node);
int movieCounter(MovieNode* node);

MovieTree::MovieTree()
{
  root = nullptr;
}

void MovieTree::printMovieInventory()
{
   if (root == nullptr)
   {
     cout << "Tree is Empty. Cannot print" << endl;
   }
   else
   {
   printMovieInventoryHelper(root);
   }
}

static void printMovieInventoryHelper(MovieNode* node)
{
    if (node->left != nullptr)
   {
      printMovieInventoryHelper(node->left);
   }
   cout << "Movie: " << node -> title << " " << node->rating << endl;
   if (node -> right != nullptr)
   {
     printMovieInventoryHelper(node->right);
   }
}


void MovieTree::addMovieNode(int ranking, string title, int year, float rating)
{
  MovieNode* movie = new MovieNode(ranking, title, year, rating);
  movie -> ranking = ranking;
  movie -> title = title;
  movie -> year = year;
  movie -> rating = rating;
  movie -> left = nullptr;
  movie -> right = nullptr;
  if (root == nullptr)
  {
    root = movie;
  }
  else
  {
    MovieNode* foundMovie = root;
    while (foundMovie != nullptr)
    {
      if(title.compare(foundMovie -> title) < 0)
      {
        if(foundMovie -> left != nullptr)
        {
          foundMovie = foundMovie -> left;
        }
        else
        {
          foundMovie -> left = movie;
          foundMovie = nullptr;
        }
      }
      else
      {
        if(foundMovie-> right != NULL)
        {
          foundMovie = foundMovie -> right;
        }
        else
        {
          foundMovie -> right = movie;
          foundMovie = nullptr;
        }
      }
    }
  }
}


void MovieTree::findMovie(string title)
{
  MovieNode* foundMovie = search(title, root);
  if(foundMovie == nullptr)
  {
    cout << "Movie not found." << endl;
    return;
  }
  else
  {
    cout << "Movie Info:" << endl;
    cout << "==================" << endl;
    cout << "Ranking:" << foundMovie -> ranking << endl;
    cout << "Title :" << foundMovie -> title << endl;
    cout << "Year  :"  << foundMovie -> year << endl;
    cout << "rating :" << foundMovie -> rating << endl;
    }
}

MovieNode* search(string title, MovieNode* node)
{
  MovieNode* foundMovie = node;
  while (foundMovie != nullptr)
  {
    if (title.compare(foundMovie -> title) < 0)
    {
      foundMovie = foundMovie -> left;
    }
    else if (title.compare(foundMovie -> title) > 0)
    {
      foundMovie = foundMovie -> right;
    }
    else if (title.compare(foundMovie -> title) == 0)
    {
      break;
      }
  }
  return foundMovie;
}

void MovieTree::queryMovies(float rating, int year)
{
  if (root == nullptr)
  {
    cout << "Tree is Empty. Cannot query Movies" << endl;
  }
  else
  {
    cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
    MovieNode* foundMovie = queryMoviesHelper(rating, year, root);
  }
}

MovieNode* queryMoviesHelper(float rating, int year, MovieNode* node)
{
  if (node->left != nullptr)
  {
    queryMoviesHelper(rating, year, node->right);
  }
  if (node -> rating > rating && node -> year > year)
  {
    cout << node->title << "(" << node->year << ") " << node->rating << endl;
  }
  if (node -> right != nullptr)
  {
    queryMoviesHelper(rating, year, node->right);
  }
  return;
}


void MovieTree::averageRating()
{
  if (root == nullptr)
  {
    cout << "Average Rating:0.0" << endl;
  }
  else
  {
    int numMovies = movieCounter(root);
    float totRating = averageRatingHelper(root);
    float avgRating;
    cout << "Average Rating:" << totRating/numMovies << endl;
  }
}

float averageRatingHelper(MovieNode* node)
{
  if (node == nullptr)
  {
    return 0;
  }
  else
  {
    return (node->rating + averageRatingHelper(node->left) + averageRatingHelper(node->right));
  }
}

int movieCounter(MovieNode* node)
{
  if(node == nullptr)
  {
    return 0;
  }
  else
  {
    return (movieCounter(node->left) + movieCounter(node->right) + 1);
  }
}
