#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include <vector>
#include <stdio.h>
#include <chrono>
#include <unistd.h>
#include <thread>
#include "arrayHelper.hpp"
#include "BST.hpp"
#include "LL.hpp"

using namespace std::chrono;

BST BSTTest;
LL LLTest;
arrayHelper dataSetA;
arrayHelper dataSetB;

float insert[3][400];
float search[3][400]; //creating gloabal arrays for the insert and search arrays.

// float timeCheck (void *func, int index){
//     *count = 0;
//     float per100avg = 0;
//     for (int i = 0; i < 40000; i++)
//     {
//         auto start = high_resolution_clock::now();
//         func;
//         auto end = high_resolution_clock::now();
//         per100avg += duration_cast<nanoseconds>(end - start).count();
//         // cout << duration_cast<nanoseconds>(end - start).count() << endl;

//         if(i%100==0){
//             insert[index][*count] = per100avg/100;
//             (*count)++;
//             per100avg = 0;
//         }
//     }
// }

float BSTInsertTimeCheck(arrayHelper x)
{
    int count = 0;
    float per100avg = 0;
    for (int i = 0; i < 40000; i++)
    {
        auto start = high_resolution_clock::now();
        BSTTest.addNode(x.getTestArray(i));
        auto end = high_resolution_clock::now();
        per100avg += duration_cast<nanoseconds>(end - start).count();
        // cout << duration_cast<nanoseconds>(end - start).count() << endl;

        if (i % 100 == 0)
        {
            insert[0][count] = per100avg / 100;
            count++;
            per100avg = 0;
        }
    }
}

float BSTSearchTimeCheck(arrayHelper x)
{
    int count = 0;
    float per100avg = 0;
    for (int i = 0; i < 40000; i++)
    {
        auto start = high_resolution_clock::now();
        BSTTest.searchKey(x.getTestArray(i));
        auto end = high_resolution_clock::now();
        per100avg += duration_cast<nanoseconds>(end - start).count();
        // cout << duration_cast<nanoseconds>(end - start).count() << endl;

        if (i % 100 == 0)
        {
            search[0][count] = per100avg / 100;
            count++;
            per100avg = 0;
        }
    }
}

float LLInsertTimeCheck(arrayHelper x)
{
    int count = 0;
    float per100avg = 0;
    for (int i = 0; i < 40000; i++)
    {
        auto start = high_resolution_clock::now();
        LLTest.addNode(x.getTestArray(i));
        auto end = high_resolution_clock::now();
        per100avg += duration_cast<nanoseconds>(end - start).count();
        // cout << duration_cast<nanoseconds>(end - start).count() << endl;

        if (i % 100 == 0)
        {
            insert[1][count] = per100avg / 100;
            count++;
            per100avg = 0;
        }
    }
}

float LLSearchTimeCheck(arrayHelper x)
{
    int count = 0;
    float per100avg = 0;
    for (int i = 0; i < 40000; i++)
    {
        auto start = high_resolution_clock::now();
        LLTest.searchList(x.getTestArray(i));
        auto end = high_resolution_clock::now();
        per100avg += duration_cast<nanoseconds>(end - start).count();
        // cout << duration_cast<nanoseconds>(end - start).count() << endl;

        if (i % 100 == 0)
        {
            search[1][count] = per100avg / 100;
            count++;
            per100avg = 0;
        }
    }
}


int main()
{
    dataSetA.openAndRead("dataSetA.csv"); //see arrayHelper.cpp for information
    dataSetB.openAndRead("dataSetB.csv");
    cout << "-----------------------------------------------------------------------------------" << endl;
    cout << endl;

    //----------------------------------------------------------------------------------------------------------
    //-----------------------------------------[INSERT/SEARCH DATA STRUCTURE]------------------------------------------
    //----------------------------------------------------------------------------------------------------------

    cout << "BST Insert (DATA SET A): " << BSTInsertTimeCheck(dataSetA) << " Nanoseconds" <<endl;
    cout << "BST Search (DATA SET A): " << BSTSearchTimeCheck(dataSetA) << " Nanoseconds" <<endl;
    cout << "LL Insert (DATA SET A): " << LLInsertTimeCheck(dataSetA) << " Nanoseconds" <<endl;
    cout << "LL Search (DATA SET A): " << LLSearchTimeCheck(dataSetA) << " Nanoseconds" <<endl;
    
    cout << "Finished DATA SET A Tests." << endl;
    //----------------------------------------------------------------------------------------------------------
    //-----------------------------------------[EXPORT DATA A]----------------------------------------------------
    //----------------------------------------------------------------------------------------------------------
    // LLTest.printList();
    
    string fileName = "exportedData.csv";
    ofstream out_File;
    out_File.open(fileName);
    out_File.clear();
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 400; j++){
            out_File << insert[i][j] <<",";
        }
        out_File << endl;
    }
    out_File << endl;

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 400; j++){
            out_File << search[i][j]<<",";
        }
        out_File << endl;
    }
    out_File << endl;
    cout << fileName << "(DATA A) has been exported sucessfully." << endl;
    
    
    cout << "-----------------------------------------------------------------------------------" << endl;
    cout << endl;

    cout << "BST Insert (DATA SET B): " << BSTInsertTimeCheck(dataSetB) << " Nanoseconds" <<endl;
    cout << "BST Search (DATA SET B): " << BSTSearchTimeCheck(dataSetB) << " Nanoseconds" <<endl;
    cout << "LL Insert (DATA SET B): " << LLInsertTimeCheck(dataSetB) << " Nanoseconds" <<endl;
    cout << "LL Search (DATA SET B): " << LLSearchTimeCheck(dataSetB) << " Nanoseconds" <<endl;
    
    cout << "Finished DATA SET B Tests." << endl;

    //----------------------------------------------------------------------------------------------------------
    //-----------------------------------------[EXPORT DATA B]----------------------------------------------------
    //----------------------------------------------------------------------------------------------------------

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 400; j++){
            out_File << insert[i][j] <<",";
        }
        out_File << endl;
    }
    out_File << endl;

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 400; j++){
            out_File << search[i][j]<<",";
        }
        out_File << endl;
    }
    cout << fileName << "(DATA B) has been exported sucessfully." << endl;
    out_File.close();
}
