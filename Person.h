#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

class Person {

  private:
    string firstName;
    string lastName;
    string phone;
    string street;
    string city;
    string zip;
/*
	void addressBook(string firstname, string lastname, string phon, string str, string cit, string zipcode) {
		firstName = firstname;
		lastName = lastname;
		phone = phon;
		street = str;
		city = cit;
		zip = zipcode;
	}
*/
  public:

    void setFirst(string);
    void setLast(string);
    void setPhone(string);
    void setStreet(string);
    void setCity(string);
    void setZip(string);

	//inline 
    string getFirst()
      { return firstName; }
    string getLast()
      { return lastName; }
    string getPhone()
      { return phone; }
    string getStreet()
      { return street; }
    string getCity()
      { return city; }
    string getZip()
      { return zip; }

	//defult constructor
	Person();
	//non default constructor
	Person(string, string, string, string, string, string);
	//for constructor

};

#endif
