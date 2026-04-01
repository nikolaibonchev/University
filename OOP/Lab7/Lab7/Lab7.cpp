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
	int TactMoveSpeed;
	int AttackSpeed;
	int TactAttackSpeed;

public:
	GameUnit();
	GameUnit(TPoint* inPos, TPoint* inTar, int inCond, int inMS, int inAS);
	void Attack();
	void Move();
};

GameUnit::GameUnit() {
	Position = nullptr;
	Target = nullptr;
	Condition = 0;
	MoveSpeed = 0;
	AttackSpeed = 0;
	TactMoveSpeed = 0;
	TactAttackSpeed = 0;

};

GameUnit::GameUnit(TPoint* inPos, TPoint* inTar, int inCond, int inMS, int inAS) {
	int tarX = inTar->getX();
	int tarY = inTar->getY();

	if (tarX == -1) inTar->setX(0);
	if (tarY == -1) inTar->setY(0);

	Position = inPos;
	Target = inTar;
	Condition = inCond;
	MoveSpeed = inMS;
	AttackSpeed = inAS;
};

void GameUnit::Attack() {

}

void GameUnit::Move() {

}

class Knight: public GameUnit {
private:
	int Sword;
	int Armor;

public:
	Knight();
	Knight(int inSword, int inArmor);
};

Knight::Knight() {
	Sword = 0;
	Armor = 0;
};

Knight::Knight(int inSword, int inArmor) {
	Sword = inSword;
	Armor = inArmor;
};

class Monster: public GameUnit {
private:
	int Nails;
	int Teeth;

public:
	Monster();
	Monster(int inNails, int inTeeth);
};

Monster::Monster() {
	Nails = 0;
	Teeth = 0;
};

Monster::Monster(int inNails, int inTeeth) {
	Nails = inNails;
	Teeth = inTeeth;
}

class GameEngine {
private:
	GameUnit* array[100];

public:
	void addElement(GameUnit* unit);
	void Action(std::string type, GameUnit* unit);
};

void GameEngine::addElement(GameUnit* unit) {

};

void GameEngine::Action(std::string type, GameUnit* unit) {
	if (type == "attack") {
		unit->Attack();
	}
	else {
		unit->Move();
	}
};

int main()
{

};