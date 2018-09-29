#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;
char confirm;
//Global variable//
const int capacity=9999;

int ContactNum; //Read or wirte contacts' rows
///string Loader ; //Temporary record contactbook.txt each row loaded information
//int fileWidth=168; //contactbook width
int SN[capacity]; //sequence number of contact 
int FoundSN[capacity]; // for searched, deleted, and updated functions to record the operation row
string FirstName[capacity]; // capacity is 21
string MiddlName[capacity]; // [21];
string LastName[capacity]; // [21];
string PhoneNum1[capacity]; // [11];
string PhoneNum2[capacity]; // [11];
string Address[capacity]; // [30];
string City[capacity]; //[20]
string States[capacity]; //10
string Zipcode[capacity]; //[5]
char Status[capacity]; // [1] temporary record the contact operation status record the contact status like be deleted 'D' or updated 'U'

//Global variable//
void ContactArrayCleanUp();//to clean up contact arrays
void SortArray(int);///Sort the contacts' order by name
int ReadFileF(string);///string filename
int writeFileF(string, int);///string filename; int: to indicate the contacts' quantity
void DistributionofLoader(string, int);///string contain one contact information; int: to indicate the contacts' quantity
int addressBookMenu(); ///
void ContactListDisplay(int);///int indicate the rows of contact
int stringcomparssion(string existingstring, char[]); /// to compare two string if return 1:match otherwise not match


int main()
{
	//load contact information
	cout << "Loading contact information..." << endl;
	ContactNum = ReadFileF("contactbook.txt");

	// cout << "ContactNum: " << ContactNum;
	if (ContactNum>=0)
	{ 
		cout << "Loaded" << ContactNum << " contact(s)" << endl;
	}
	else
	{
		cout << "Fail to open contacts file!" << endl;
	}

  	do
  	{
    
	} while (addressBookMenu() != 0);
	return 0;
}


void SortArray(int row)
{
	string combinename1, combinename2;
	string exchangestring;
	char exchangechar;

	for (int i = 1; i <= row; i++)
	{
		for (int j = i; j <= row; j++)
		{
			combinename1 = FirstName[i] + LastName[i];
			combinename2 = FirstName[j] + LastName[j]; 

			if (strcmp(combinename1.c_str(), combinename2.c_str()) > 0)
     			{
				exchangestring = FirstName[i]; FirstName[i] = FirstName[j];FirstName[j] = exchangestring;
				exchangestring = LastName[i];LastName[i] = LastName[j];LastName[j] = exchangestring;
				exchangestring = MiddlName[i];MiddlName[i] = MiddlName[j];MiddlName[j] = exchangestring;
				exchangestring = PhoneNum1[i]; PhoneNum1[i] = PhoneNum1[j]; PhoneNum1[j] = exchangestring;
				exchangestring = PhoneNum2[i]; PhoneNum2[i] = PhoneNum2[j]; PhoneNum2[j] = exchangestring;
				exchangestring = Address[i]; Address[i] = Address[j]; Address[j] = exchangestring;
				exchangestring = City[i]; City[i] = City[j]; City[j] = exchangestring;
				exchangestring = States[i]; States[i] = States[j]; States[j] = exchangestring;
				exchangestring = Zipcode[i]; Zipcode[i] = Zipcode[j]; Zipcode[j] = exchangestring;
				exchangechar = Status[i]; Status[i] = Status[j]; Status[j] = exchangechar;
			}
    		}
	}
}


void ContactArrayCleanUp()
{
	for (int i = 0; i < capacity; i++)
	{
		SN[i]=0; //sequence number of contact
		FirstName[i]=""; // [21];
		LastName[i] = ""; // [21];
		PhoneNum1[i] = ""; // [11];
		Address[i] = ""; // [82];
		City[i]=""; //[20]
		States[i]=""; //10
		Zipcode[i]=""; //[5]
		Status[i]=' ';
	}
	ContactNum = 0;
}


//string contain one contact information; int: to indicate the contacts' quantity
void DistributionofLoader(string contactdata, int row)
{
	int ifind;

	SN[row] = row;

	ifind = contactdata.find('\t');
	FirstName[row] = contactdata.substr(0, ifind);
	contactdata = contactdata.substr(ifind +1);
		 
	ifind = contactdata.find('\t');
	LastName[row] = contactdata.substr(0, ifind);
	contactdata = contactdata.substr(ifind + 1);

	ifind = contactdata.find('\t');
	PhoneNum1[row] = contactdata.substr(0, ifind);
	contactdata = contactdata.substr(ifind + 1);

	ifind = contactdata.find('\t');
	Address[row] = contactdata.substr(0, ifind);
	contactdata = contactdata.substr(ifind + 1);

	ifind = contactdata.find('\t');
	City[row] = contactdata.substr(0, ifind);
	contactdata = contactdata.substr(ifind + 1);

	ifind = contactdata.find('\t');
	States[row] = contactdata.substr(0, ifind);

	Zipcode[row] = contactdata.substr(ifind+1);	
}


//display
void ContactListDisplay(int row)
{
	int i = row;

	cout << setw(4) << left << i << '\t';
	cout << setw(10) << left << FirstName[i].c_str() << '\t';
	cout << setw(8) << left << LastName[i].c_str() << '\t';
	cout << setw(13) << left << PhoneNum1[i].c_str() << '\t';
	cout << setw(20) << left << Address[i].c_str()  << '\t';
	cout << setw(10) << left << City[i].c_str() << '\t';
	cout << setw(10) << right << States[i].c_str()  << '\t';
	cout << setw(5) << left << Zipcode[i].c_str() << setw(3) << left << Status[i]<< endl;
}


void ContactListDisplay()
{
	if (ContactNum == 0) 
  { 
    cout << "No contact found!"; 
  }

	for (int i = 1; i <= ContactNum; i++)
	{
		ContactListDisplay(i);
	}
}


int ReadFileF(string filename)
{
	int rows=0;
	ContactArrayCleanUp();
	ifstream inputFile;
	inputFile.open(filename.c_str());

	if (inputFile.fail())
	{
		return -1;//Unable to open file
	}
	int beginning=0;

	while (!inputFile.eof())
	{
		beginning++;
		char ReadEachChar;
		string Loader = "";
		do
		{
			ReadEachChar = inputFile.get();

			if (inputFile.fail()) 
			{
			  break;
			}
		  	else if (ReadEachChar == 'n')
			{
				rows++;
				DistributionofLoader(Loader, rows); //allocate the contact information to contact array
				Loader = "";

				ContactListDisplay(rows);
				break;
			}
			else if ( ReadEachChar == 'n' || ReadEachChar == '0' || ReadEachChar == 'r' )
			{ 

      			}
			else
			{
				Loader = Loader + ReadEachChar;
			}
		} while (1 == 1);
	}
	inputFile.close();
	return rows;
}


//string filename; int: to indicate the contacts' quantity
int  writeFileF(string filename, int row)
{
	ofstream inputFile;
	inputFile.open(filename.c_str());

	SortArray(row); //Sort the arrays before saving

	for (int i = 1; i <= row; i++)
	{
		if (Status[i] == 'D')
		{
			//skip the deleted row
		}
		else
		{ 
			inputFile << FirstName[i].c_str() << '\t' << LastName[i].c_str() << '\t'<< PhoneNum1[i].c_str() << '\t' << Address[i].c_str() << '\t' << City[i].c_str() << '\t' << States[i].c_str() << '\t' << Zipcode[i].c_str()  <<'\n';
		}
	}
	inputFile.close();
	cout << "File Save." << endl;

	return 0;
} 


int stringcomparssion(string existingstring, char findstring[])
{
	int findstringsize = 0;

	for (int i = 0; i < 11; i++)
	{
		if (findstring[i] == 'n' || findstring[i] == '0' || findstring[i] == 'r' || findstring[i] == '0')
		{
			break;
		}
		findstringsize++;
	}

	if (findstringsize >= 1) //get the comparssion size
	{
		int comparssioncount = 0;

		for (int i = 0; i < findstringsize; i++)
		{
			if (toupper(existingstring[i]) == toupper(findstring[i]))
			{
				comparssioncount++;
			}
		}

		if (comparssioncount == findstringsize)
		{
			return 1;
		}
	}
	return 0;
}


int contactsearch(char findingstring[], char filed)
{
	int result=0;
	int resultcount=0;
	
	for (int i = 1; i <= ContactNum; i++) //before search clean the FoundSN[] up
	{
		FoundSN[resultcount] = 0;
	}

	switch (filed)
	{
		case '1':
			for (int i = 1; i <= ContactNum; i++)
			{
				result = stringcomparssion(FirstName[i], findingstring);
				if (result == 1)
			  	{
					ContactListDisplay(i);
				 	resultcount++;
				 	FoundSN[resultcount] = i; //Record each found contact
				 	FoundSN[0] = resultcount; //Record the found contact total
				}
			}
			break;

	  	case '2':
			for (int i = 1; i <= ContactNum; i++)
		  	{
				result = stringcomparssion(PhoneNum1[i], findingstring);
				if (result == 1)
			 	{
					ContactListDisplay(i);
					resultcount++;
				 	FoundSN[resultcount] = i; //Record each found contact
				 	FoundSN[0] = resultcount; //Record the found contact total
				}
		  	}
		  	break;
	
		case '3':
			for (int i = 1; i <= ContactNum; i++)
		 	{
				result = stringcomparssion(Address[i], findingstring);
				if (result == 1)
				{
					ContactListDisplay(i);
					resultcount++;
					FoundSN[resultcount] = i; //Record each found contact
					FoundSN[0] = resultcount; //Record the found contact total
			  	}
			}
	  		break;
	
		case '4':
			for (int i = 1; i <= ContactNum; i++)
		  	{
		  		result = stringcomparssion(City[i], findingstring);
			  	if (result == 1)
			  	{
			  		ContactListDisplay(i);
			  		resultcount++;
			  		FoundSN[resultcount] = i; //Record each found contact
			  		FoundSN[0] = resultcount; //Record the found contact total
			  	}
		  	}
			break;
	
    		case '5':
		  	for (int i = 1; i <= ContactNum; i++)
		  	{
		  		result = stringcomparssion(States[i], findingstring);
			  	if (result == 1)
			  	{
					ContactListDisplay(i);
				 	resultcount++;
				 	FoundSN[resultcount] = i; //Record each found contact
				 	FoundSN[0] = resultcount; //Record the found contact total
				}
			}
    			break;

	  	case '6':
	  		for (int i = 1; i <= ContactNum; i++)
	  		{
	  			result = stringcomparssion(Zipcode[i], findingstring);
	  		
				if (result == 1)
		  		{
		  			ContactListDisplay(i);
		  			resultcount++;
			  		FoundSN[resultcount] = i; //Record each contact
			  		FoundSN[0] = resultcount; // Record total
				}
			}
			break;
	}
	cout <<  "Found " << resultcount << " contact(s)" << endl << endl  ;	
	return resultcount;
}


int contactsearch(char findField)
{
	char str[11];

	switch (findField)
	{
		case '1':
			cout << endl << "First Name (10 characters):";
			cin.getline(str, 10);
			return contactsearch(str, '1');
			break;

		case '2':
			cout << endl << "Phone Number(10 characters):";
		  	cin.getline(str, 10);
		 	return contactsearch(str, '2');
		 	break;

		case '3':
			cout << endl << "Address(10 characters):";
		 	cin.getline(str, 10);
		 	return contactsearch(str, '3');
		 	break;

		case '4':
	  		cout << endl << "City(10 characters):";
	  		cin.getline(str, 10);
	  		return contactsearch(str, '4');
	  		break;
	
		case '5':
			cout << endl << "States(10 characters):";
			cin.getline(str, 10);
			return contactsearch(str, '5');
			break;
	
	    	case '6':
			cout << endl << "Zipcode(10 characters):";
		 	cin.getline(str, 10);
		 	return contactsearch(str, '6');
		 	break;

		case 'E':
	  		break;
	}
	return 0;
}

//search contact
void contactsearch()
{
	char menuChoice;

	do
	{
		cout << "Choose a search field [First Name(1)/Phone(2)/Address(3)/City(4)/State(5)/Zipcode(6)/All(7)/Exit(0)]";
		cin >> menuChoice;
		cin.ignore();

		if (menuChoice == '0')
		{
			break;
		}
    		else if (menuChoice == '7')
		{
			ContactListDisplay();
			break;
		}
		else
		{
			contactsearch(menuChoice);
		}
	} while (1 == 1);
}

//delete a contact
void contactdelete()
{
	char menuChoice;

	do
	{
		cout << "Choose a search field for deleting operation:" << endl << "[First Name(1)/Phone(2)/Address(3)/City(4)/State(5)/Zipcode(6)/All(7)/Exit(0)]";
		cin >> menuChoice;
		cin.ignore();

		if (menuChoice == '0')
		{
			break;
		}
		
		if (menuChoice == '7') 
		{ 
			menuChoice = 'E'; 
			if (menuChoice == 'E') //user chose  all contacts for menus third then select all contact for user next operation 
			{
				ContactListDisplay();
				FoundSN[0] = ContactNum;
				for (int i = 1; i <= FoundSN[0]; i++)
				{
					FoundSN[i] = i; //record the potential deleted contact SN. Here is all.
				}
			}
		}

		if ( menuChoice == 'E' ||  contactsearch(menuChoice)>0  )
		{
			do
			{
				int DeletSn;
				bool FoundEnterSn = false;
				// in the third menu, let user choose to delete
				cout << "Select the contact(s) to delete follow below instruction." << endl << "If you make twice select at a same contact, the selection is canceled!" <<endl;
				cout << "Enter a SN from above list (number)/All Above(-2)/All whole book(-100)/list All(-3)/Exit(0):";
				cin >> DeletSn;

				if (DeletSn ==-2)//delete All Above(-2)
				{ 
					for (int i = 1; i <= FoundSN[0]; i++)
					{
						if (Status[FoundSN[i]] == 'D')
						{
							Status[FoundSN[i]] = ' ';
						}
						else
						{
							FoundEnterSn = true;
							Status[FoundSN[i]] = 'D';
						}
					}
				}
				else if (DeletSn == -3)//list All(-3)
				{
					ContactListDisplay();
					FoundSN[0] = ContactNum;
				
					for (int i = 1; i <= FoundSN[0]; i++)
					{
						FoundSN[i] =i;//record the potential deleted contact SN
					}
				}
				else if (DeletSn == -100)
				{
					for (int i = 1; i <= ContactNum; i++)
					{
						if (Status[FoundSN[i]] == 'D')
						{
							Status[FoundSN[i]] = ' ';
						}
						else
						{
							FoundEnterSn = true;
							Status[FoundSN[i]] = 'D';
						}
					}
				}
				else if (DeletSn == 0)
				{
					break;
				}
				else
				{ 		
					for (int i = 1; i <= FoundSN[0]; i++)
					{
            					if (FoundSN[i]== DeletSn)
						{
							if (Status[FoundSN[i]] == 'D')
							{
								Status[FoundSN[i]] = ' ';
							}
							else
							{
								FoundEnterSn = true;
								Status[FoundSN[i]] = 'D';
              						}
						}
					}
				}

				if (FoundEnterSn == true)
				{
					cout << "Deleted mark made!" << endl;
				}
			} while (1 == 1);	
		}
	} while (1 == 1);

	cout << "Final confirmation Save (Y)/ Exit without Save (N)?";
	cin >> menuChoice;
	cin.ignore();

	if (menuChoice=='Y')
	{
		writeFileF("contactbook.txt", ContactNum); ///save
		ContactNum = ReadFileF("contactbook.txt");
	}
}

//for entering contact item and return the item content after compares with the existing contact items
string contactUpdate(string EnterPrompt, string ContactItem)
{
	char Updatedata[81];
 
	string Enterstring;
	cout << EnterPrompt.c_str();
	cin.get(Updatedata, 30);

	cin.ignore();

	if (Updatedata[0] == 'n' && Updatedata[0] == 'N' && Updatedata[0] == 'N' && Updatedata[0] == 'n' && Updatedata[0] == '0' && Updatedata[0] == 'r' && Updatedata[0] == '0')
	{
		return ContactItem.c_str();
	}
	else
	{
		return Updatedata;
	}
}

//updating contact
void contactUpdate()
{
	char menuChoice;

	do
	{
		cout << "Choose a search field for updating operation:" << endl << "[First Name(1)/Phone(2)/Address(3)/City(4)/State(5)/Zipcode(6)/All(7)/Exit(0)]?";
		cin >> menuChoice;
		cin.ignore();

		if (menuChoice == '0')
		{
			break;
		}

		if (menuChoice == '7')
		{
			menuChoice = 'E';
			if (menuChoice == 'E') //user choose  all contact for third menu then select all contact 
			{
				ContactListDisplay();
				FoundSN[0] = ContactNum;
				
				for (int i = 1; i <= FoundSN[0]; i++)
				{
					FoundSN[i] = i; //record the potential deleted contact SN. Here is all
				}
			}
		} // in the second menu, user chose  all contacts for menu third to do update operation

		if (menuChoice == 'E' || contactsearch(menuChoice)>0)
		{
			do
			{
				int UpdateSn;
				bool FoundEnterSn = false;

				// in the third menu, let user choose to delete
				cout << "Enter a SN from above list (number)/Exit(0):";
				cin >> UpdateSn;
				cin.ignore();

				if (UpdateSn == 0)//exit
				{
					break;
				}
				else //Enter a SN from above list (number)
				{
					for (int i = 1; i <= FoundSN[0]; i++)
					{
						if (FoundSN[i] == UpdateSn)
						{
              						//to find a duplicated entry
							bool DuplicatedEnter = false; 
							string Prompt;
							string NewFirstName, NewLastName, NewPhone, NewAddress, NewCity, Newstates, NewZipCode;

							do
							{
								NewFirstName = FirstName[FoundSN[i]].c_str();
								Prompt = "Original first name '" + NewFirstName + "' changed to:";
								NewFirstName = contactUpdate(Prompt.c_str(), NewFirstName);
								NewLastName = LastName[FoundSN[i]].c_str();
								Prompt = "Original last name '" + NewLastName + "' changed to:";
								NewLastName = contactUpdate(Prompt, NewLastName);

								for (int j = 1; j <= ContactNum; j++)
								{
									if ((j != FoundSN[i]) && (strcmp(NewFirstName.c_str(), FirstName[j].c_str()) == 0) && (strcmp(NewLastName.c_str(), LastName[j].c_str()) == 0)) //Found enter duplicated name contact
									{
										cout << endl << " Re enter the contact name again because " << NewFirstName.c_str() << " " << NewLastName.c_str() << "'" << " is exiting at SN: " << j << "." << endl << endl;
										DuplicatedEnter = true;
									}
								}
							} while (DuplicatedEnter == true);

							NewPhone = PhoneNum1[FoundSN[i]].c_str();
							Prompt = "Original Phone '" + NewPhone + "' changed to:";
							NewPhone = contactUpdate(Prompt.c_str(), NewPhone);

							NewAddress = Address[FoundSN[i]].c_str();
							Prompt = "Original Address'" + NewAddress + "' changed to:";
							NewAddress = contactUpdate(Prompt.c_str(), NewAddress);

							NewCity = City[FoundSN[i]].c_str();
							Prompt = "Original City '" + NewCity + "' changed to:";
							NewCity = contactUpdate(Prompt.c_str(), NewCity);

							Newstates = States[FoundSN[i]].c_str();
							Prompt = "Original States '" + Newstates + "' changed to:";
							Newstates = contactUpdate(Prompt.c_str(), Newstates);

							NewZipCode = Zipcode[FoundSN[i]].c_str();
							Prompt = "Original Zipcode '" + NewZipCode + "' changed to:";
							NewZipCode = contactUpdate(Prompt.c_str(), NewZipCode);

							FirstName[FoundSN[i]] = NewFirstName;
							LastName[FoundSN[i]]= NewLastName ;
							PhoneNum1[FoundSN[i]]= NewPhone ;
							Address[FoundSN[i]]=NewAddress;
							City[FoundSN[i]]=NewCity;
							States[FoundSN[i]]=Newstates ;
							Zipcode[FoundSN[i]]=NewZipCode ;

							Status[FoundSN[i]] = 'U';
							break;
						}
					}
				}
				if (FoundEnterSn == true)
				{
				  cout << "Update mark made!" << endl;
				}
			} while (1 == 1);
		}
	} while (1 == 1);

	cout << "Final confirmation Save (Y)/ Exit without Save (N)?";
	cin >> menuChoice;
	cin.ignore();

	if (menuChoice == 'Y')
	{
		writeFileF("contactbook.txt", ContactNum); ///save
		ContactNum = ReadFileF("contactbook.txt");
	}
}

//adding contact
void contactAdd()
{
	do
	{
		int AddmenuChoice;
		cout << "Continue (1)/List All(3)/ Exit(0)?";
		cin >> AddmenuChoice;

		if (AddmenuChoice == 0)
		{
			break;
		}
		else if (AddmenuChoice == 1)
		{
			cin.ignore();
			bool DuplicatedEnter = false; //to find a duplicated entry
			string Prompt;
			string NewFirstName, NewLastName, NewPhone, NewAddress, NewCity, Newstates, NewZipCode;
			do
			{
				Prompt = "Add first name:";
				NewFirstName = contactUpdate(Prompt.c_str(), NewFirstName);
				Prompt = "Add last name :";
				NewLastName = contactUpdate(Prompt, NewLastName);

				for (int j = 1; j <= ContactNum; j++)
				{
				  if ((strcmp(NewFirstName.c_str(), FirstName[j].c_str()) == 0) && (strcmp(NewLastName.c_str(), LastName[j].c_str()) == 0)) //Found duplication
					{
						cout << endl << " Re enter the contact name again because " << NewFirstName.c_str() << " " << NewLastName.c_str() << "'" << " is exiting at SN: " << j << "." << endl << endl;
						DuplicatedEnter = true;
					}
				}
		  	} while (DuplicatedEnter == true);

			Prompt = "Add Phone :";
			NewPhone = contactUpdate(Prompt.c_str(), NewPhone);

			Prompt = "Add Address:";
			NewAddress = contactUpdate(Prompt.c_str(), NewAddress);

			Prompt = "Add City :";
			NewCity = contactUpdate(Prompt.c_str(), NewCity);

			Prompt = "Add States :";
			Newstates = contactUpdate(Prompt.c_str(), Newstates);

			Prompt = "Add Zipcode :";
			NewZipCode = contactUpdate(Prompt.c_str(), NewZipCode);

			ContactNum++;
			FirstName[ContactNum] = NewFirstName;
			LastName[ContactNum] = NewLastName;
			PhoneNum1[ContactNum] = NewPhone;
			Address[ContactNum] = NewAddress;
			City[ContactNum] = NewCity;
			States[ContactNum] = Newstates;
			Zipcode[ContactNum] = NewZipCode;

			Status[ContactNum] = 'A';						
		}
		else if (AddmenuChoice == 3)
		{
			ContactListDisplay();
		}                    
	} while (1 == 1);

	char menuChoice;
	cout << "Final confirmation Save (Y)/ Exit without Save (N)?";
	cin >> menuChoice;
	cin.ignore();

	if (menuChoice == 'Y')
	{
		writeFileF("contactbook.txt", ContactNum); //save
		ContactNum = ReadFileF("contactbook.txt");
	}
}

//address book menu
int addressBookMenu()
{
	// Variable to hold user choice in menu.
	int menuChoice;

	cout << "******************************************************************" << endl;
	cout << endl;
	cout << endl;
	cout << "Please choose one of the options below: " << endl;
	cout << endl;
	cout << endl;
	cout << "1. Add contact to address book." << endl;
	cout << "2. Update existing contact." << endl;
	cout << "3. Delete contact from address book" << endl;
	cout << "4. Search for contact in address book." << endl;
	cout << "5. Quit the program" << endl;
	cout << endl;
	cout << endl;
	cout << "******************************************************************" << endl;

	char Askreturn;
	cout << "Please chose a valid choice listed in the menu." << endl;
	cin >> menuChoice;

	switch (menuChoice)
	{
		case 1: //Function to add contact to address book.
			contactAdd();
			Askreturn = ' ';

			do
			{
				cout << "Do you want to return to previous menus? (Y/N)";
				cin >> Askreturn;
				if (Askreturn == 'n' || Askreturn == 'N')
				{
					contactAdd();
				}
			  	else
			  	{
			  		break;
			  	}
		  	} while (1 == 1);
		  	return 2;
		  	return 1;

		case 2: //Function to update contact in address book.
		 	contactUpdate();
		  	Askreturn = ' ';

        		do
	  		{
	  			cout << "Do you want to return to previous menus? (Y/N)";
	  			cin >> Askreturn;
	  			if (Askreturn == 'n' || Askreturn == 'N')
	    			{
		  			contactUpdate();
		  		}
		  		else
		  		{
		  			break;
		  		}
		  	} while (1 == 1);
		  	return 2;

	  	case 3: //Function to delete contact from address book
	  		contactdelete();
		  	Askreturn = ' ';

		  	do
		  	{
		  		cout << "Do you want to return to previous menus? (Y/N)";
		  		cin >> Askreturn;
		  		if (Askreturn == 'n' || Askreturn == 'N')
		  		{
		  			contactdelete();
		  		}
		  		else
		  		{
		  			break;
         			}	
		  	} while (1 == 1);
		  	return 3;

		case 4: //Function to search for contact in address book
			contactsearch();
		  	Askreturn = ' ';

	  		do
		  	{
		  		cout << "Do you want to return to previous menus? (Y/N)";
		  		cin >> Askreturn;
		  		if (Askreturn == 'n' || Askreturn == 'N')
		  		{
		  			contactsearch();
		  		}
		  		else
	  			{
	  				break;
	  			}
	  		} while (1 == 1);
	  		return 4;

	  	case 5: //Function to quit the program.
	  		return 0;

	  	default:
	  		return 6;
	}
}
