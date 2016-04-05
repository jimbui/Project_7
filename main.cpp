#include <iostream>

#include "Address.h"
#include "New_Venue.h"
#include "Seat.h"
#include "Seat_Row.h"
#include "Seat_Section.h"
#include "tinyxml.h"
#include "Venue_From_Xml.h"

using namespace std ;

int number_of_seats = 0 ;

Address* Create_Address(TiXmlNode* venue_node) // takes in a node and extracts the address.
{
   string street_address = venue_node->FirstChild()->NextSibling()->FirstChild()->FirstChild()->Value() ; // value of street.
   string city = venue_node->FirstChild()->NextSibling()->FirstChild()->NextSibling()->FirstChild()->Value() ; // ^
   string state = venue_node->FirstChild()->NextSibling()->FirstChild()->NextSibling()->NextSibling()->FirstChild()->Value() ; // ^
   int zip_code = std::stoi(venue_node->FirstChild()->NextSibling()->FirstChild()->NextSibling()->NextSibling()->NextSibling()->FirstChild()->Value()) ; // ^ , converts the string read in to an int.

   Address* adr = new Address(street_address , city , state , zip_code) ;

   // while (cin.get() != '\n') ; // cleans the input buffer.

   return adr ;
}

Address* Create_Address() // original.
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

New_Venue* Venue() // original.
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

New_Venue* Create_Venue(TiXmlNode* venue_node)
{
   string venue_name = venue_node->FirstChild()->FirstChild()->Value() ;
   Address* address = Create_Address(venue_node) ;

   New_Venue* new_venue = new New_Venue(venue_name , *address) ;
   return new_venue;
}

Seat* Get_Seat_Array(TiXmlNode* venue_node) // this will return an array of all seats.
{
   int i = 0 ;
   static Seat seat_array[1000] ;

   TiXmlNode* seat_row_node = venue_node->FirstChild()->NextSibling()->NextSibling() ;
   assert(seat_row_node != 0) ;

   while (seat_row_node != 0) // iterates through all rows.
   {
      TiXmlNode* name_node = seat_row_node->FirstChild("name") ;
      assert(name_node != 0) ;
      TiXmlNode* seat_node = seat_row_node->FirstChild("seat") ;

      while (seat_node != 0) // iterates through all seats in this row.
      {
         TiXmlNode* number_node = seat_node->FirstChild("number");
         TiXmlNode* section_node = seat_node->FirstChild("section");
         seat_node = seat_node->NextSibling() ;

         seat_array[i] = Seat(name_node->FirstChild()->Value() , std::stoi(number_node->FirstChild()->Value()) , section_node->FirstChild()->Value()) ;

         number_of_seats++ ;
         i++ ;
      }

      seat_row_node = seat_row_node->NextSibling();
   }

   return seat_array ;
}

int main()
{
   std::cout << "testing the XML stuff." << " \n\n" ;
   string filename = "Venue.xml" ; // test file.

   // loading file and creating first node venue_node.

   TiXmlDocument doc(filename) ;
   bool loadOkay = doc.LoadFile() ; 

   if (!loadOkay)
   {
      std::cout << "Could not load file " << filename << "." << " \n" ;
      cout << "Error = \"" << doc.ErrorDesc() << "\".  Exiting." << " \n" ;
      cin.get() ; exit(1) ;
   }

   std::cout << "file " << filename << " read in." << " \n\n" ;
   TiXmlNode* venue_node = doc.FirstChild("venue_file")->FirstChild() ; 

   // New_Venue* venue = Create_Venue(venue_node) ;
   // venue->Display() ; // does nothing for now.

   Seat* p = Get_Seat_Array(venue_node) ;

   std::cout << "displaying array." << " \n\n" ;

   for (int i = 0 ; i < number_of_seats ; i++)
   {
      p->Display() ;
      std::cout << " \n" ;
      p++ ;
   }

   std::cout << " \n" << "end program." << " \n\n" ;
}












