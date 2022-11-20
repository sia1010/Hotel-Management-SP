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
        cout << "The room ID is already in the list, Please try again with different ID." << endl;
        return; // end the function
    }

    //add the room into the vector list
    arrRoom.push_back(newRoom);
    cout << "Successfully added!" << endl;

}

void edit_Room() {
    cout << endl << "--------------------------EDIT ROOM----------------------" << endl;
    int target_id; room editRoom;
    cout << "Enter the room ID that you wish to edit: "; cin >> target_id;

    //find if room exists
    int index = findRoom(target_id);
    if (index == -1) {
        cout << "The ID is not in the list. Please try again." << endl;
        return;
    }

    editRoom.id = target_id;
    cout << "Enter the new type of room: "; cin >> editRoom.type;
    cout << "Enter the new price of room (RM): "; cin >> editRoom.price;

    //proceed to edit the room
    arrRoom.at(index) = editRoom;
    cout << "Successfully edited" << endl;

}

void manage_Room() {
    int selection;
    cout << endl << "--------------------------ROOM MANAGEMENT----------------------" << endl 
        << "1.Add A New Room\n2.Edit An Existing Room" << endl;
    cout << "Please input the wanted operation code[1-2], otherwise input '0' to cancel: "; cin >> selection;

    //simple error checking
    while (selection < 0 || selection>2) {
        cout << "Wrong input!\n Please enter the correct operation code [0-2]: "; cin >> selection;
    }

    if (selection == 1) {
        add_Room();
    }
    else if (selection == 2) {
        edit_Room();
    }
}
