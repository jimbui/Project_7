#pragma once
#include "tinyxml.h"
#include <iostream>
#include "tinyxml.h"
#include "New_Venue.h"
#include "Address.h"
#include "Seat.h"
#include "Seat_Row.h"
#include "Seat_Section.h"

class Venue_From_Xml
{
public:
	static New_Venue* Get_Venue(TiXmlNode* venue_node);
	static Address* Get_Address(TiXmlNode* address_node);


private:
	void Get_Seat_Row(TiXmlNode* seat_row_node);
	void Get_Seats(TiXmlNode* seat_row_node);

	void Get_Seat(TiXmlNode* seat_node);
};

