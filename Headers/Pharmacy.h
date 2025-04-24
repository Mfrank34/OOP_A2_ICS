#ifndef PHARMACY_H
#define PHARMACY_H

#include "Tables.h"
#include <string>
#include <vector>

using namespace std;

class Pharmacy : public Tables
{
private:
    // mediaction data
    vector <pair <string, float> > pharmacyData = {};
    // amount information
    int amount;
public:
    Pharmacy();

    void setMedication(int index);

    vector<pair<string,float>> getData();
    
    void setAmount(int input);

    int getAmount();

    ~Pharmacy();

};

#endif