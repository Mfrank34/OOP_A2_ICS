#ifndef SURGERY_H
#define SURGERY_H

#include"Tables.h"
#include <string>
#include <vector>

using namespace std;

class Surgery : public Tables
{
private:
    // user data
    vector<pair <string, float> > surgeryData = {};

public:
    Surgery();

    void setSurgery(int input); // user select screen

    vector<pair<string,float>> getData();

    int getCost(); // return cost of surgerys

    string getName();

    ~Surgery();
};

#endif