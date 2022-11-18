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

void set_arrRoom() {
    ofstream file;
    file.open("room.txt");
    for (auto i = arrRoom.begin(); i != arrRoom.end(); ++i) {
        file << (*i).id << " " << (*i).type << " " << (*i).price << " " << (*i).reserved;
        if (i != arrRoom.end() - 1) {
            file << endl;
        }
    }
    file.close();
}

void set_arrCustomer() {
    ofstream file;
    file.open("customer.txt");
    for (auto i = arrCustomer.begin(); i != arrCustomer.end(); ++i) {
        file << (*i).firstName << " " << (*i).lastName << " " << (*i).telephone << " " << (*i).ic_number;
        if (i != arrCustomer.end() - 1) {
            file << endl;
        }
    }
    file.close();
}

void set_arrReservation() {
    ofstream file;
    file.open("reservation.txt");
    for (auto i = arrReservation.begin(); i != arrReservation.end(); ++i) {
        file << (*i).id << " " << (*i).customer_ic << " " << (*i).room_id << " " << (*i).check_in << " " << (*i).check_out << " " << (*i).charged_price << " " << (*i).deposit;
        if (i != arrReservation.end() - 1) {
            file << endl;
        }
    }
    file.close();
}