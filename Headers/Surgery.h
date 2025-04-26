#ifndef SURGERY_H
#define SURGERY_H

#include "Tables.h"
#include <string>
#include <vector>

using namespace std;

class Surgery : public Tables
{
private:
    vector<tuple<string, int, float>> treatementData = {};
    int amount;

public:
    Surgery();

    void setTreatement(int input);

    vector<tuple<string, int, float>> getData();

    void setAmount(int input);

    int getAmount();

    float getTreatementCost();

    ~Surgery();
};

#endif