#include <iostream>

class Unit {
	char Address[100];
	char Owner[30];
	float Price;
	double Area;

public:

	Unit();
	Unit(char* inAddress, char* inOwner, float inPrice, double inArea);
	~Unit();
	virtual void printInfo();
};

Unit::Unit() {
	Price = 0;
	Area = 0;
};

Unit::Unit(char* inAddress, char* inOwner, float inPrice, double inArea) {
	strcpy_s(Address, sizeof(Address), inAddress);
	strcpy_s(Owner, sizeof(Owner), inOwner);
	Price = inPrice;
	Area = inArea;
}

Unit::~Unit(){
	delete Address;
	delete Owner;
};

void Unit::printInfo() {
	printf("The Address is: ", Address);
	printf("The Owner is: ", Owner);
	printf("The Price is: ", Price);
	printf("The Area is: ", Area);
}

class Apartment : public Unit {
	int RoomCount;
	int Floor;

public:
	Apartment();
	Apartment(int inRoomCount, int inFloor);
	~Apartment();

	void printInfo();
};

Apartment::Apartment() {
	RoomCount = 0;
	Floor = 0;
};

Apartment::Apartment(int inRoomCount, int inFloor) {
	RoomCount = inRoomCount;
	Floor = inFloor;
};

Apartment::~Apartment() {};

void Apartment::printInfo() {
	printf("The count of rooms is: ", RoomCount);
	printf("The floor of the Apartment is: ", Floor);

}

class Agency {
	char Name[20];
	int unitCount;
	Unit* units[20];

public:
	Agency();
	Agency(char* inName, int inUnitCount);
	~Agency();

	void addUnit(Unit* unit, char* type);
	void removeUnit();
	int searchByPrice(float hPrice, float lPrice);
};

Agency::Agency() {
	unitCount = 0;
}

Agency::Agency(char* inName, int inUnitCount) {
	strcpy_s(Name, sizeof(Name), inName);
	unitCount = inUnitCount;
}

void Agency::addUnit(Unit* unit, char* type, ) {
	if (strcmp(type, "Apartment") == 0) {
		Apartment app = new Apartment()
	}
	else if (strcmp(type, "House") == 0)
	{

	}
};

void Agency::removeUnit() {

}

Agency::~Agency() {
	delete units;
}

int main()
{
}