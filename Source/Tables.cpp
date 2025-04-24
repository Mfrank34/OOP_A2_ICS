#include "Tables.h"
#include <iostream>
#include <iomanip>

using namespace std;

Tables::Tables() {};

void Tables::createTable() {
    string costStr = " | Cost £";
    for (size_t i = 0; i < tableData.size(); ++i) {
        cout << left << setw(2) << i << ". "
             << setw(24) << tableData[i].first
             << right << setw(10) << costStr << tableData[i].second
             << endl;
    }
};

int Tables::getTableDataSize()
{
    return tableData.size();
};

Tables::~Tables() {};
