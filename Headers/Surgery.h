#ifndef SURGERY_H
#define SURGERY_H

#include"Tables.h"
#include <string>
#include <vector>

using namespace std;

class Surgery : public Tables
{
private:
    vector<pair <string, float> > treatementData = {};
    int amount;
public:
    Surgery();

    void setTreatement(int input);

    vector<pair<string,float>> getData();

    void setAmount(int input);

    int getAmount();

    ~Surgery();
};

#endif