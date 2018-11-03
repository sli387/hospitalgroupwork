#include "Patient.h"
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;
void displayMenu();

int main()
{
    Patient user;
	//for menu choice
    int choice;

    // Set numeric output formatting.
    cout << fixed << showpoint << setprecision(2);

	cout << "******************************************\n\n";
	cout << "\tWELCOME TO OUR HOSPITAL";
	cout << "\n\n******************************************";

	cout << "\n\nHello, my name Daniel.\nI will be of your assiatance for your stay.\nPlease fill out the paper work.\n";

    do {
    	// Display the menu and get a valid selection.
        displayMenu();
        cin >> choice;
		cout << endl;
    	while (choice < 1 || choice > 5) {
            cout << "Please make a choice in the range " << "of 1 to 5 :";
            cin >> choice;
        }

        // Process the user's menu selection.
        switch (choice) {

            case 1:

                user.patientSetMenu();
                break;

            case 2:

                user.setSurgery();
                break;

        	case 3:

                user.setMedicine();
                break;

            case 4:

                user.checkout() ;
				exit(EXIT_SUCCESS);
                break;
        }

    } while (choice != 5);

    return 0;
}

void displayMenu() {

	cout << "\n\n==================================================\n\n";
	cout << "\n1) Patient Account setting\n";
	cout << "2) Patient Surgery Information setting\n";
	cout << "3) Patient Pharmacy Information setting\n";
	cout << "4) Patient Check Out\n";

	cout << "\n\nIf you would like to leave please tell me.\n";
	cout << "5) Exit \n";

	cout << "\nChoice : ";

} 
