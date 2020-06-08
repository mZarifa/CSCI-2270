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

struct wordItem
{
  string word;
  int count;
};

void getStopWords(const char *ignoreWordFileName, string ignoreWords[]);

bool isStopWord(string word, string ignoreWords[]);

int getTotalNumberNonStopWords(wordItem uniqueWords[], int length);

void arraySort(wordItem uniqueWords[], int length);

void printNext10(wordItem uniqueWords[], int N, int totalNumWords);

void enlarge(int *&array, int size);

int totalNumWords = 0;

void getStopWords(const char *ignoreWordFileName, string ignoreWords[])
{
  ifstream ignorefile;
  ignorefile.open(ignoreWordFileName);
  if (!ignorefile)
  {
    cout << "Failed to open " << ignoreWordFileName << endl;
  }
  string tempLine;
  int i = 0;
  while (getline(ignorefile, tempLine))
  {
    ignoreWords[i] = tempLine;
    i++;
  }
  ignorefile.close();
}

bool isStopWord(string word, string ignoreWords[])
{
  for (int i = 0; i < 50; i++)
  {
    if (ignoreWords[i] == word)
    {
      return true;
    }
  }
  return false;
}

int getTotalNumberNonStopWords(wordItem uniqueWords[], int length)
{
  int total = 0;
  for (int i = 0; i < length; i++)
  {
    total += uniqueWords[i].count;
  }
  return total;
}

void arraySort(wordItem uniqueWords[], int length)
{
  for (int i = 0; i < length; i++)
  {
    for (int j = i + 1; j < length; j++)
    {
      if (uniqueWords[i].count < uniqueWords[j].count)
      {
        wordItem placeholder = uniqueWords[i];
        uniqueWords[i] = uniqueWords[j];
        uniqueWords[j] = placeholder;
      }
    }
  }
}

void printNext10(wordItem uniqueWords[], int startRank, int totalNumWords)
{
  cout << "Probability of next 10 words from rank " << startRank << endl;
  cout << "---------------------------------------" << endl;
  for (int i = startRank; i < startRank + 10; i++)
  {
    float prob = (float)uniqueWords[i].count / totalNumWords;
    cout << fixed << setprecision(4) << prob << " - " << uniqueWords[i].word << endl;
  }
}

int main(int argc, char const *argv[])
{
  int length = 100;
  int total = 0;
  int value = 0;
  int countdouble;
  string ignore[50];
  getStopWords(argv[3], ignore);
  string read;

  bool found;
  //second argument file
  ifstream myfile(argv[2]);
  wordItem *wArray = new wordItem[length];
  //write to the array
  if (myfile.is_open())
  {
    // read and stores
    while (myfile >> read)
    {
      if (isStopWord(read, ignore) == false)
      {
        total++;
        found = false;
        for (int i = 0; i < value; i++)
        {
          if (wArray[i].word == read)
          {
            wArray[i].count++;
            found = true;
            break;
          }
        }
        if (found == false)
        {
          wArray[value].word = read;
          wArray[value].count = 1;
          value++;
        }
        if (value == length)
        {
          countdouble++;
          length = length * 2;
          wordItem *wArray2 = new wordItem[length];
          //copy values into new array of new size
          for (int k = 0; k < length / 2; k++)
          {
            wArray2[k].word = wArray[k].word;
            wArray2[k].count = wArray[k].count;
          }
          delete[] wArray;
          wArray = wArray2;
        }
      }
    }
  }
  getTotalNumberNonStopWords(wArray, value);
  arraySort(wArray, value);
  cout << "Array doubled: " << countdouble << endl;
  cout << "#" << endl;
  cout << "Unique non-common words: " << value << endl;
  cout << "#" << endl;
  cout << "Total non-common words: " << total << endl;
  cout << "#" << endl;
  printNext10(wArray, stoi(argv[1]), total);
  return 0;
}
