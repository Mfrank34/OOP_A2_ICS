#include <iostream>
#include <limits>
#include <fstream>

// classes
#include "Headers/Patient_Account.h"
#include "Headers/Pharmacy.h"
#include "Headers/Surgery.h"
#include "Headers/FileManager.h"

using namespace std;

void charGen(int length = 56, char placeholder = '-')
// gets the length of string, and placeholder to make line same length as inputed string
{
    cout << string(length, placeholder) << endl;
}

void dataRead(vector<pair<string, float>> data)
// debugging tool
{
    for (const auto &items : data) // for reading custom data vector for instance vector<tuple <string, int  ,float>> i really wanted to use index, maps dont let you
    {
        cout << items.first << " | " << items.second << endl; // custom readout format for debugging
    }
}

int errorHandleDigits(string mode = "number", int range = 0) // mode type | range selection
{
    if (mode == "range") // error handle numbers within range
    {
        int input;
        while (!(cin >> input) || input < 0 || input > (range - 1)) // take in input and matches between range
        {
            cout << "Enter a number between 0 and " << (range - 1) << ": "; // error message that dynamic wow so cool
            cin.clear();                                                    // clear console line
            cin.ignore(numeric_limits<streamsize>::max(), '\n');            // clear console line
        }
        return input;
    }
    else if (mode == "number") // error handle numbers
    {
        int input;
        while (!(cin >> input) || 0 >= input) // prevents inputing of 0 and only numbers
        {
            cout << "Invalid input. Enter a number above 0: ";   // error message
            cin.clear();                                         // clear console line
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear console line
        }
        return input;
    }
}

char errorHandleLetters()
{
    char input; // takes input
    bool letters = true;
    while (letters)
    {
        cin >> input;           // waits for input
        input = tolower(input); // lowers case

        if (input == 'y' || input == 'n') // looking for 'y' or 'n'
        {
            letters = false; // break look
        }
        else
        {
            cout << "Invalid input. Enter 'y' or 'n': ";         // error message
            cin.clear();                                         // clears console lone
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // removed all letter / number / spiece char
        }
    }
    return input;
}

void title()
{
    string title = "Inpatient Checkout Menu";
    charGen(56, '*');
    cout << string(15, ' ') << title << string(15, ' ') << endl;
    charGen(56, '*');
}

string patientName()
{
    bool getName = true;                                 // enable loop
    string patientNameMessage = "Enter Patients Name: "; // message
    string patientName;                                  // collection
    while (getName)
    {
        cout << patientNameMessage; // message readout
        cin >> patientName;         // collection
        cout << "The patient's name is " << patientName << endl
             << "Is this correct? Please answer with 'y' or 'n': "; // checking input
        char answer;                                                // checking user input and waiting for y or no
        if (!(answer = errorHandleLetters()) || answer == 'y')
        {
            getName = false; // breaks loop
        }
    }
    charGen(56, '-');

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
        cout << dayMessage;
        days = errorHandleDigits("number"); // collection of number
        cout << "Days in hospital: " << days << endl
             << "Is this correct? ('y' or 'n'): ";

        char answer; // should return y or n depending
        if (!(answer = errorHandleLetters()) || answer == 'y')
        {
            daySelect = false; // break loop if yes
        }
    }
    charGen(56, '-');
    return days; // returns day
};

void classScreen(auto &GivenClass, vector<string> sentence) // used class that given and messages
{
    int loopScreen = true;
    while (loopScreen)
    {
        // create table
        cout << sentence[0] << endl;
        GivenClass.createTable(); // table creator
        charGen(56, '-');

        // Input section
        cout << sentence[1];
        int select = errorHandleDigits("range", GivenClass.getTableDataSize());
        charGen(56, '-');
        // selecting multiple
        cout << sentence[2];
        int amount = errorHandleDigits("number");
        charGen(56, '-');

        GivenClass.setAmount(amount);     // set together
        GivenClass.setTreatement(select); // adds muliple items to treatement data

        // exit message
        cout << sentence[3];
        char answer;
        if (!(answer = errorHandleLetters()) || answer == 'n')
        {
            loopScreen = false;
        }
        charGen(56, '-');
    }
}

int main()
{
    // start
    title();

    bool programe = true;
    while (programe)
    {
        string name = patientName(); // name collection
        int days = daySelect();      // day collection

        // add surgery section
        Surgery surgery;
        vector<string> surgeryMessages = {
            "Which type of surgery was performed? ",             // 0
            "Choose a type of surgery (0 - 4): ",                // 1
            "Select amount of surgeries: ",                      // 2
            "Do you want to add more surgerie? ('y' or 'n'): "}; // 3

        classScreen(surgery, surgeryMessages);
        // debug data read
        // dataRead(surgery.getData());

        // pharmacy setup
        Pharmacy pharmacy;
        vector<string> medicationMessages = {
            "Which follow-up medication was given? ",   // 0
            "Choose a type of medication (0 - 5): ",    // 1
            "Select the amount of medications: ",       // 2
            "Choose more medications? ('y' or 'n'): "}; // 3

        classScreen(pharmacy, medicationMessages);
        // debug data read
        // dataRead(pharmacy.getData());

        PatientAccount patient(name, 200, days); // overloading right

        // calulations
        float surgeryCost = surgery.getTreatementCost();   // gets surgery cost
        float pharmacyCost = pharmacy.getTreatementCost(); // gey pharmacy cost
        float stayCost = patient.getStayAmount();          // gets total stay day times rate

        float totalCost = (stayCost + pharmacyCost + surgeryCost);                       // does maths thing
        cout << "Total Bill for " << patient.getName() << " is £ " << totalCost << endl; // readout
        cout << "Printing Bill..." << endl
             << endl;

        // create a read of of the bill

        FileManager bill;
        bill.createTop(patient.getName(), patient.getStay());              // creates top of bill
        bill.createTable(surgery.getData());                               // create table 1
        bill.createTable(pharmacy.getData());                              // create table 2
        bill.createBottom(stayCost, surgeryCost, pharmacyCost, totalCost); // create end
        bill.writeFile();                                                  // reads out to bill file

        cout << "Create another Bill ('y' or 'n'): ";
        char answer;
        if (!(answer = errorHandleLetters()) || answer == 'n')
        {
            cout << "Thanks for using the inpatient Checkout Simulator!" << endl;
            programe = false;
        }
    }
    return 0; // end programm!
}