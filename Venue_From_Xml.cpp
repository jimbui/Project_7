#include <iostream>
#include <string>
#include "Venue_From_Xml.h"
#include "tinyxml.h"
#include "New_Venue.h"
#include "Address.h"
#include "Seat.h"
#include "Seat_Row.h"
#include "Seat_Section.h"
using namespace std;

Address* Venue_From_Xml::Get_Address(TiXmlNode* venue_node)
{
   string street_address = venue_node->FirstChild()->NextSibling()->FirstChild()->FirstChild()->Value() ; // value of street.
   string city = venue_node->FirstChild()->NextSibling()->FirstChild()->NextSibling()->FirstChild()->Value() ; // ^
   string state = venue_node->FirstChild()->NextSibling()->FirstChild()->NextSibling()->NextSibling()->FirstChild()->Value() ; // ^
   int zip_code = std::stoi(venue_node->FirstChild()->NextSibling()->FirstChild()->NextSibling()->NextSibling()->NextSibling()->FirstChild()->Value()) ; // ^ , converts the string read in to an int.

   Address* adr = new Address(street_address , city , state , zip_code) ;

   return adr;
}

void Venue_From_Xml::Get_Seat(TiXmlNode* seat_node)
{
	TiXmlNode* number_node = seat_node->FirstChild("number");
	cout << number_node->Value() << ": ";
	cout << number_node->FirstChild()->Value() << " ";
	TiXmlNode* section_node = seat_node->FirstChild("section");
	cout << section_node->Value() << ": ";
	cout << section_node->FirstChild()->Value() << endl;
}

void Venue_From_Xml::Get_Seat_Row(TiXmlNode* seat_row_node)
{
//	cout << seat_row_node->Value() << endl;
	TiXmlNode* name_node = seat_row_node->FirstChild("name");
	assert(name_node != 0);
//	cout << name_node->Value() << " ";
//	cout << name_node->FirstChild()->Value() << " ";

	TiXmlNode* seat_node = seat_row_node->FirstChild("seat");
	while (seat_node != 0)
	{
		cout << name_node->Value() << " ";
		cout << name_node->FirstChild()->Value() << " ";
		cout << seat_node->Value() << " ";
		Get_Seat(seat_node);
		seat_node = seat_node->NextSibling();
	}


}

void Venue_From_Xml::Get_Seats(TiXmlNode* seat_row_node)
{
	while (seat_row_node != 0)
	{
		Get_Seat_Row(seat_row_node);
		seat_row_node = seat_row_node->NextSibling();
	}

}

New_Venue* Venue_From_Xml::Get_Venue(TiXmlNode* venue_node)
{

	TiXmlNode* name_node = venue_node->FirstChild();
	assert(name_node != 0);
//	cout << name_node->Value() << endl;
	cout << endl;

	TiXmlNode* name_text_node = name_node->FirstChild();
	assert(name_text_node != 0);
	//cout << name_text_node->Value() << endl;

	string venue_name = venue_node->FirstChild()->FirstChild()->Value() ;

	TiXmlNode* address_node = name_node->NextSibling();
	assert(address_node != 0);
	//cout << address_node->Value() << endl;

	Address* address = Get_Address(venue_node);

	New_Venue* new_venue = new New_Venue(venue_name , *address);

	TiXmlNode* seat_row_node = address_node->NextSibling();
	assert(seat_row_node != 0);
	//Get_Seats(seat_row_node);

	return new_venue;

}
