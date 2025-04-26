#include "Tables.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

Tables::Tables() {}; // create table class

void Tables::createTable()
{
    string costStr = " | Cost £"; // formating
    for (size_t i = 0; i < tableData.size(); ++i)
    {                                                               // loop though table data
        cout << left << setw(2) << i << ". "                        // create left
             << setw(24) << tableData[i].first                      // create middle
             << right << setw(10) << costStr << tableData[i].second // create right
             << endl;                                               // new line
    }
};

int Tables::getTableDataSize() { return tableData.size(); }; // returns the total size of table

Tables::~Tables() {}; // destroy table class
