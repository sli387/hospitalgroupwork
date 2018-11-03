#include "Patient.h"
#include <iostream>
#include <cstring>

using namespace std;


void Patient::patientSetMenu() {
    char getname[31];
    int getdays;
    double getrate;

    cin.ignore();

    cout << "\nPatient name: ";
    cin.getline(getname, 30);

    cout<< "\nDay(s) Staying:";
    cin >> getdays;

    setName(getname);
    setDays(getdays);


}

void Patient::setSurgery() {

    char nameoftype[30];
    double setprice;
	char choice;

    for (int i = 0; i < 5; i++) {
        cin.ignore();
        cout << "Enter No." << i + 1 << " type of surgery:";
        cin.getline(nameoftype, 30);

        surgery.setSurgeryName(nameoftype, i);

        cout << "Enter price of No." << i + 1 << " type of surgery:";
        cin >> setprice;
        surgery.setSurgeryPrice(setprice, i);

		cout << "Would you like to input another surgery?\n\tYes[Y]\tNo[N]";
		cin >> choice;
		if(toupper(choice) == 'N') {
			break;
		}

		cout << endl << endl;
    }
}

void Patient::setMedicine() {

    char nameoftype[30];
    double setprice;
	char choice;

    for (int i = 0; i < 5; i++) {
        cin.ignore();
        cout << "Enter No." << i + 1 << " medication type:";
        cin.getline(nameoftype, 30);

        medicine.setMedicineName(nameoftype, i);

        cout << "Enter price of No." << i + 1 << " medication type:";
        cin >> setprice;
        medicine.setMedicinePrice(setprice, i);

		cout << "Would you like to input another surgery?\n\tYes[Y]\tNo[N]";
		cin >> choice;
		if(toupper(choice) == 'N') {
			break;
		}

		cout << endl << endl;
	}
}

double Patient::totalChargeMedicine()  {
	double cost = 0.00;

	for (int i = 0; i < 5; i++) {
	 	cost = cost + medicine.getMedicinePrice(i);
	}

	return cost;
}

double Patient::totalChargeSurgery() {
	double cost = 0.00;

	for (int i = 0; i < 5; i++) {
		cost = cost + surgery.getSurgeryPrice(i);
	}

	return cost;
}


void Patient::showSurgeryList() {
	for (int i = 0; i < 5; i++) {
		cout << surgery.getSurgeryName(i) << "\t" << surgery.getSurgeryPrice(i) << endl;
	}
}

void Patient::showMedicineList() {
	for (int i = 0; i < 5; i++) {
		cout << medicine.getMedicineName(i) << "\t" << medicine.getMedicinePrice(i) << endl;
	}
}

 
void Patient::checkout() {
	cout << "\n___________________________________________________";
	cout << "\nThank you for your stay. Here is the charge : \n\n";
	cout << "Patient name: " << getName() << endl;
	cout << "Total charge: " << totalChargeSurgery() + totalChargeMedicine() + getCharge() << endl;
	cout << "\nDaily charge: " << getCharge() << endl ;
	cout << "Day(s):" << getDay() << endl;
	cout << "Rate : " << getRate() << endl;
	cout << "\n=========================" << endl << endl;
	
	cout << "Surgery charge:" << totalChargeSurgery() << endl << endl;
	showSurgeryList();
	cout << "\n=========================" << endl << endl;
	
	cout << "Pharmacy charge:" << totalChargeMedicine() << endl << endl;
	showMedicineList();
	cout << "\n=========================" << endl;
	
}
