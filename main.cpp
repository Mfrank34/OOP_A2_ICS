#include <iostream>
// classes
#include "Headers/Patient_Account.h"
#include "Headers/Pharmacy.h"
#include "Headers/Surgery.h"

void starGen(int amount){
    for (int i = 0; i < amount; i++)
    {
        cout << "*";
    }
    cout << endl;
}

using namespace std;
// Main
int main()
{
    starGen(20);
    cout << "Inpatient Checkout Menu" << endl;
    starGen(20);

    


    // end
    return 0;
}