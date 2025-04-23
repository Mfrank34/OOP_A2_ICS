#ifndef SURGERY_H
#define SURGERY_H

#include <string>
#include <vector>

using namespace std;

class Surgery
{
private:
    // storing information about the class
    vector<string> surgeryPerformed = {"None", "Cataract surgery", "Debridement", "Low back pain surgery", "Tonsillectomy"};
    vector<int> prices = {0, 1500, 180, 900, 2100};

    // user data
    int surgery;
public:
    Surgery();

    void readout(); // display surgerys

    void setSurgery(int input); // user select screen

    int surgeryCost(); // return cost of surgerys

    int getTreatmentSize();

    ~Surgery();
};

#endif