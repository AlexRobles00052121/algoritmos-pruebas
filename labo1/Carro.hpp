#pragma once
#include <string>

using namespace std;

class Carro
{
    private:
        //attributes
        string _brand;
        int _year;
        int _price;
    public:
    //Constructor
    Carro(string, int, int);
    //getter
    string getBrand();
    int getYear();
    int getPrice();
    //setter
    void setBrand(string);
    void setYear(int);
    void setPrice(int);
};