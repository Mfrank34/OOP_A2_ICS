#ifndef PHARMACY_H
#define PHARMACY_H

#include <string>

using namespace std;

class Pharmacy
{
private:
    int locationSize = 4;
    string location[locationSize] = {"Cataract surgery", "Debridement", "Low back pain surgery", "Tonsillectomy"};

    int priceSize = 4;
    int Pricing[priceSize] = {1500, 180, 900, 2100};
    
public:
    Pharmacy(/* args */);
    ~Pharmacy();
};

#endif