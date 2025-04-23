#ifndef PATIENT_ACCOUNT_H
#define PATIENT_ACCOUNT_H

#include <string>

class PatientAccount
{
private:
    int total_stay;
    int room_rate;
    int extra_cost; 
    
public:
    PatientAccount();

    // setting total stay.
    void set_total_stay(int days);
    // setting room rate.
    void set_room_rate(int rate);
    // display different items.
    int return_total_stay();

    int return_room_rate();

    void add_extra_cost(int extra);

    int return_extra_cost();

    int return_total_cost();

    ~PatientAccount();

};

#endif