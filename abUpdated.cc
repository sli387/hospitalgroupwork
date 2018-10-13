#include <iostream>
using namespace std;

struct Person {
  string firstName;
  string lastName;
  string phoneNumber;
  string houseNumber;
  string streetName;
  string address;

  struct Person* next;
};

//get the head of the list and the number, and return the data
void search(struct Person** head) {
  struct Person* current = *head;
  string firstName;

  cout << "Type in first name : ";
  cin >> firstName;

  while(current != nullptr){
    if(current -> firstName == firstName){
      cout << current -> firstName << "\n" << current -> lastName << "\n" << current -> phoneNumber << "\n" << current -> address;
      return;
    }
    current = current -> next;
  }
  return;
}

void update(struct Person** head) {
  struct Person* current = *head;
  string firstName;
  string lastName;
  string phoneNumber;
  string houseNumber;
  string streetName;
  string address;
  int choice;

  cout << "Type in first name : ";
  cin >> firstName;

  while(current != nullptr){
    if(current -> firstName == firstName){
      cout << current -> firstName << "\n" << current -> lastName << "\n" << current -> phoneNumber << "\n" << current -> address;
      cout << "What would you like to change ?\n";
      cout << "\t1. Name\n" << "\t2. Phone Number\n" << "\t3. Address";
      cin >> choice;
      switch (choice){
        case 1:
          cout << "Change : \n \t 1. First name \n \t 2. Last Name";
          if(choice == 1) {
            cout << " New First Name : ";
            cin >> firstName;
            current -> firstName = firstName;
          } else if(choice == 2) {
            cout << " New Last Name : ";
            cin >> lastName;
            current -> lastName = lastName;
          }
          break;
        case 2:
          cout << " New Number : ";
          cin >> phoneNumber;
          current -> phoneNumber = phoneNumber;
          break;
        case 3:
          cout << " New Address : \n \t House Number and Street Name";
          cin >> houseNumber >> streetName;
          address = houseNumber + " " + streetName;
          current -> address = address;
          break;
      }
      return;
    }
    current = current -> next;
  }
  cout << "Contact not in Book";
  return;
}

void add(struct Person** head) {
  struct Person* newContact = new Person;
  struct Person* last = *head;

  string firstName;
  string lastName;
  string phoneNumber;
  string houseNumber;
  string streetName;
  string address;
  
  cout << "First Name : ";
  cin >> firstName;
  cout << "Last Name : ";
  cin >> lastName;
  cout << "Phone Number : ";
  cin >> phoneNumber;
  cout << "House Number and Street Name : ";
  cin >> houseNumber >> streetName;
  address = houseNumber + " " + streetName;

  newContact -> firstName = firstName;
  newContact -> lastName = lastName;
  newContact -> phoneNumber = phoneNumber;
  newContact -> address = address;
  newContact -> next = nullptr;

  if(*head == nullptr) {
    *head = newContact;
    return;
  }
  while(last -> next != nullptr) {
    last = last -> next;
  }
  last -> next = newContact;
  return;
}

int main() {
  struct Person* head = new Person;
  head = nullptr;

  add(&head);
  add(&head);
  search(&head);
  update(&head);

  struct Person* myList = head;
  struct Person* iter = myList;
  while(iter != nullptr){
    cout << iter -> firstName << " ";
    iter = iter -> next;
  }
  cout << "\\0" << endl;
  
}
