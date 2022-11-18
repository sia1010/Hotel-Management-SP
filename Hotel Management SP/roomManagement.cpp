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

void view_Room() {
    string status;
    cout << endl << "-------------------------------------------------------------" << endl;
    printElement("ID", 5);
    printElement("ROOM TYPE", 15);
    printElement("PRICE", 20);
    printElement("RESERVATION STATUS", 20);
    cout << endl << "-------------------------------------------------------------" << endl;

    for (auto i = arrRoom.begin(); i != arrRoom.end(); i++)
    {
        printElement((*i).id, 5);
        printElement((*i).type, 15);
        //format 2 decimal place money
        char str[20];
        sprintf_s(str, "RM %.2f", (*i).price);
        printElement(str, 20);
        if ((*i).reserved == true) {
            status = "RESERVED";
        }
        else {
            status = "VACANT";
        }
        printElement(status, 20);
        cout << endl;
    }

    cout << endl << endl;

}
void add_Room() {
    cout << endl << "--------------------------ADD ROOM----------------------" << endl;
    room newRoom;
    cout << "Enter the room id: "; cin >> newRoom.id;
    cout << "Enter the type of room: "; cin >> newRoom.type;
    cout << "Enter the price of room (RM): "; cin >> newRoom.price;

    //find duplicate room in the vector list
    if (findRoom(newRoom.id) != -1) {
        cout << "The room id is already in the list, Please try again with different id" << endl;
        return; // end the function
    }

    /// add the room into the vector list
    arrRoom.push_back(newRoom);
    cout << "OPERATION SUCCESS" << endl;

}

void delete_Room() {
    cout << endl << "--------------------------DELETE ROOM----------------------" << endl;
    int target_id;
    cout << "Enter the room id that you wish to delete: "; cin >> target_id;
    int index = findRoom(target_id);
    if (index == -1) {
        cout << "The id is not in the list. Please try again" << endl;

    }

    //proceed to delete the room
    arrRoom.erase(arrRoom.begin() + index);
    cout << "Successfully delete" << endl;

}