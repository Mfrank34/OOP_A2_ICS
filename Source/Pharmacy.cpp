#include "Pharmacy.h"
#include "Tables.h"
#include <string>
#include <vector>

using namespace std;

Pharmacy::Pharmacy()
{
    this-> tableData = {
        {"None", 0.00},
        {"Antibiotic", 20.00},
        {"Anti-inflamatory", 17.00},
        {"Anti-nausea", 38.00},
        {"Inhalant", 66.00},
        {"Pain Relief", 35.00}
    };
}

void Pharmacy::setMedication(int index)
{
    pair<string, float> select = tableData[index];
    pharmacyData.push_back(select);
}

void Pharmacy::setAmount(int input)
{
    amount = input;
}

vector<pair<string,float>> Pharmacy::getData()
{
    return pharmacyData;
}

int Pharmacy::getAmount()
{
    return amount;
}

Pharmacy::~Pharmacy()
{

}