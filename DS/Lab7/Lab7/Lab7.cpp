#include <iostream>

class TPoint {
private:
	int x;
	int y;

public:
	TPoint();
	TPoint(int ix, int iy);
	int getX();
	int getY();
	void setX(int ix);
	void setY(int iy);
};

TPoint::TPoint() {
	x = 0;
	y = 0;
};

TPoint::TPoint(int ix, int iy) {
	x = ix;
	y = iy;
};

int TPoint::getX() {
	return x;
};

int TPoint::getY() {
	return y;
};

void TPoint::setX(int ix) {
	x = ix;
};

void TPoint::setY(int iy) {
	y = iy;
};

class GameUnit {
private:
	TPoint* Position;
	TPoint* Target;
	int Condition;
	int MoveSpeed;
	int AttackSpeed;

public:
	GameUnit();
	GameUnit(TPoint* inPos, TPoint* inTar, int inCond, int inMS, int inAS);
	~GameUnit();
};

GameUnit::GameUnit() {
	Position = nullptr;
	Target = nullptr;
	Condition = 0;
	MoveSpeed = 0;
	AttackSpeed = 0;
};

GameUnit::GameUnit(TPoint* inPos, TPoint* inTar, int inCond, int inMS, int inAS) {
	Position = inPos;
	Target = inTar;
	Condition = inCond;
	MoveSpeed = inMS;
	AttackSpeed = inAS;
}

class Knight: public GameUnit {
private:
	int Sword;
	int Armor;

public:
};

class Monster: public GameUnit {
private:
	int Nails;
	int Teeth;

public:
};

class GameEngine {
private:
	GameUnit* array[100];

public:

};

int main()
{
   
}