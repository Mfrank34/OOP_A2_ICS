#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class FileManager
{
private:
    string name;
    ostringstream fileData;
    // billing formation
public:
    FileManager();

    void createTable(vector<tuple<string, int, float>> data);

    void createTop(string name);

    void createBottom(float StayCost, float sCost, float pCost, float totalCost);

    void writeFile();

    ~FileManager();
};

#endif
