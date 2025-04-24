#ifndef PHARMACY_H
#define PHARMACY_H

#include "Tables.h"
#include <string>
#include <vector>

using namespace std;

class Pharmacy : public Tables
{
private:
    int amount;
    int medication;

public:
    Pharmacy();

    void setMedication(int input);

    void setAmount(int input);

    int medsCost();

    int getMedicationSize();

    ~Pharmacy();

};

#endif