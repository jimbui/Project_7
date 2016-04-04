#include <iostream>
#include <string>
#include <cassert>
#include "Seat_Row.h"
using namespace std;

Seat_Row::Seat_Row(const string& Row_Name, int Number_Of_Seats, const string& Section_Name) :
	row_name(Row_Name),
	section_name(Section_Name),
	number_of_seats(0)
{
	for (int i = 0; i < Number_Of_Seats; i++)
	{
		Add_Seat(new Seat(Row_Name, i + 1, Section_Name));
	}
}

bool Seat_Row::operator>(const Seat& other) 
{
		if (this->row_name == other.SEAT_NAME()) 
		{ 
			return this->number_of_seats > other.SEAT_NUM(); 
		} 

		return this->row_name > other.SEAT_NAME(); 
	
}

void Seat_Row::Add_Seat(/*const*/ Seat* new_seat)
{
	assert(number_of_seats < MAX_SEATS_PER_ROW);
	seats[number_of_seats++] = new_seat;
}

void Seat_Row::Display() const
{
	cout << "Row " << row_name << " Seats " << "1-" << number_of_seats << " Section "<< section_name << endl;

	//for (int i = 0; i < number_of_seats; ++i)
	//{
	//	//;
	//	//cout << "\t";		// Indent the Seat description
	//	//seats[i]->Display();
	//}
}

//void Seat_Row::Sort_Seats()const
//{
//	for (int i = 0; i < number_of_seats; ++i)
//	{
//		if (*seats[i]->seat_number < *seats[i + 1]->seat_number)
//		{
//
//		}
//	}
//}