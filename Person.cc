#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

//default constructor
Person::Person(){
	firstName = "0"; 
	lastName = "0";
	phone = "0"; 
	street = "0"; 
	city = "0";
	zip = "0";
}

//non default constor
Person::Person(string first, string last, string number, string str, string cit, string zipcode) {
		//initilaize the variables
		firstName = first; 
		lastName = last;
		phone = number; 
		street = str; 
		city = cit;
		zip = zipcode;
}

//sets the firstname for address book
void Person::setFirst(string first) {
        firstName = first;
}

//sets the last name for address book
void Person::setLast(string last) {

        lastName = last;

}

//sets the phone number for address book
void Person::setPhone(string num) {

        phone = num;

}

//sets the street name for address book
void Person::setStreet(string str) {

        street = str;

}

//sets the city for address book
void Person::setCity(string cy) {

        city = cy;

}

//sets the zipcode for address book
void Person::setZip(string code) {

        zip = code;

}
