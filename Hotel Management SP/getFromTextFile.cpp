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

void get_arrRoom() {

    ifstream file;
    file.open("room.txt");

    while (!file.eof()) {
        room currRoom;
        file >> currRoom.id >> currRoom.type >> currRoom.price >> currRoom.reserved;
        arrRoom.push_back(currRoom); //add the room to the list
    }
    file.close();
}
//get all customer in the text file and add into the vector list
void get_arrCustomer() {
    ifstream file;
    file.open("customer.txt");

    while (!file.eof()) {
        customer currCust;
        file >> currCust.firstName >> currCust.lastName >> currCust.telephone >> currCust.ic_number;
        arrCustomer.push_back(currCust); //add the room to the list
    }
    file.close();
}
//get all reservation in the text file and add into the vector list
void get_arrReservation() {
    ifstream file;
    file.open("reservation.txt");
    while (!file.eof()) {
        reservation currReservation;

        file >> currReservation.id >> currReservation.customer_ic >> currReservation.room_id;
        file >> currReservation.check_in >> currReservation.check_out >> currReservation.charged_price >> currReservation.deposit;
        arrReservation.push_back(currReservation);
    }
    file.close();
}