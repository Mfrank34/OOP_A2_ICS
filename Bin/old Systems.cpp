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

char errorHandingYesNo()
{
    char input;
    bool error = true;
    while (error)
    {
        cin >> input;
        input = tolower(input); //make input case-insensitive

        if (input == 'y' || input == 'n')
        {
            error = false;
        }
        else
        {
            cout << "Invalid input. Enter 'y' or 'n': ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
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

void surgeryScreen(Surgery &surgery)
{
    string surgeryMessage = "Which type of surgery has been performed?";
    surgery.createTable();
    charGen(surgeryMessage, '-');

    // surgery input
    string SurgeryInputMessage = "Choose a type of Surgery (0-4): ";
    cout << SurgeryInputMessage;

    // selecting surgery
    int surgerySelect;
    cout << surgery.getTableDataSize() << endl;
    surgerySelect = errorHandlingDigits("range", surgery.getTableDataSize());

    // multiple surgery
        
    cout << SurgeryAmountMessage;
    int surgeryAmount;
    surgeryAmount = errorHandlingDigits("number");
    surgery.setAmount(surgeryAmount);
    charGen(SurgeryAmountMessage, '-');

    // make it handel multiple selects
    for (int i = 0; i < surgeryAmount; i++)
    {
        surgery.setTreatement(surgerySelect);
    }
};

void pharmacyScreen(Pharmacy &pharmacy)
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
    pharmacySelect = errorHandlingDigits("range", pharmacy.getTableDataSize());

    charGen(pharmacyInputMessage, '-');

    // pharmacy amount
    string pharmacyAmountInputMessage = "Select amount of medications: ";
    cout << pharmacyAmountInputMessage;

    int pharmacyAmount;
    pharmacyAmount = errorHandlingDigits("number");
    pharmacy.setAmount(pharmacyAmount);
    charGen(pharmacyAmountInputMessage, '-');

    for (int i = 0; i < pharmacyAmount; i++)
    {
        pharmacy.setTreatement(pharmacySelect);
    }
};
