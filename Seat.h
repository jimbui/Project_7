#pragma once
#include <string>
using namespace std;

class Seat
{
private:
	string seat_row_name;
	string seat_section_name;
	int seat_number;

public:
	Seat(string Row_Name, int Seat_Number, string Seat_Section_Name);

	//void Sell();
	void Display() const;
};

