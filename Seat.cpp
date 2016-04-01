#include <iostream>
#include "Seat.h"

using namespace std;

Seat::Seat(string Row_Name, int Seat_Number, string Seat_Section_Name) :seat_row_name(Row_Name),seat_number(Seat_Number),seat_section_name(Seat_Section_Name)
{}

// Code for selling a seat
//void Seat::Sell()
//{
//	sold = true;
//}

void Seat::Display() const
{
	cout << "Row " << seat_row_name << " Seat " << seat_number << " Section " << seat_section_name;
}
