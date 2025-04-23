#ifndef PHARMACY_H
#define PHARMACY_H

#include <string>
#include <vector>

using namespace std;

class Pharmacy
{
private:
    vector<string> medications = {"None", "Antibiotic", "Anti-inflamatory", "Anti-nausea", "Inhalant", "Pain Relief"};
    vector<int> medicationCost = {0,20,17,38,66,35};

    // handeling
    int amount;
    int selection;

public:
    Pharmacy(/* args */);

    void readout();

    void Selection(int input);

    void amountSelect(int input);

    int medsCost();

    int getMedicationSize();

    ~Pharmacy();

};

#endif