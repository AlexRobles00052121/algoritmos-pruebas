#include<iostream>
#include<fstream>

using namespace std;

// Define the structure for storing client information
struct Client
{
    string name, address, job;
    float income;
};

void load_data(Client *data, const int rows = 1000, const int cols = 5)
{
    // Define the file name
    string filename = "clients.txt";

    string name, address, job, incomeStr;

    const int numRows = rows;     // Number of rows
    const int numColumns = cols; // Number of columns

    // Open the file
    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Failed to open the file." << endl;
        return;
    }

    int i = 0;
    while(getline(file, name, '\t')){
        data[i].name = name;
        getline(file, address, '\t');
        data[i].address = address;
        getline(file, job, '\t');
        data[i].job = job;
        getline(file, incomeStr, '\n');
        //stod == String to Double
        data[i].income = stod(incomeStr);
        ++i;
    }

    // Close the file
    file.close();
}