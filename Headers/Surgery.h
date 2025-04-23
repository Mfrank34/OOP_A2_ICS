#ifndef SURGERY_H
#define SURGERY_H

#include <string>
#include <vector>

using namespace std;

class Surgery
{
private:
    vector<string> medications = {"None", "Antibiotic", "Anti-inflamatory", "Anti-nausea", "Inhalant", "Pain Relief"};
    vector<int> medicationCost = {0,20,17,38,66,35};

    // handeling
    int amount;
    int selection;

public:
    Surgery(/* args */);

    void readout();

    void Selection();

    void amountSelect();

    int medsCost();

    ~Surgery();
};

#endif