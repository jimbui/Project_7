#include <iostream>
#include "Venue_from_Xml.h"
#include "tinyxml.h"
using namespace std;

void Venue_From_Xml::Get_Address(TiXmlNode* address_node)
{
	TiXmlNode* street_node = address_node->FirstChild();
	assert(street_node != 0);
	cout << street_node->FirstChild()->Value() << endl;
	TiXmlNode* city_node = street_node->NextSibling();
	assert(city_node != 0);
	cout << city_node->FirstChild()->Value() << ", ";
	TiXmlNode* state_node = city_node->NextSibling();
	assert(state_node != 0);
	cout << state_node->FirstChild()->Value() << " ";
	TiXmlNode* zip_code = state_node->NextSibling();
	assert(zip_code != 0);
	cout << zip_code->FirstChild()->Value() << endl;
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

void Venue_From_Xml::Get_Venue(TiXmlNode* venue_node)
{

	TiXmlNode* name_node = venue_node->FirstChild();
	assert(name_node != 0);
//	cout << name_node->Value() << endl;
	cout << endl;

	TiXmlNode* name_text_node = name_node->FirstChild();
	assert(name_text_node != 0);
	cout << name_text_node->Value() << endl;

	TiXmlNode* address_node = name_node->NextSibling();
	assert(address_node != 0);
//	cout << address_node->Value() << endl;

	Get_Address(address_node);

	TiXmlNode* seat_row_node = address_node->NextSibling();
	assert(seat_row_node != 0);
	Get_Seats(seat_row_node);

}