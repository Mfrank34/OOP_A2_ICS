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

void dataRead(vector<pair<string, float>> data)
// debugging tool
{
    for (const auto &items : data)
    {
        cout << items.first << " | " << items.second << endl;
    }
}

int errorHandleDigits(string mode, int range = 0)
{
    if (mode == "range") // error handle numbers within range
    {
        int input;
        while (!(cin >> input) || input < 0 || input > (range - 1))
        {
            cout << "Enter a number between 0 and " << range << ": ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        return input;
    }
    else if (mode == "number") // error handel numbers
    {
        int input;
        while (!(cin >> input))
        {
            cout << "Invalid input. Enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        return input;
    }
    else
    {
        cout << "Unknown mode.\n";
        return -1; // or throw an error
    }
}

char errorHandleLetters()
{
    char input;
    bool letters = true;
    while (true)
    {
        cin >> input;
        input = tolower(input);

        if (input == 'y' || input == 'n')
            letters = false;

        else
        {
            cout << "Invalid input. Enter 'y' or 'n': ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        return input;
    }
}

void title()
{
    string title = "Inpatient Checkout Menu";
    charGen(title);
    cout << title << endl;
    charGen(title);
}

string patientName()
{
    bool getName = true;
    string patientNameMessage = "Enter Patients Name: ";
    string patientName;
    while (getName)
    {
        // message
        cout << patientNameMessage;
        // input
        cin >> patientName;

        // checking name
        cout << "The patient's name is " << patientName << ". Is this correct? Please answer with 'y' or 'n': ";
        char answer = errorHandleLetters();

        if (answer == 'y')
        {
            // loop breaker
            getName = false;
        }
    }
    charGen(patientNameMessage, '-');
    return patientName;
};

int daySelect()
{
    // verable setup
    bool daySelect = true;
    int days;
    string dayMessage = "How many days was the patient in the hospital? ";
    while (daySelect)
    {
        // message
        cout << dayMessage;
        // input
        days = errorHandleDigits("number");
        cout << "Days in hospital: " << days << ". Is this correct? ('y' or 'n'): ";
        // check
        char answer = errorHandleLetters();
        // break
        if (answer == 'y')
        {
            daySelect = false;
        }
    }
    charGen(dayMessage, '-');
    return days;
};

void classScreen(auto &GivenClass, vector<string> sentence)
{
    int loopScreen = true;
    while (loopScreen)
    {
        // create table
        cout << sentence[0] << endl;
        GivenClass.createTable();
        charGen(sentence[0], '-');

        // Input section
        cout << sentence[1];
        int select = errorHandleDigits("range", GivenClass.getTableDataSize());
        charGen(sentence[1], '-');
        // selecting multiple
        cout << sentence[2];
        int amount = errorHandleDigits("number");
        GivenClass.setAmount(amount);
        charGen(sentence[2], '-');

        // Storing multiple treatments
        for (int i = 0; i < GivenClass.getAmount(); i++)
        {
            GivenClass.setTreatement(select);
        }
        // exit message

        cout << sentence[3];
        char answer = errorHandleLetters();
        charGen(sentence[3], '-');
        // break
        if (answer == 'n')
        {
            loopScreen = false;
        }
    }
}

int main()
{
    // start
    title();

    // patient name
    string name = patientName();
    // patient days
    int days = daySelect();

    // add surgery section
    Surgery surgery;
    // sentences
    vector<string> surgeryMessages = {
        "Which type of surgery was performed? ",             // 0
        "Choose a type of surgery (0 - 4): ",                // 1
        "Select amount of surgeries: ",                      // 2
        "Do you want to add more surgerie? ('y' or 'n'): "}; // 3

    classScreen(surgery, surgeryMessages);
    // debug data read
    //dataRead(surgery.getData());

    // pharmacy setup
    Pharmacy pharmacy;
    vector<string> medicationMessages = {
        "Which follow-up medication was given? ",
        "Choose a type of medication (0 - 5): ",
        "Select the amount of medications: ",
        "Would you like to choose more medications? ('y' or 'n'): "};

    classScreen(pharmacy, medicationMessages);
    // debug data read
    //dataRead(pharmacy.getData());

    // time for overloading i am i right?
    PatientAccount patient(name, 200, days);
    
    // calulations

    // end
    return 0;
}