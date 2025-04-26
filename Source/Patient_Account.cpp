#include "Patient_Account.h"

PatientAccount::PatientAccount() {}

PatientAccount::PatientAccount(string name, float rate, int stay)
{
    this->name = name;
    this->stay = stay;
    this->rate = rate;
};

void PatientAccount::setName(string input) { name = input; };

void PatientAccount::setStay(int input) { stay = input; };

void PatientAccount::setRate(float input) { rate = input; };

void PatientAccount::setExtraCost(float input) { extraCost = input; };

string PatientAccount::getName() { return name; };

int PatientAccount::getStay() { return stay; };

float PatientAccount::getRate() { return rate; };

float PatientAccount::getExtraCost() { return extraCost; };

PatientAccount::~PatientAccount() {};
