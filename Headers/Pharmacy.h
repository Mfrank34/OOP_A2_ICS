#ifndef PHARMACY_H
#define PHARMACY_H

#include "Tables.h"
#include <string>
#include <vector>

using namespace std;

class Pharmacy : public Tables
{
private:
    vector <tuple<string, int, float>> treatementData = {};
    int amount;
public:
    Pharmacy();

    void setTreatement(int index);

    vector<tuple<string, int, float>> getData();
    
    void setAmount(int input);

    int getAmount();

    float getTreatementCost();

    ~Pharmacy();
};

#endif