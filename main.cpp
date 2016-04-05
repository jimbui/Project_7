#include <iostream>
#include "Address.h"
#include "Seat_Section.h"
#include "Seat.h"
#include "Seat_Row.h"
#include "New_Venue.h"
using namespace std;

Address* Create_Address() // address making.
{
   string street_address;
   string city;
   string state;
   int zip_code;

   cout << "Street Address: ";
   getline(cin, street_address);

   cout << "City: ";
   getline(cin, city);

   cout << "State: ";
   getline(cin, state);

   cout << "Zip Code: ";
   cin >> zip_code;
   cout << endl;

   Address* adr = new Address(street_address, city, state, zip_code);

   // Clean the input buffer
   while (cin.get() != '\n');

   return adr;
}

Seat_Section row_info() // copy-paste of section() almost , with some modifications.
{
   string rowname_[1000];
   int first[1000], last[1000];
   int i = 0, rows = 0;
   string sectionname = "NULL" ; // redundant.

   cout << "Enter seat row information." << " \n";
   cout << "Enter blank line for seat row name when finished." << " \n\n";

   while (true) // takes in the row names and seats per row.
   {
      cout << "Seat row name: " ;
//      cin.ignore(1, ' \n');
      getline(cin, rowname_[i]);

      if (rowname_[i] == "")
      {
         break;
      }

      rows++;

      cout << "Number of seats: " ;
      cin >> last[i] ;
      first[i] = 1 ;
      cout << " \n" ;
      i++;
   }

   Seat_Section seatsection = Seat_Section(sectionname, rowname_, first, last, rows);
   cout << " \n" ;
   return seatsection;
}

Seat_Section section() // creates sections , takes in row names and intervals per section.
{
   string sectionname;
   string rowname_[1000];
   int first[1000], last[1000];
   int i = 0, rows = 0;

   cout << "Enter seating section information." << " \n" ;
   cout << "Enter blank line for seating section name when finished." << " \n\n" ;
   cout << "Seating section name: " ;

   getline(cin, sectionname);
   cout << " \n" ;

   cout << "Enter row names and seat number ranges." << " \n";
   cout << "Enter a blank line for row name when finished with this section." << " \n\n" ;

   while (true)
   {
      cout << "Row name: ";
      getline(cin, rowname_[i]);

      if (rowname_[i] == "")
      {
         break;
      }


      rows++;

      cout << "First seat number: ";
      cin >> first[i];

      cout << "Last seat number: ";
      cin >> last[i];
      cout << endl;
      cin.ignore() ;

      i++;
   }

   Seat_Section seatsection = Seat_Section(sectionname, rowname_, first, last, rows);

   return seatsection;
}

//Seat_Row Create_Seat_Row()
//{
//
//}

New_Venue* Venue()
{
   string venue_name;

   cout << "Venue name: ";
   getline(cin, venue_name);

   Address* address = Create_Address();

   // All code up to this point works.

   New_Venue* new_venue = new New_Venue(venue_name, *address);

   // Create seat rows
   string row_name;
   int seat_count = 0;

   cout << "Enter seat row information." << " \n";
   cout << "Enter blank line for seat row name when finished." << " \n\n";

   while (true)
   {
	   cout << "Seat row name: ";
	   // cin.ignore(1, ' \n');
	   getline(cin, row_name);

	   if (row_name == "")
	   {
		   break;
	   }

	   cout << "Number of seats: ";
	   cin >> seat_count;
	   cout << " \n";

	   // Create new row and assign it to venue
	   new_venue->Add_Seat_Row(new Seat_Row(row_name, seat_count, "section")); //Change this!!!!!!

	   // Clean the input buffer
	   while (cin.get() != '\n');
   }

   // Create seat sections
   cout << "Enter seating section information." << " \n";
   cout << "Enter blank line for seating section name when finished." << " \n\n";

   string section_name;

   while (true)
   {
	   // Create new section
	   cout << "Seat Section name: ";
	   // cin.ignore(1, ' \n');
	   getline(cin, section_name);

	   if (section_name == "")
	   {
		   break;
	   }

	   cout << " \n";

	   // variables for seat section initialization
	   string row_name[1000];
	   int first_seat[1000];
	   int last_seat[1000];
		int row_count = 0;

		// Add data to arrays + display instructions
		cout << "Enter row names and seat number ranges." << " \n";
		cout << "Enter a blank line for row name when finished with this section." << " \n\n";

		// Iterate through each possible entry
		for (int i = 0; i < 1000; i++)
		{
			cout << "Row name: ";
			getline(cin, row_name[i]);

			if (row_name[i] == "")
			{
				cout << endl;
				break;
			}

			cout << "First seat number: ";
			cin >> first_seat[i];

			cout << "Last seat number: ";
			cin >> last_seat[i];
			cout << endl;
			// cin.ignore();

			row_count++;

			// Clean the input buffer
			while (cin.get() != '\n');
		}

	   // Create new section and assign it to venue
	   new_venue->Add_Seat_Section(new Seat_Section(section_name, row_name, first_seat, last_seat, row_count));
   }

   return new_venue;
}

int main()
{
   cout << "This is the New_Venue program." << " \n" ;
   cout << "Please enter venue information." << " \n\n" ;

   New_Venue* venue = Venue();

   cout << " \n" ;

   venue->Display();

   cin.get();
}
