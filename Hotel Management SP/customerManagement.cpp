#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<iomanip>
#include<vector>
#include"header.h"
using namespace std;

/////////////////////////////////////////////////////USER STRUCT DECLARATION////////////////////////////////////////////////////////
struct customer;
struct room;
struct date;
struct reservation;


void add_Customer() {
    customer newCustomer;
    cout << "Enter the first name: "; cin >> newCustomer.firstName;
    cout << "Enter the last name: "; cin >> newCustomer.lastName;
    cout << "Enter the telephone number(without space): "; cin >> newCustomer.telephone;
    cout << "Enter the ic number in the format(XXXXXX-XX-XXXX): ";cin >> newCustomer.ic_number;

    //find duplicate room in the vector list
    if (findCustomerUsingDifferentVariable(newCustomer.ic_number) != -1) { //this is broken
        cout << "The customer ic is already in the list, Please try again." << endl;
        return; // end the function
    }

    /// add the room into the vector list
    arrCustomer.push_back(newCustomer);
    cout << "SAVED SUCCESSFULLY!" << endl;

}
void view_Customer() {

    char CustomerIC[15];

    cout << "Enter customer IC number: "; cin >> CustomerIC;

    //find customer based on ic
    int custIndex = findCustomerUsingDifferentVariable(CustomerIC); 

    //print output
    if (custIndex != -1) {
        cout << endl << "-------------------------------------------------------------------------------" << endl;
        printElement("CUSTOMER IC", 15);
        printElement("FIRST NAME", 20);
        printElement("LAST NAME", 20);
        printElement("TELEPHONE NUMBER", 20);

        cout << endl << "-------------------------------------------------------------------------------" << endl;

        printElement(arrCustomer[custIndex].ic_number, 15);
        printElement(arrCustomer[custIndex].firstName, 20);
        printElement(arrCustomer[custIndex].lastName, 20);
        printElement(arrCustomer[custIndex].telephone, 20);
    }
    else {
        cout << "The customer IC number entered does not exist in the database.";
    }


    cout << endl << endl;


}