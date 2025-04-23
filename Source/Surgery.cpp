#include "Surgery.h"
#include <iostream>

#include <vector>
#include <string>

using namespace std;

Surgery::Surgery()
{
}

void Surgery::readout()
{
    for (int i; i < medications.size(); i++)
    {
        cout << i << "." << medications[i] << "-" << medicationCost[i] << endl;
    };
}

void Surgery::Selection()
{
    // need error checking mike!
    int userinput;
    cout << "Choose a type of Surgery (0-4): ";
    cin >> userinput;
    // user input
    userinput = selection;
}

void Surgery::amountSelect()
{
    // need error checking mike!
    int userinput;
    cout << "Choose a type of Surgery (0-4): ";
    cin >> userinput;
    // user input
    userinput = amount;
}

int Surgery::medsCost()
{
    return medicationCost[selection] * amount;
}

Surgery::~Surgery()
{
}