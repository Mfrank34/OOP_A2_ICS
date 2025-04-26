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
public:
    PatientAccount();

    PatientAccount(string name, float rate, int stay);

    void setName(string input);

    void setStay(int input);

    void setRate(float input);

    string getName();

    int getStay();

    float getRate();

    float getStayAmount();

    ~PatientAccount();

};

#endif