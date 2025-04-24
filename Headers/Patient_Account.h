#ifndef PATIENT_ACCOUNT_H
#define PATIENT_ACCOUNT_H

#include <string>

using namespace std;

class PatientAccount
{
private:
    string name;
    int stay;
    float rate;
    float extraCost;
public:
    PatientAccount();

    void setName(string input);

    void setStay(int input);

    void setRate(float input);

    void setExtraCost(float input);

    string getName();

    int getStay();

    float getRate();

    float getExtraCost();

    ~PatientAccount();

};

#endif