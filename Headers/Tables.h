#ifndef TABLES_H
#define TABLES_H

#include <vector>
#include <string>

using namespace std;

class Tables
{
protected:
    // information for tables
    vector<pair<string, float>> tableData = {};

public:
    Tables();

    void createTable();

    int getTableDataSize();

    ~Tables();
};

#endif