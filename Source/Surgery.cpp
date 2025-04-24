#include "Surgery.h"
#include "Tables.h"
#include <vector>
#include <map>

using namespace std;

Surgery::Surgery()
{
    this-> tableData = {
        {"None", 0},
        {"Cataract surgery", 1500},
        {"Debridement", 180},
        {"Low back pain surgery", 900},
        {"Tonsillectomy", 2100}
    };
}

void Surgery::setSurgery(int index)
{
    pair<string, float> select = tableData[index];
    surgeryData.push_back(select);
}

vector<pair<string,float>> Surgery::getData()
{
    return surgeryData;
}

int Surgery:: getCost()
{
    return 0;
}

string Surgery:: getName()
{
    return "hi";
}

Surgery::~Surgery()
{

}
