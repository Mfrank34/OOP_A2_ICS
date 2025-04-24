#ifndef TABLES_H
#define TABLES_H

#include <vector>
#include <string>

using namespace std;

class Tables
{
protected:
    vector<string> item = {};
    vector<float> cost = {};
public:
    Tables();

    void createTable();

    ~Tables();
};

#endif