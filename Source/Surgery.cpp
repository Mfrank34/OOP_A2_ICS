#include "Surgery.h"
#include <iostream>

Surgery::Surgery()
{
    
}

void Surgery::readout()
{
    for (int i; i < surgeryPerformed.size(); i++)
    {
        cout << i << "." << surgeryPerformed[i] << "-" << prices[i] << endl;
    }
}

void Surgery::setSurgery(int input)
{
    surgery = input;
}

int Surgery:: surgeryCost()
{
    return prices[surgery];
}


int Surgery::getTreatmentSize()
{
    return surgeryPerformed.size();
}

Surgery::~Surgery()
{
}
