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

int findRoom(int room_id) {

    //tranverse through every room and find the specific room
    bool found = false;

    for (int i = 0; i < arrRoom.size(); i++)
    {
        if (arrRoom[i].id == room_id)
        {

            found = true;
            return i;

        }
    }

    return -1;//not found
}

int findCustomer(char ic[]) {

    //tranverse through every customer and find the specific customer
    bool found = false;

    for (int i = 0; i < arrCustomer.size(); i++)
    {
        if (strcmp(arrCustomer[i].ic_number, ic) == 0)
        {

            found = true;
            return i;

        }
    }

    return -1;//not found
}

int findReservation(int id) {

    //tranverse through every reservation and find the specific reservation
    bool found = false;

    for (int i = 0; i < arrReservation.size(); i++)
    {
        if (arrReservation[i].id == id)
        {

            found = true;
            return i;

        }
    }

    return -1;//not found
}