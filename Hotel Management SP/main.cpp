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

// Moved to dateLogic.cpp //

////////////////////////////////////////////////////TEMPLATE FOR OUTPUT////////////////////////////////////////////////////

template<typename T> void printElement(T t, const int& width);

//////////////////////////////////////////////////// MENU SELECTION - EDIT TO OUR NEEDS///////////////////////////////////////////////////////////

int getMenu(){
    int input;
    cout<<"=========================================GERRY HOTEL MANAGEMENT========================================="<<endl;
    cout<<"++MAIN MENU++\n\n";
    cout<<" 1.MANAGE ROOM\n 2.ADD RESERVATION\n 3.VIEW ROOM\n 4.VIEW RESERVATION \n 5.VIEW CUSTOMER \n 6.VIEW PAYMENT \n 7.SAVE CHANGES \n 0.EXIT"<<endl;

    cout<<"Please input the wanted operation code[1-6] otherwise  input '0' to exit: ";    cin>>input;
    //simple error checking- later add
    while(input<0 || input>6){
        cout<<"Wrong input!\n Please enter the correct operation code[0-6] : "; cin>>input;
    }
    
    return input;
}
/////////////////////////////////////////////////////////FIND FROM LIST////////////////////////////////////////////////////////////

// send id, will return index //

// moved to findFromList.cp //

//////////////////////////////////////////////////////////GET FROM TEXT FILE////////////////////////////////////////////////////////

//get all data in text file and add into the vector list //

// moved to getFromTextFile.cpp //

///////////////////////////////////////////////////////SAVE TO TEXTFILE/////////////////////////////////////////////////////////////

// save all data from vector list into text file //

// moved to saveToTextFile.cpp //

//////////////////////////////////////////////////////CUSTOMER MANAGEMENT//////////////////////////////////////////////////////////////////

void add_Customer(){
    customer newCustomer;
    cout<<"Enter the first name: "; cin>>newCustomer.firstName;
    cout<<"Enter the last name: "; cin>>newCustomer.lastName;
    cout<<"Enter the telephone number(without space): "; cin>>newCustomer.telephone;
    cout<<"Enter the ic number in the format(XXXXXX-XX-XXXX): ";cin>>newCustomer.ic_number;
    
    //find duplicate room in the vector list
    if(findCustomer(newCustomer.ic_number)!=-1){
       cout<< "The customer ic is already in the list, Please try again."<<endl;
        return; // end the function
    }

    /// add the room into the vector list
    arrCustomer.push_back(newCustomer);
    cout<<"OPERATION SUCCESS"<<endl;

}

//////////////////////////////////////////////////////RESERVATION MANAGEMENT -ALI//////////////////////////////////////////////////////////

// moved to reservationManagement.cpp //

///////////////////////////////////////////////////////ROOM MANAGEMENT - SIA //////////////////////////////////////////////////////////////

// moved to roomManagement.cpp //

///////////////////////////////////////////////////////MAIN FUNCTION////////////////////////////////////////////////////////////////

int main(){
    // must be at start to get the current data from file to the vector list
    ///
    get_arrCustomer();
    get_arrReservation();
    get_arrRoom();

    while(true){
        int selection=getMenu();
        if (selection==0)
        {
            break;
        }

        else if (selection==1){
            add_Room();

            set_arrRoom(); //to update the textfile
            cout<<"complete save";
        }

        else if (selection == 2) {
            add_Reservation();
        }

        else if (selection==3){
            view_Room();
        }

        else if (selection==4){
            view_Reservation();
        }


    //use all the set_arrXXXXX() to write back from the vector list to the textfile. Happy coding i guess. Please don't be ambitious for 5% project.Thenks
        
    }
    




   



    return 0;
}