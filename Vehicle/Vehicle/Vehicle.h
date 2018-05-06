#pragma once

enum Colour
{
	red,
	blue,
	black,
	white,
	green,
	grey,
	yellow
};

class Vehicle
{
public:
	Vehicle();
	Vehicle(const Vehicle&);
	Vehicle& operator=(const Vehicle&);
	virtual ~Vehicle();
	Vehicle(Colour _colour, char* _manufactorer, unsigned short _year, unsigned short _seats, unsigned short _maxspeed);

	Colour getColour()const;
	void setColour(const Colour);

	char* getManufactorer()const;
	void setManufactorer(const char*);

	unsigned short getYear()const;
	void setYear(const unsigned short);

	unsigned short getSeats()const;
	void setSeats(const unsigned short);

	unsigned short getMaxSpeed()const;
	void setMaxSpeed(const unsigned short);

private:
	Colour colour;
	char* manufacturer;
	unsigned short year;
	unsigned short seats;
	unsigned short maxSpeed;

protected:
	void myStrCpy(char*&, const char*);
	void init();
	void copy(const Vehicle&);
	void destroy();
};