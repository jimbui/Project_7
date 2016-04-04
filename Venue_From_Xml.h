#pragma once
#include "tinyxml.h"

static class Venue_From_Xml			//NEVER INSTANTIATE STATIC class
{
public:
	static void Get_Venue(TiXmlNode* venue_node);
	
private:
	static void Get_Address(TiXmlNode* address_node);
	
	static void Get_Seat_Row(TiXmlNode* seat_row_node);
	static void Get_Seats(TiXmlNode* seat_row_node);

	static void Get_Seat(TiXmlNode* seat_node);
};

