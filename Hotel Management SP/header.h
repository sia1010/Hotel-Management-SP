#ifndef HEADER_H
#define HEADER_H

#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<iomanip>
#include<vector>
#include"header.h"
using namespace std;

// Declarations

/////////////////////////////////////////////////////USER STRUCT DECLARATION////////////////////////////////////////////////////////
struct customer {
    string firstName = "";
    string lastName = "";
    string telephone = "";
    char ic_number[15] = "000000-00-0000"; // primary key
};

struct room {
    int id = -1; //primary key
    char type[20];
    double price;
    bool reserved = false;
};


struct reservation {
    int id;//primary key 
    char customer_ic[15];
    int room_id;
    string check_in;
    string check_out;
    double charged_price;
    double deposit;
};

struct date {
    int day;
    int month;
    int year;
};

//////////////////////////////////////////////////////VECTOR DECLARATION///////////////////////////////////////////////////////////////
extern vector<room> arrRoom;
extern vector<reservation> arrReservation;
extern vector<customer> arrCustomer;

////////////////////////////////////////////////////TEMPLATE FOR OUTPUT////////////////////////////////////////////////////
const char separator = ' ';

template<typename T> void printElement(T t, const int& width){
    cout << left << setw(width) << setfill(separator) << t;
    cout << "|";
}

/////////////////////////////////////////////////////MAIN FUNCTION DECLARATION//////////////////////////////////////////////////////
int main();

/////////////////////////////////////////////////////DATE LOGIC DECLARATION/////////////////////////////////////////////////////////
int check_leap_year(int);
int no_of_days_in_month(int,int);
long long int difference_of_days(int,int,int,int,int,int);
bool validDate(int,int,int,int);
date getDate();
int getDurationOfStay(int,int,int,int,int,int);

/////////////////////////////////////////////////////////FIND FROM LIST////////////////////////////////////////////////////////////
int findRoom(int room_id);
int findCustomer(char ic[]);
int findReservation(int id);

//////////////////////////////////////////////////////////GET FROM TEXT FILE////////////////////////////////////////////////////////
void get_arrRoom();
void get_arrCustomer();
void get_arrReservation();

///////////////////////////////////////////////////////SAVE TO TEXTFILE/////////////////////////////////////////////////////////////
void set_arrRoom();
void set_arrCustomer();
void set_arrReservation();

//////////////////////////////////////////////////////RESERVATION MANAGEMENT -ALI//////////////////////////////////////////////////////////
void view_Reservation();
void add_Reservation();

///////////////////////////////////////////////////////ROOM MANAGEMENT - SIA //////////////////////////////////////////////////////////////
void view_Room();
void add_Room();
void delete_Room();
#endif 
