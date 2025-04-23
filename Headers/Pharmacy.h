#ifndef PHARMACY_H
#define PHARMACY_H

#include <string>
#include <vector>

using namespace std;

class Pharmacy
{
private:
    // storing information about the class
    vector<string> surgeryPerformed = {"None","Cataract surgery", "Debridement", "Low back pain surgery", "Tonsillectomy"};
    vector<int> prices = {0,1500, 180, 900, 2100};

    // user data 
    int userSelect;
public:
    Pharmacy();

    void readout(); // display surgerys

    void selection(); // user select screen

    int surgeryCost(); // return cost of surgerys

    ~Pharmacy(); 


};

#endif