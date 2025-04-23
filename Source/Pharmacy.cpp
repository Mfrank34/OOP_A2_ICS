#include "Pharmacy.h"
#include <iostream>

Pharmacy::Pharmacy()
{
}

void Pharmacy::readout()
{
    cout << "Which type of surgery has been performed?" << endl;
    for (int i; i < surgeryPerformed.size(); i++)
    {
        cout << i << "." << surgeryPerformed[i] << "-" << prices[i] << endl;
    }
}

void Pharmacy::selection()
{
    // need error checking mike!
    int userinput;
    cout << "Choose a type of Surgery (0-4): ";
    cin >> userinput;
    // user input
    userinput = userSelect; 
}

int Pharmacy:: surgeryCost()
{
    return prices[userSelect];
}

Pharmacy::~Pharmacy()
{
}
