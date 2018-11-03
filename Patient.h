#ifndef PATIENT_H
#define PATIENT_H
#include "Surgery.h"
#include "Pharmacy.h"
#include <cstring>
#include <iostream>
using namespace std;

class Patient {
  private:
    
    string name;
    int days;
    double rate;

	Surgery surgery;
	Pharmacy medicine;

    
  public:
    
    Patient() {
      name = "John Doe";
      days = 0;
      rate = 245.39;
    }

    ~Patient() {}

    void setDays(int setDay) 
      { days = setDay; }

    void setName(string setName)
      { name = setName;}

    int getDay() const
      { return days; }

    string getName() const
      { return name; }

    double getRate() const 
      { return rate;}

    double getCharge() 
      { return rate * days; }


    double totalChargeSurgery();
    double totalChargeMedicine();

	double totalCharge();

    void setSurgery();
    void setMedicine();

	void patientSetMenu();
    void showSurgeryList();
    void showMedicineList();
    void checkout();
};

#endif
