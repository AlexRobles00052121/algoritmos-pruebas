#ifndef READER_HPP
#define READER_HPP

#include<iostream>
#include<fstream>
#include<string>
#include"object.hpp"

string double_quote(ifstream* file, string str){
    string temp;
    getline(*file, temp, ',');
    str += temp;
    return str;
}

void load_data(Battalion *data)
{
    // Define the file name
    string filename = "Battalions.csv";

    string code, idStr, manpowerStr, armoredEquipmentStr, budgetStr;

    // Open the file
    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Failed to open the file." << endl;
        return;
    }

    // Removing the column headers
    getline(file, code, '\n');
    
    // Reading the data
    int i = 0;
    while(getline(file, code, ',')){
        if(code[0] == '\"'){
            code = double_quote(&file, code);
        }
        data[i].setCode(code);
        
        getline(file, idStr, ',');
        // stoi == String to Integer
        data[i].setId(stoi(idStr));

        getline(file, manpowerStr, ',');
        // stoi == String to Integer
        data[i].setManpower(stoi(manpowerStr));
        
        getline(file, armoredEquipmentStr, ',');
        // stoi == String to Integer
        data[i].setArmoredEquipment(stoi(armoredEquipmentStr));
        
        getline(file, budgetStr, '\n');
        // stod == String to Double
        data[i].setBudget(stod(budgetStr));
        
        ++i;
    }

    // Close the file
    file.close();
}
#endif