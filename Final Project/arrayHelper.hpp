#ifndef ARRAYHELPER_H
#define ARRAYHELPER_H

using namespace std;

class arrayHelper
{
public:
    arrayHelper();
    void setTestArray(int, int);
    int getTestArray(int);
    void openAndRead(string); //opens and reads the filename
    void outputArray();

private:
    int testDataArray[40009]; //public testDataArray for easy access.
};
#endif