#include <iostream>
#include "Seat.h"

using namespace std;

Seat::Seat(string Row_Name,
	int Seat_Number) :
	seat_row_name(Row_Name),
	seat_number(Seat_Number),
	sold(false)
{}

// Code for selling a seat
void Seat::Sell()
{
	sold = true;
}

void Seat::Display() const
{
	cout << "Row " << seat_row_name << " Seat " << seat_number /* Test Code */ << " (Sold:  " << sold << ")" /* End Test Code */ << endl;
}
