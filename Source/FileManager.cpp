#include "FileManager.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

FileManager::FileManager() {}

void FileManager::createTop(string name, int days)
{
    this->name = name;

    fileData << string(56, '*') << endl
             << string(15, ' ') << "Inpatient Checkout Receipt" << string(15, ' ') << endl
             << string(56, '*') << endl
             << endl;

    // Label and value with some padding
    fileData << left << setw(16) << "Patient's Name:" << name << endl;
    fileData << left << setw(12) << "Days Spent:" << days << endl
             << endl;
}

void FileManager::createTable(const vector<tuple<string, int, float>> data)
{
    // Header row with left and right alignment and separators
    fileData << left << setw(30) << "Item's" << " | "
             << setw(10) << "Amount" << " | "
             << right << setw(10) << "Cost" << endl;

    fileData << string(56, '-') << endl; // separator line (30 + 3 + 10 + 3 + 10 = 56 chars)

    // Iterate and print each item tuple
    for (auto item : data)
    {
        fileData << left << setw(30) << get<0>(item) << " | "
                 << setw(10) << get<1>(item) << " | "
                 << right << fixed << setprecision(2) << setw(10) << get<2>(item)
                 << endl;
    }
    fileData << endl
             << endl;
}

void FileManager::createBottom(float StayCost, float sCost, float pCost, float totalCost)
{
    int leftGap = 40;
    int rightGap = 10; // made a bit wider

    fileData << fixed << setprecision(2);

    fileData << string(56, '-') << endl;

    fileData << left << setw(leftGap) << "Stay Cost:"
             << "£" << right << setw(rightGap) << StayCost << "\n";

    fileData << left << setw(leftGap) << "Surgery Cost:"
             << "£" << right << setw(rightGap) << sCost << "\n";

    fileData << left << setw(leftGap) << "Pharmacy Cost:"
             << "£" << right << setw(rightGap) << pCost << "\n";

    fileData << string(56, '-') << endl;

    fileData << left << setw(leftGap) << "Total Cost:"
             << "£" << right << setw(rightGap) << totalCost << "\n";
}

void FileManager::writeFile()
{
    string fileName = "Bills/Bill for " + name + ".txt";

    ofstream file(fileName);
    if (file.is_open())
    {
        file << fileData.str() << endl;              // adds content
        cout << "File written successfully" << endl; // message output
        file.close();                                // close
    }
    else
    {
        cout << "File Failed to Open file!" << endl; // error message
    }
}

FileManager::~FileManager() {};