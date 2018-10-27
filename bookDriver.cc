#include <iostream>
#include "Person.h"
#include "Person.cc"
//#include "AddressBook.h"
//#include "AddressBook.cc"
using namespace std;

void menu(/*takes addressbook array*/);

int main() {

	//AddressBook myaddressBook;

	menu(/*addressbook array*/);
	
	return 0;
}

void menu() {

	int choice;
	int error = 0;
	const int max = 25;
	char input[max];
	const int space = 5;
	Person book[5];

	cout << "\n-----------------------------------------------------\n";
	cout << "\n\t    Welcome To The Address Book\n";
	cout << "\n-----------------------------------------------------\n";
	cout << "What would you like to do : \n";
	cout << "\n\t1. View Book";
	cout << "\n\t2. Add Contact";
	cout << "\n\t3. Delete Contact";
	cout << "\n\t4. Update Contact";
	cout << "\n\t5. Search Contact";
	cout << "\n\t6. Exit Address Book";
	cout << "\n\nChoice Number : ";
	cin >> choice;
	cout << endl;

	switch (choice) {
		case 1:
			//view
			cout << "\n-----------------------------------------------------\n";
			cout << "Address Book Contents \n";

			for(int i = 0; i < 5; i++) {

				cout << "\n-----------------------------------------------------\nCONTACT #" << i+1;
				cout << "\n\tName : " << book[i].getFirst() << " " << book[i].getLast() << endl;
				cout << "\tPhone : " << book[i].getPhone() << endl;
				cout << "\tAddress : " << book[i].getStreet() << ", " << book[i].getCity() << " " << book[i].getZip() << endl; 

			}

			cout << "\n-----------------------------------------------------\n\n";
			//after displaying the book contents
			cout << "1. Back To Main Menu\n";
			cout << "2. Exit Address Book\n";
			cout << "Choice : ";
			cin >> choice;

			if(choice == 1) {
				menu();
			} else {
				exit(EXIT_SUCCESS);
			}
			break;

		case 2:
			//add
			for(int i = 0; i < 5; i++) {
				if(book[i].getFirst() == "0") {
					//space--;
					cout << "\n\nAdding contact to Address Book #" << i+1 << "\n\n";
					cin.ignore();

					cout << "\tFirst Name : ";
					cin.getline(input, max);
					//firstname = input;
					book[i].setFirst(input);
					
					cout << "\tLast Name : ";
					cin.getline(input, max);
					//lastname = input;
					book[i].setLast(input);
					
					cout << "\tPhone : ";
					cin.getline(input, max);
					//phone = input;
					book[i].setPhone(input);
					
					cout << "\tStreet : ";
					cin.getline(input, max);
					//street = input;
					book[i].setStreet(input);
					
					cout << "\tCity : ";
					cin.getline(input, max);
					//city = input;
					book[i].setCity(input);
					
					cout << "\tZip : ";
					cin.getline(input, max);
					//zip = input;
					book[i].setZip(input);
					break;
					//addPerson(firstname, lastname, phone, street, city, zip);
/*
					//Repeats the Contact to user in order to double check
					cout << "\n\n\tDISPLAY CONTACT\n\n";			
					cout << "\t"<< book[i].getFirst() << " " << book[i].getLast() << endl;
					cout << "\t"<< book[i].getPhone() << endl;
					cout << "\t"<< book[i].getStreet() << ", " << book[i].getCity() << " " << book[i].getZip() << endl;
*/
				}
			}

			cout << "\n-----------------------------------------------------\n\n";
			//after displaying the book contents
			cout << "1. Back To Main Menu\n";
			cout << "2. Exit Address Book\n";
			cout << "Choice : ";
			cin >> choice;

			if(choice == 1) {
				menu();
			} else {
				exit(EXIT_SUCCESS);
			}
			break;

		case 3:
			//delete
			{
				cout << "\n\nDelteing Contact in Address Book";
				cin.ignore();
				cout << "\nType in Fist Name : ";
				cin.getline(input, max);

				for(int i = 0; i < 5; i++) {
					if(book[i].getFirst() == input) {
						cout << "\n\nContact #" << i+1 << "\n\n";
						book[i].setFirst("0");
						book[i].setLast("0");
						book[i].setPhone("0");
						book[i].setStreet("0");
						book[i].setCity("0");
						book[i].setZip("0");

						cout << "Contact Deleted";
						cout << "\n-----------------------------------------------------\nCONTACT #" << i+1;
						cout << "\n\tName : " << book[i].getFirst() << " " << book[i].getLast() << endl;
						cout << "\tPhone : " << book[i].getPhone() << endl;
						cout << "\tAddress : " << book[i].getStreet() << ", " << book[i].getCity() << " " << book[i].getZip() << endl;
	/*
						//Repeats the Contact to user in order to double check
						cout << "\n\n\tDISPLAY CONTACT\n\n";			
						cout << "\t"<< book[i].getFirst() << " " << book[i].getLast() << endl;
						cout << "\t"<< book[i].getPhone() << endl;
						cout << "\t"<< book[i].getStreet() << ", " << book[i].getCity() << " " << book[i].getZip() << endl;
	*/
					} else {
						cout << "";
					}
				}
				cout << "\n-----------------------------------------------------\n\n";
				//after displaying the book contents
				cout << "1. Back To Main Menu\n";
				cout << "2. Exit Address Book\n";
				cout << "Choice : ";
				cin >> choice;

				if(choice == 1) {
					menu();
				} else {
					exit(EXIT_SUCCESS);
				}
			}
			break;

		case 4:
			//update
			{
				cout << "\n\nUpdating Contact in address Book";
				cin.ignore();
				cout << "\nType in Fist Name : ";
				cin.getline(input, max);

				for(int i = 0; i < 5; i++) {
					if(book[i].getFirst() == input) {
						cout << "\n\nNew contact to Address Book #" << i+1 << "\n\n";
						cout << "Update : \n";
						cout << "\n\t1. First Name";
						cout << "\n\t2. Last Name";
						cout << "\n\t3. Phone";
						cout << "\n\t4. Street";
						cout << "\n\t5. City";
						cout << "\n\t6. Zip";
						cout << "\nChoice : ";
						cin >> choice;
						switch (choice) {
							case 1:
								cout << "\tFirst Name : ";
								cin.ignore();
								cin.getline(input, max);
								book[i].setFirst(input);
								break;

							case 2:
								cout << "\tLast Name : ";
								cin.ignore();
								cin.getline(input, max);
								book[i].setLast(input);
								break;
							
							case 3:
								cout << "\tPhone : ";
								cin.ignore();
								cin.getline(input, max);
								book[i].setPhone(input);
								break;
								
							case 4:
								cout << "\tStreet : ";
								cin.ignore();
								cin.getline(input, max);
								book[i].setStreet(input);
								break;

							case 5:
								cout << "\tCity : ";
								cin.ignore();
								cin.getline(input, max);
								book[i].setCity(input);
								break;
								
							case 6:
								cout << "\tZip : ";
								cin.ignore();
								cin.getline(input, max);
								book[i].setZip(input);
								break;
						}
						

						cout << "Contact Updated";
						cout << "\n-----------------------------------------------------\nCONTACT #" << i+1;
						cout << "\n\tName : " << book[i].getFirst() << " " << book[i].getLast() << endl;
						cout << "\tPhone : " << book[i].getPhone() << endl;
						cout << "\tAddress : " << book[i].getStreet() << ", " << book[i].getCity() << " " << book[i].getZip() << endl;
	/*
						//Repeats the Contact to user in order to double check
						cout << "\n\n\tDISPLAY CONTACT\n\n";			
						cout << "\t"<< book[i].getFirst() << " " << book[i].getLast() << endl;
						cout << "\t"<< book[i].getPhone() << endl;
						cout << "\t"<< book[i].getStreet() << ", " << book[i].getCity() << " " << book[i].getZip() << endl;
	*/
					} else {
						cout << "";
					}
				}
				cout << "\n-----------------------------------------------------\n\n";
				//after displaying the book contents
				cout << "1. Back To Main Menu\n";
				cout << "2. Exit Address Book\n";
				cout << "Choice : ";
				cin >> choice;

				if(choice == 1) {
					menu();
				} else {
					exit(EXIT_SUCCESS);
				}
			}
			break;

		case 5:
			//search
			cin.ignore();
			cout << "\n-----------------------------------------------------\n";
			cout << "Searching Address Book Contents \n\n";
			cout << "Search (First Name) : ";
			cin.getline(input, max);

			for(int i = 0; i < 5; i++) {
				if(book[i].getFirst() == input) {
					cout << "\n-----------------------------------------------------\nCONTACT #" << i+1;
					cout << "\n\tName : " << book[i].getFirst() << " " << book[i].getLast() << endl;
					cout << "\tPhone : " << book[i].getPhone() << endl;
					cout << "\tAddress : " << book[i].getStreet() << ", " << book[i].getCity() << " " << book[i].getZip() << endl; 
				} else {
					error++;
				}
			}

			if(error == 4) {
				cout << "\n-----------------------------------------------------\n";
				cout << "\nName not in Address Book\n";
			}

			cout << "\n-----------------------------------------------------\n\n";
			//after displaying the book contents
			cout << "1. Back To Main Menu\n";
			cout << "2. Exit Address Book\n";
			cout << "Choice : ";
			cin >> choice;

			if(choice == 1) {
				menu();
			} else {
				exit(EXIT_SUCCESS);
			}
			break;

		case 6:
			//exit
			cout << "\n-----------------------------------------------------\n";
			cout << "\n\tNow exiting Address Book. . .\n";
			cout << "\n-----------------------------------------------------\n";
			exit(EXIT_SUCCESS);
			break;
	}
}
