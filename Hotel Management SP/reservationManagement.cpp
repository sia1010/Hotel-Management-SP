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

void view_Reservation() {
    cout << endl << "-------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    printElement("ID", 5);
    printElement("CUSTOMER IC", 15);
    printElement("CUSTOMER NAME", 30);
    printElement("ROOM ID", 9);
    printElement("CHECK IN", 12);
    printElement("CHECK OUT", 12);
    printElement("TOTAL CHARGED", 20);
    printElement("DEPOSIT", 20);
    printElement("OUTSTANDING FEE", 20);
    cout << endl << "-------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < arrReservation.size(); i++)
    {
        printElement(arrReservation[i].id, 5);
        printElement(arrReservation[i].customer_ic, 15);
        //find customer based on ic
        int custIndex = findCustomer(arrReservation[i].customer_ic);
        printElement(arrCustomer[custIndex].firstName + " " + arrCustomer[custIndex].lastName, 30);
        printElement(arrReservation[i].room_id, 9);
        printElement(arrReservation[i].check_in, 12);
        printElement(arrReservation[i].check_out, 12);

        //format 2 decimal place money
        char str[20];
        sprintf_s(str, "RM %.2f", arrReservation[i].charged_price);
        printElement(str, 20);
        sprintf_s(str, "RM %.2f", arrReservation[i].deposit);
        printElement(str, 20);
        sprintf_s(str, "RM %.2f", arrReservation[i].charged_price - arrReservation[i].deposit);
        printElement(str, 20);
        cout << endl;
    }

    cout << endl << endl;


}

void add_Reservation() {

    cout << endl << "--------------------------ADD RESERVATION----------------------" << endl;
    reservation newReservation;
    cout << "Enter the customer ic_number: "; cin >> newReservation.customer_ic;
    cout << "Enter the room ID: "; cin >> newReservation.room_id;
    cout << "Enter the check in date :";
    date check_in = getDate();
    cout << "Enter the check out date :";
    date check_out = getDate();
    //find for the price of the room and duration of stay
    double roomPrice = arrRoom[findRoom(newReservation.room_id)].price;
    int duration = getDurationOfStay(check_in.day, check_out.day, check_in.month, check_out.month, check_in.year, check_out.year);
    newReservation.charged_price = roomPrice * duration;
    cout << "Total charges is RM " << newReservation.charged_price << endl;
    cout << "Enter the deposited money: ";cin >> newReservation.deposit;
    //error checking 
    if ((findRoom(newReservation.room_id) == -1) || findCustomer(newReservation.customer_ic) == -1) {
        //no record of room or customer in 
        cout << "Error occur since the room ID or customer ID is not in the system. Please add the new room/customer if you still want to add the reservation." << endl;
        return;//exit
    }

    else if (arrRoom[findRoom(newReservation.room_id)].reserved) {
        cout << "The room is already reserved. Please try again." << endl;
        return;

    }

    newReservation.id = arrReservation.size() + 1;

    arrReservation.push_back(newReservation);
    //CHANGE THE ROOM CONDITION FROM VACANT TO RESERVED
    arrRoom[findRoom(newReservation.room_id)].reserved = true;

    cout << "Operation successful!" << endl;


}