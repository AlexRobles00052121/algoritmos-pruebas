#include "Carro.hpp"

//constructor

Carro::Carro (string brand, int year, int price):

    _brand(brand),
    _year(year),
    _price(price)
    
{}
//brand 
   //getter 
    string Carro::getBrand ()
    { 
         return _brand;
    }
    //setter
    void Carro::setBrand (string brand)
    {
        _brand = brand;
    }
//year 
    //getter
    int Carro::getYear ()
    {
        return _year;
    }
    //setter 
    void Carro::setYear (int year)
    {
        _year = year;
    }
//price
    //getter
    int Carro::getPrice ()
    {
        return _price;
    }
    //setter
    void Carro::setPrice (int price) 
    {
        _price = price;
    }