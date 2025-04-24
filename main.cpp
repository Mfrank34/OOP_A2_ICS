#include <iostream>
#include <limits>

// classes
#include "Headers/Patient_Account.h"
#include "Headers/Pharmacy.h"
#include "Headers/Surgery.h"

using namespace std;

void charGen(string length, char placeholder = '*')
// gets the length of string, and placeholder to make line same length as inputed string
{
    cout << string(length.size(), placeholder) << endl;
}

int errorHandingRange(int range)
// an errorHandler that deals with range items starting from 0 to range.
{
    int input;
    while (!(cin >> input) || input < 0 || input > range)
    {
        if (0 > input && input < range)
        {
            cout << "Enter number between 0 - " << range << ": ";
        }
        else
        {
            cout << "Invalid input. Enter numbers: ";
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    // user input
    return input;
}

int errorHanding()
{
    // number handler
    int input;
    while (!(cin >> input))
    {
        cout << "Invalid input. Enter numbers: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    // user input
    return input;
}

void dataRead(vector<pair<string, float>> data)
{
    for (const auto & items : data)
    {
        cout << items.first << " | " << items.second << endl;
    }
}

void title()
{
    string title = "Inpatient Checkout Menu";
    charGen(title);
    cout << title << endl;
    charGen(title);
}

void surgeryScreen(Surgery& surgery)
{
    string surgeryMessage = "Which type of surgery has been performed?";
    surgery.createTable();
    charGen(surgeryMessage, '-');

    // surgery input
    string SurgeryInputMessage = "Choose a type of Surgery (0-4): ";
    cout << SurgeryInputMessage;

    // selecting surgery...
    int surgerySelect;
    surgerySelect = errorHandingRange(surgery.getTableDataSize());

    // make it handel multiple selects
    surgery.setSurgery(surgerySelect);

    // edit remove before sub
    dataRead(surgery.getData());
}

void pharmacyScreen(Pharmacy& pharmacy)
{
    string pharmacyMessage = "which follow-up medication has been given?";
    // formating
    charGen(pharmacyMessage, '-');
    cout << pharmacyMessage << endl;

    // pharmacy readout
    pharmacy.createTable();
    charGen(pharmacyMessage, '-');

    // pharmacy select
    string pharmacyInputMessage = "Choose a type of mediation (0-5): ";
    cout << pharmacyInputMessage;

    int pharmacySelect;
    pharmacySelect = errorHandingRange(pharmacy.getTableDataSize()); // yes i could saved it verable...
    pharmacy.setMedication(pharmacySelect);
    charGen(pharmacyInputMessage, '-');

    // edit remove before sub
    dataRead(pharmacy.getData());

    // pharmacy amount
    string pharmacyAmountInputMessage = "Select amount of medications: ";
    cout << pharmacyAmountInputMessage;

    int pharmacyAmount;
    pharmacyAmount = errorHanding();
    pharmacy.setAmount(pharmacyAmount);
    charGen(pharmacyAmountInputMessage, '-');
}

int main()
{
    // start
    title();

    // PatientAccount patient;

    // // name input
    // string patientNameMessage = "Enter Patients Name: ";
    // cout << patientNameMessage;
    // // input
    // string patientName;
    // cin >> patientName;

    // // days amount
    // string dayMessage = "How many days was the patient in the hospital? ";
    // cout << dayMessage;
    // int days;
    // days = errorHanding();
    // patient.setStay(days);
    // charGen(dayMessage, '-');

    // add surgery section
    Surgery surgery;

    surgeryScreen(surgery);
    surgeryScreen(surgery);

    Pharmacy pharmacy;
    pharmacyScreen(pharmacy);
    pharmacyScreen(pharmacy);
    // pharmacy setup
    // pharmacyScreen();

    // calulations

    // end
    return 0;
}