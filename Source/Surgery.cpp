#include "Surgery.h"
#include "Tables.h"

using namespace std;

Surgery::Surgery()
{
    // set table data readout
    this->tableData = {
        {"None", 0},
        {"Cataract surgery", 1500},
        {"Debridement", 180},
        {"Low back pain surgery", 900},
        {"Tonsillectomy", 2100}};
}

void Surgery::setTreatement(int index) // sets treatement data
{
    pair<string, float> select = tableData[index];                             // select an item from tabledata,
    treatementData.push_back(make_tuple(select.first, amount, select.second)); // apends it to treatement data, name, amount, cost
}

vector<tuple<string, int, float>> Surgery::getData() { return treatementData; } // hands over paired vector with string and float

void Surgery::setAmount(int input) { amount = input; } // sets amount

int Surgery::getAmount() { return amount; } // return amount

float Surgery::getTreatementCost()
{
    float totalCost;                                       // total cost
    for (tuple<string, int, float> items : treatementData) // loops though the cost of item
    {
        totalCost += (get<1>(items) * get<2>(items)); // get elements from second and third and multiples them together
    }
    return totalCost; // retunds cost
};

Surgery::~Surgery() {}
