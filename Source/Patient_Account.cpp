#include "Patient_Account.h"

PatientAccount::PatientAccount() {}

PatientAccount::PatientAccount(string name, float rate, int stay)
{
    this->name = name;
    this->stay = stay;
    this->rate = rate;
};

void PatientAccount::setName(string input) { name = input; }; // set input for name

void PatientAccount::setStay(int input) { stay = input; }; // set input for stay

void PatientAccount::setRate(float input) { rate = input; }; // really do i need to explain this???

string PatientAccount::getName() { return name; };

int PatientAccount::getStay() { return stay; };

float PatientAccount::getRate() { return rate; };

float PatientAccount::getStayAmount() { return (rate * stay); }; // rate is float, stay is interger times them for stay cost

PatientAccount::~PatientAccount() {};
