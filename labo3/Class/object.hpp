// Define the structure for storing battalion information

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <string>
using namespace std;

struct Battalion
{
    private:
        //Parameters
        string code;
        int id;
        int manpower;
        int armoredEquipment;
        double budget;
    
    public:
        //Getters and Setters
        string getCode(){
            return code;
        }
        void setCode(string code){
            this->code = code;
        }

        int getId(){
            return id;
        }
        void setId(int id){
            this->id = id;
        }

        int getManpower(){
            return manpower;
        }
        void setManpower(int manpower){
            this->manpower = manpower;
        }

        int getArmoredEquipment(){
            return armoredEquipment;
        }
        void setArmoredEquipment(int armoredEquipment){
            this->armoredEquipment = armoredEquipment;
        }

        double getBudget(){
            return budget;
        }
        void setBudget(double budget){
            this->budget = budget;
        }

        //Constructors
        Battalion(){
            code = "";
            id = 0;
            manpower = 0;
            armoredEquipment = 0;
            budget = 0.0;
        }
        Battalion(string code, int id, int manpower, int armoredEquipment, double budget){
            this->code = code;
            this->id = id;
            this->manpower = manpower;
            this->armoredEquipment = armoredEquipment;
            this->budget = budget;
        }
};

#endif