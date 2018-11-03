#ifndef SURGERY_H
#define SURGERY_H
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class Surgery {
private:

    string surgeryName[5];
    double surgeryPrice[5];

public:

    Surgery() {

        for (int i = 0; i < 5; i++) {
            surgeryName[i] = "";
            surgeryPrice[i] = 0.00;
        }

    }

    string getSurgeryName(int index) const 
		{	return surgeryName[index];	}

    double getSurgeryPrice(int index) const
		{	return surgeryPrice[index];	}

    void setSurgeryName(char* settype, int index) 
		{	surgeryName[index] = settype;	}

    void setSurgeryPrice(float setprice, int index) 
		{	surgeryPrice[index] = setprice;	}

        //void setsurgery();
};


#endif
