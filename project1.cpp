#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string historyfile = "records.csv";

void addToHistory(int slot, string car, string plate, string timeIn, string timeOut, int cost, string paymentType)
{
    ofstream outFile;
    outFile.open(historyfile, ios::app);
    outFile << slot << ", "
            << car << ", "
            << plate << ", "
            << timeIn << ", "
            << timeOut << ", "
            << cost << ", "
            << paymentType << ", "
            << "\n";
    outFile.close();
}
