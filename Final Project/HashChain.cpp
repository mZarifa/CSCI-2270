#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <chrono>
using namespace std;

struct HashNode
{
  int key;
  HashNode *next; //create structure

  HashNode()
  {
    key = 0;
    next = 0;
  }
  HashNode(int k)
  {
    key = k;
    next = 0; //define next node and nodes value
  }
  ~HashNode() {}
};

class HashTable
{
private:
  HashNode **table; //create hashtable class
  int size;

public:
  HashTable()
  {
    size = 40009;
    table = new HashNode *[40009];
    for (int i = 0; i < size; i++)
      table[i] = 0; //define table size of 400009
  }

  HashTable(int s)
  {
    size = s;
    table = new HashNode *[s];
    for (int i = 0; i < size; i++) //define a custom size i guess dude
      table[i] = 0;
  }

  ~HashTable()
  {
    for (int i = 0; i < size; i++)
    {
      HashNode *tmp = table[i];
      while (tmp != 0)
      {
        HashNode *curr = tmp;
        tmp = tmp->next;
        delete curr; //set up the table
      }
    }
    delete[] table; //delete the trash
  }

  void insert(int key) //function for key insertion
  {
    HashNode *node = new HashNode(key); //create new node
    int index = hashCode(key, size);    //run the key value through the hash function to turn it into its index value

    if (table[index] == 0)
      table[index] = node; //if the index is 0, that is the node
    else
    {
      node->next = table[index]; //else the next node is now that index value
      table[index] = node;       //set that index value to that node
    }
  }

  HashNode *search(int key) //search function shit
  {
    int index = hashCode(key, size); //run the hash function to get the index value

    if (table[index] == 0) //if its 0, return 0 cuz that bad
      return 0;
    else
    {
      HashNode *curr = table[index]; //run through the table and try and find the hash value
      while (curr != 0)
      {
        if (curr->key == key)
          return curr;
        else
          curr = curr->next;
      }
      return 0;
    }
  }

  int hashCode(int k, int table_size) //this is the actual hash stuff
  {
    int hash = 0;
    hash = hash + k;
    return hash % table_size;
  }
};

#include "arrayHelper.hpp"

int main() //this is some sphagetti code, so hold on tight
{
  arrayHelper dataSetA;
  arrayHelper dataSetB;
  HashTable bigtable(40009); //create the table, use the arrayHelper file to set up the data sets.
  float insert[400];
  float search[400];
  using namespace std::chrono;

  dataSetA.openAndRead("dataSetA.csv"); //READ THAT 
  dataSetB.openAndRead("dataSetB.csv");

  int count = 0;
  float per100avg = 0; //create a counter and average value
  for (int i = 0; i < 40000; i++)
  {
    auto start = high_resolution_clock::now();
    bigtable.insert(dataSetA.getTestArray(i));
    auto end = high_resolution_clock::now();
    per100avg += duration_cast<nanoseconds>(end - start).count();
    // cout << duration_cast<nanoseconds>(end - start).count() << endl; time that stuff
    if (i % 100 == 0)
    {
      insert[count] = per100avg / 100;
      count++;
      per100avg = 0; //thats the number dummy
    }
  }

  count = 0;
  per100avg = 0;
  for (int i = 0; i < 40009; i++) //run it again, this is for the serach now. Literally the same for loop. 
  {
    auto start = high_resolution_clock::now();
    bigtable.search(dataSetA.getTestArray(i));
    auto end = high_resolution_clock::now();
    per100avg += duration_cast<nanoseconds>(end - start).count();
    // cout << duration_cast<nanoseconds>(end - start).count() << endl;
    if (i % 100 == 0)
    {
      search[count] = per100avg / 100;
      count++;
      per100avg = 0;
    }
  }

  string fileName = "HashChain.csv"; //create the hashChain.csv file for easy export
  ofstream out_File;
  out_File.open(fileName);
  out_File.clear(); //clear the file if there is one

  for (int j = 0; j < 400; j++)
  {
    out_File << insert[j] << ","; //output the file using this for loop since there are 400 data points
  }
  out_File << endl;

  for (int j = 0; j < 400; j++)
  {
    out_File << search[j] << ","; //same but for search function
  }
  out_File << endl;

  cout << fileName << "(HASHING A ) has been exported sucessfully." << endl; //output to terminal

  count = 0;
  per100avg = 0;

  //THIS IS THE SAME TWO FOR LOOPS BUT NOW ITS DATA SET B. 

  for (int i = 0; i < 40000; i++)
  {
    auto start = high_resolution_clock::now(); 
    bigtable.insert(dataSetB.getTestArray(i));
    auto end = high_resolution_clock::now();
    per100avg += duration_cast<nanoseconds>(end - start).count();
    // cout << duration_cast<nanoseconds>(end - start).count() << endl;
    if (i % 100 == 0)
    {
      insert[count] = per100avg / 100;
      count++;
      per100avg = 0;
    }
  }

  count = 0;
  per100avg = 0;
  for (int i = 0; i < 40009; i++)
  {
    auto start = high_resolution_clock::now();
    bigtable.search(dataSetB.getTestArray(i));
    auto end = high_resolution_clock::now();
    per100avg += duration_cast<nanoseconds>(end - start).count();
    // cout << duration_cast<nanoseconds>(end - start).count() << endl;
    if (i % 100 == 0)
    {
      search[count] = per100avg / 100;
      count++;
      per100avg = 0;
    }
  }

  for (int j = 0; j < 400; j++)
  {
    out_File << insert[j] << ",";
  }
  out_File << endl;

  for (int j = 0; j < 400; j++)
  {
    out_File << search[j] << ",";
  }
  out_File << endl;

  cout << fileName << "(HASHING B)has been exported sucessfully." << endl;

  out_File.close();
}
