#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <chrono>

#define MIN_TABLE_SIZE 10
using namespace std;
/*
 * Node Type Declaration
 */
enum EntryType
{
    Legitimate,
    Empty,
    Deleted
};
/*
 * Node Declaration
 */
struct HashNode
{
    int element;
    enum EntryType info;
};
/*
 * Table Declaration
 */
struct HashTable
{
    int size;
    HashNode *table;
};

bool isPrime(int n)
{
    if (n == 2 || n == 3)
        return true;
    if (n == 1 || n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}
int nextPrime(int n)
{
    if (n <= 0)
        n == 3;
    if (n % 2 == 0)
        n++;
    for (; !isPrime(n); n += 2)
        ;
    return n;
}
int hashCode(int key, int size)
{
    return key % size;
}
/*
 * Function to Initialize Table
 */
HashTable *initializeTable(int size)
{
    HashTable *htable;
    if (size < MIN_TABLE_SIZE)
    {
        cout << "Table Size Too Small" << endl;
        return NULL;
    }
    htable = new HashTable;
    if (htable == NULL)
    {
        cout << "Out of Space" << endl;
        return NULL;
    }
    htable->size = nextPrime(size);
    htable->table = new HashNode[htable->size];
    if (htable->table == NULL)
    {
        cout << "Table Size Too Small" << endl;
        return NULL;
    }
    for (int i = 0; i < htable->size; i++)
    {
        htable->table[i].info = Empty;
        htable->table[i].element = NULL;
    }
    return htable;
}
/*
 * Function to tableSearch Element at a key
 */
int tableSearch(int key, HashTable *htable)
{
    int pos = hashCode(key, htable->size);
    int collisions = 0;
    while (htable->table[pos].info != Empty &&
           htable->table[pos].element != key)
    {
        pos = pos + 2 * ++collisions - 1;
        if (pos >= htable->size)
            pos = pos - htable->size;
    }
    return pos;
}
/*
 * Function to tableInsert Element into a key
 */
void tableInsert(int key, HashTable *htable)
{
    int pos = tableSearch(key, htable);
    if (htable->table[pos].info != Legitimate)
    {
        htable->table[pos].info = Legitimate;
        htable->table[pos].element = key;
    }
}

#include "arrayHelper.hpp"

int main()
{
    int size, pos;
    HashTable *bigtable;
    size = 40009;
    bigtable = initializeTable(size);
    cout << "Size of Hash Table: " << nextPrime(size);
    arrayHelper dataSetA;
    arrayHelper dataSetB;
    float insert[400];
    float search[400];
    using namespace std::chrono;

    dataSetA.openAndRead("dataSetA.csv"); //see arrayHelper.cpp for information
    dataSetB.openAndRead("dataSetB.csv");

    int count = 0;
    float per100avg = 0;
    for (int i = 0; i < 40000; i++)
    {
        auto start = high_resolution_clock::now();
        tableInsert(dataSetA.getTestArray(i), bigtable);
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
        tableSearch(dataSetA.getTestArray(i), bigtable);
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

    string fileName = "quadhashexport.csv";
    ofstream out_File;
    out_File.open(fileName);
    out_File.clear();

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

    cout << fileName << "(quadHASHING) has been exported sucessfully." << endl;
    out_File.close();
}