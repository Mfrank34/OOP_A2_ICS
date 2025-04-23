#include "Pharmacy.h"
#include <iostream>

#include <vector>
#include <string>
#include <limits>

using namespace std;

Pharmacy::Pharmacy()
{
}

void Pharmacy::readout()
{
    for (int i; i < medications.size(); i++)
    {
        cout << i << "." << medications[i] << "-" << medicationCost[i] << endl;
    };
}

void Pharmacy::Selection(int input)
{
    selection = input;
}

void Pharmacy::amountSelect(int input)
{
    amount = input;
}

int Pharmacy::medsCost()
{
    return medicationCost[selection] * amount;
}

int Pharmacy::getMedicationSize()
{
    return medications.size();
}

Pharmacy::~Pharmacy()
{

}