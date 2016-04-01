#pragma once

#include "Seat.h"
#include "Seat_Row.h"
#include <string>

using namespace std;

class Seat_Section
{
   public:

   static const int MAX_SEATS_PER_SECTION = 1000 ;

   private:

   string section_name ;

   string row_name[1000] ; 
   int first_seat[1000] ;
   int last_seat[1000] ;

   const Seat* seat[MAX_SEATS_PER_SECTION] ;

   int seat_count ;
   int row_count  ;

   public:

   Seat_Section(){} ;
   Seat_Section(const string Section_Name, string Row_Name[], int First_Seat[], int Last_Seat[] , int rows);

   // Add seats from a specific row to a seat section
   void Add_Seats_From_Row(const Seat_Row& seat_row, int First_Seat, int Last_Seat);

   

   void Display() const ;
   void Display_Row() const;

   string Get_Name(){return section_name; } ;

   string Get_Row_Element(int index) { return row_name[index]; };
   int Get_First_Seat_Element(int index) { return first_seat[index]; };
   int Get_Last_Seat_Element(int index) { return last_seat[index]; };
   int Get_Row_Count() const { return row_count; };
};

