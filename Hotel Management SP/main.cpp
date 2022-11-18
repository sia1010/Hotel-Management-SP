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

//////////////////////////////////////////////////////VECTOR DECLARATION///////////////////////////////////////////////////////////////
vector<room> arrRoom;
vector<reservation> arrReservation;
vector<customer> arrCustomer;

/////////////////////////////////////////////////////FUNCTIONS//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////DATE IMPLEMENTATION////////////////////////////////////////////////////

// ali's blood and sweat //
// Moved to dateLogic.cpp //

/////////////////////////////////////////////////////////FIND FROM LIST////////////////////////////////////////////////////////////

// send id, will return index //
// moved to findFromList.cpp //

//////////////////////////////////////////////////////////GET FROM TEXT FILE////////////////////////////////////////////////////////

// get all data in text file and add into the vector list //
// moved to getFromTextFile.cpp //

///////////////////////////////////////////////////////SAVE TO TEXTFILE/////////////////////////////////////////////////////////////

// save all data from vector list into text file //
// moved to saveToTextFile.cpp //

//////////////////////////////////////////////////////RESERVATION MANAGEMENT -ALI//////////////////////////////////////////////////////////

// moved to reservationManagement.cpp //

///////////////////////////////////////////////////////ROOM MANAGEMENT - SIA //////////////////////////////////////////////////////////////

// moved to roomManagement.cpp //

//////////////////////////////////////////////////////CUSTOMER MANAGEMENT//////////////////////////////////////////////////////////////////

void add_Customer() {
    customer newCustomer;
    cout << "Enter the first name: "; cin >> newCustomer.firstName;
    cout << "Enter the last name: "; cin >> newCustomer.lastName;
    cout << "Enter the telephone number(without space): "; cin >> newCustomer.telephone;
    cout << "Enter the ic number in the format(XXXXXX-XX-XXXX): ";cin >> newCustomer.ic_number;

    //find duplicate room in the vector list
    if (findCustomer(newCustomer.ic_number) != -1) { //this is broken
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
        int custIndex = findCustomer(CustomerIC); //this is broken

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
////////////////////////////////////////////////////TEMPLATE FOR OUTPUT////////////////////////////////////////////////////

template<typename T> void printElement(T t, const int& width);

//////////////////////////////////////////////////// MENU SELECTION - EDIT TO OUR NEEDS///////////////////////////////////////////////////////////

int getMenu() {
    int input;
    cout << "=========================================GERRY HOTEL MANAGEMENT=========================================" << endl;
    cout << "++MAIN MENU++\n\n";
    cout << " 1. MANAGE ROOM\n 2. ADD RESERVATION\n 3. VIEW ROOM\n 4. VIEW RESERVATION \n 5. ADD CUSTOMER \n 6. VIEW CUSTOMER \n 7. SAVE CHANGES \n 0. EXIT" << endl;

    cout << "Please input the wanted operation code[1-7], otherwise input '0' to exit: "; cin >> input;
    //simple error checking- later add
    while (input < 0 || input>7) {
        cout << "Wrong input!\n Please enter the correct operation code [0-7]: "; cin >> input;
    }

    return input;
}

///////////////////////////////////////////////////////MAIN FUNCTION////////////////////////////////////////////////////////////////

int main(){
    // must be at start to get the current data from file to the vector list
    ///
    get_arrCustomer();
    get_arrReservation();
    get_arrRoom();

    while(true){
        int selection=getMenu();
        if (selection == 0){
            break;
        }

        else if (selection == 1){
            manage_Room();

            set_arrRoom(); //to update the textfile
            cout << "SAVED SUCCESSFULLY!" << endl;
        }

        else if (selection == 2) {
            add_Reservation();

            set_arrReservation();
            cout << "SAVED SUCCESSFULLY!" << endl;
        }

        else if (selection == 3){
            view_Room();
        }

        else if (selection == 4){
            view_Reservation();
        }

        else if (selection == 5) {
            add_Customer();

            set_arrCustomer();
        }
        else if (selection == 6) {
            view_Customer();
        }

        else if (selection == 7) {

            set_arrRoom();
            set_arrCustomer();
            set_arrReservation();
            cout << "SAVED SUCCESSFULLY!" << endl;

        }
    //use all the set_arrXXXXX() to write back from the vector list to the textfile. Happy coding i guess. Please don't be ambitious for 5% project.Thenks
        
    }
    




   



    return 0;
}