#ifndef PHARMACY_H
#define PHARMACY_H

#include "Tables.h"
#include <string>
#include <vector>

using namespace std;

class Pharmacy : public Tables
{
private:
    vector <pair <string, float> > treatementData = {};
    int amount;
public:
    Pharmacy();

    void setTreatement(int index);

    vector<pair<string,float>> getData();
    
    void setAmount(int input);

    int getAmount();

    ~Pharmacy();
};

#endif