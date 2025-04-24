#include <iostream>
#include <limits>

// classes
#include "Headers/Patient_Account.h"
#include "Headers/Pharmacy.h"
#include "Headers/Surgery.h"

void charGen(string length, char placeholder = '*')
{
    for (int i = 0; i < length.size(); i++)
    {
        cout << placeholder;
    }
    cout << endl;
}

int errorHandingRange(int range)
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

void title()
{
    string title = "Inpatient Checkout Menu";
    charGen(title);
    cout << title << endl;
    charGen(title);
}

using namespace std;
// Main
int main()
{
    // start
    title();

    PatientAccount patient;

    // days amount
    string dayMessage = "How many days was the patient in the hospital? ";
    cout << dayMessage;
    int days;
    days = errorHanding();
    patient.set_total_stay(days);
    charGen(dayMessage, '-');

    // surgery performed
    Surgery surgery;

    string surgeryMessage = "Which type of surgery has been performed?";
    surgery.readout();
    charGen(surgeryMessage, '-');

    // surgery input
    string SurgeryInputMessage = "Choose a type of Surgery (0-4): ";
    cout << SurgeryInputMessage;

    // selecting surgery...
    int surgerySelect;
    surgerySelect = errorHandingRange(surgery.getTreatmentSize()); // yes i could saved it verable...
    surgery.setSurgery(surgerySelect);

    // pharmacy setup
    Pharmacy pharmacy;

    string pharmacyMessage = "which follow-up medication has been given?";
    // formating
    charGen(pharmacyMessage, '-');
    cout << pharmacyMessage << endl;

    // pharmacy readout
    pharmacy.readout();
    charGen(pharmacyMessage, '-');

    // pharmacy select
    string pharmacyInputMessage = "Choose a type of mediation (0-5): ";
    cout << pharmacyInputMessage << endl;

    int pharmacySelect;
    pharmacySelect = errorHandingRange(pharmacy.getMedicationSize()); // yes i could saved it verable...
    pharmacy.setMedication(pharmacySelect);
    charGen(pharmacyInputMessage, '-');

    // pharmacy amount
    string pharmacyAmountInputMessage = "Select amount of medications: ";
    cout << pharmacyAmountInputMessage << endl;

    int pharmacyAmount;
    pharmacyAmount = errorHanding();
    pharmacy.setAmount(pharmacyAmount);
    charGen(pharmacyAmountInputMessage, '-');


    // calulations
    



    // end
    return 0;
}