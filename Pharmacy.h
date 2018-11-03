#ifndef PHARMACY_H
#define PHARMACY_H
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class Pharmacy {
private:

    string medicineName[5];
    double medicinePrice[5];

public:

    Pharmacy() {

        for (int i = 0; i < 5; i++) {
			//sets all the medicine to the "null"
            medicineName[i] = "";
            medicinePrice[i] = 0.00;
        }
    }

    string getMedicineName(int index) const 
		{ return medicineName[index]; }

    double getMedicinePrice(int index) const
		{ return medicinePrice[index]; }

    void setMedicineName(char* settype, int index) 
		{ medicineName[index] = settype; }

    void setMedicinePrice(double setprice, int index) 
		{ medicinePrice[index] = setprice; }

};


#endif
