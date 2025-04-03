#include "Patient_Account.h"
#include <iostream>

PatientAccount::PatientAccount()
{

}

void PatientAccount::set_total_stay(int days)
{
    total_stay = days;
}

void PatientAccount :: set_room_rate(int rate)
{
    room_rate = rate;
}

int PatientAccount:: return_room_rate()
{
    return room_rate;
}

int PatientAccount:: return_total_stay()
{
    return total_stay;
}

void PatientAccount:: add_extra_cost(int extra)
{
    extra_cost += extra;
}

int PatientAccount:: return_extra_cost()
{
    return extra_cost; 
}

int PatientAccount:: return_total_cost()
{
    return (room_rate * total_stay) + extra_cost;
}

PatientAccount::~PatientAccount()
{

}

