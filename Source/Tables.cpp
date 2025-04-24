#include "Tables.h"
#include <iostream>

using namespace std;

Tables::Tables(){};

Tables::~Tables(){}

void Tables::createTable()
{
    for (int index; index < item.size(); index++)
    {
        cout << index << ". " << item[index] << "| Cost: " << cost[index] << endl;
    } 
}