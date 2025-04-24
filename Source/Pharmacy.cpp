#include "Pharmacy.h"
#include "Tables.h"
#include <iostream>

#include <vector>
#include <string>
#include <limits>

using namespace std;

Pharmacy::Pharmacy()
{
    this->item = {"None", "Antibiotic", "Anti-inflamatory", "Anti-nausea", "Inhalant", "Pain Relief"};
    this->cost = {0.00,20.00,17.00,38.00,66.00,35.00};
}

void Pharmacy::setMedication(int input)
{
    medication = input;
}

void Pharmacy::setAmount(int input)
{
    amount = input;
}

int Pharmacy::medsCost()
{
    return cost[medication] * amount;
}

int Pharmacy::getMedicationSize()
{
    return item.size();
}

Pharmacy::~Pharmacy()
{

}