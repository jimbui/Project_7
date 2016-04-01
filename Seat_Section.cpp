#include "Seat_Section.h"
#include <iostream>
#include <string>

using namespace std ;


Seat_Section::Seat_Section(const string Section_Name, string Row_Name[], int First_Seat[], int Last_Seat[] , int rows) 
{
   section_name = Section_Name ;
   int i = 0 ;
   row_count=0;
   int value;
   string name;
   while (i < rows)
   {
      name = Row_Name[i] ;
      row_name[i] = name ;
      value = First_Seat[i] ;
      first_seat[i] = value ;
      value = Last_Seat[i] ;
      last_seat[i] = value ;
      i++ ;
   }

   row_count = rows ;
} ;

void Seat_Section::Display() const
{
   cout << "Section " << section_name << " \n" ;
   int i = 0 ;
   cout << " \n" ;
   while (i < row_count)
   {
      cout << "Row " << row_name[i] << "       " << "Seats " << first_seat[i] << " - " << last_seat[i] << " \n" ;
      i++ ;
   }
}

void Seat_Section::Display_Row() const // modified version of Display().
{
   int i = 0;

   while (i < row_count)
   {
      cout << "Row " << row_name[i] << "       " << "Seats " << first_seat[i] << " - " << last_seat[i] << " \n";
      i++;
   }
   cout << " \n" ;
}

// Iterates through each seat on the seat row and assigns the seat pointers to 
// the seat section's seat pointer array.  Note that 0 corresponds to seat 1, 1 --> 2, etc.
void Seat_Section::Add_Seats_From_Row(const Seat_Row& seat_row, int First_Seat, int Last_Seat)
{
	for (int i = First_Seat; i <= Last_Seat; i++)
	{
		seat[seat_count] = seat_row.Get_Seat(i);

		seat_count++;
	}
}
