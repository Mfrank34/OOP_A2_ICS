#include "Pharmacy.h"
#include "Tables.h"

using namespace std;

Pharmacy::Pharmacy()
{
    // storing information about pharmacy and cost of item
    this->tableData = {
        {"None", 0.00},
        {"Antibiotic", 20.00},
        {"Anti-inflamatory", 17.00},
        {"Anti-nausea", 38.00},
        {"Inhalant", 66.00},
        {"Pain Relief", 35.00}};
};

void Pharmacy::setTreatement(int index)
{
    pair<string, float> select = tableData[index];                             // select an item from tabledata,
    treatementData.push_back(make_tuple(select.first, amount, select.second)); // apends it to treatement data though name, amount, cost
};

vector<tuple<string, int, float>> Pharmacy::getData() { return treatementData; }; // hands over paired vector with string and float

void Pharmacy::setAmount(int input) { amount = input; }; // sets input

int Pharmacy::getAmount() { return amount; }; // sets amount

float Pharmacy::getTreatementCost()
{
    float totalCost;                                       // total cost
    for (tuple<string, int, float> items : treatementData) // loops though the cost of item
    {
        totalCost += (get<1>(items) * get<2>(items)); // get elements from second and third and multiples them together
    }
    return totalCost; // retunds cost
};

Pharmacy::~Pharmacy() {};
