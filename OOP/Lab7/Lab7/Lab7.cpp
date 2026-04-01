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
protected:
	TPoint Position;
	TPoint Target;
	int Condition;
	int MoveSpeed;
	int TactMoveSpeed;
	int AttackSpeed;
	int TactAttackSpeed;

public:
	GameUnit();
	GameUnit(TPoint inPos, TPoint inTar, int inCond, int inMS, int inAS);
	virtual ~GameUnit() {};
	virtual void Attack();
	virtual void Move();
	void PrintPosition();
};

GameUnit::GameUnit() {
	Condition = 0;
	MoveSpeed = 0;
	AttackSpeed = 0;
	TactMoveSpeed = 0;
	TactAttackSpeed = 0;

};

GameUnit::GameUnit(TPoint inPos, TPoint inTar, int inCond, int inMS, int inAS) {
	Position = inPos;
	Target = inTar;
	Condition = inCond;
	MoveSpeed = inMS;
	AttackSpeed = inAS;
	TactMoveSpeed = 5 - MoveSpeed;
	TactAttackSpeed = 5 - AttackSpeed;
};

void GameUnit::Attack() {
	if (Condition <= 0 || AttackSpeed == 0) return;

	TactAttackSpeed--;

	TactAttackSpeed++;
	if (TactAttackSpeed <= 0) {
		std::cout << "Unit attacks!\n";
		TactAttackSpeed = 5 - AttackSpeed;;
	};
}

void GameUnit::Move() {
	if (Condition <= 0 || MoveSpeed == 0) return;

	TactMoveSpeed--;

	if (TactMoveSpeed <= 0) {
		if (Position.getX() < Target.getX()) {
			Position.setX(Position.getX() + 1);
		}
		else if (Position.getX() > Target.getX()) {
			Position.setX(Position.getX() - 1);
		}

		if (Position.getY() < Target.getY()) {
			Position.setY(Position.getY() + 1);
		}
		else if (Position.getY() > Target.getY()) {
			Position.setY(Position.getY() - 1);
		}

		TactMoveSpeed = 5 - MoveSpeed;
	}
}

void GameUnit::PrintPosition() {
	std::cout << "Unit position: (" << Position.getX() << ", " << Position.getY() << ")\n";
}

class Knight: public GameUnit {
private:
	int Sword;
	int Armor;

public:
	Knight();
	Knight(TPoint inPos, TPoint inTar, int inCond, int inMS, int inAS, int inSword, int inArmor);
	void Attack() override;
};

Knight::Knight() {
	Sword = 0;
	Armor = 0;
};

Knight::Knight(TPoint inPos, TPoint inTar, int inCond, int inMS, int inAS, int inSword, int inArmor) {
	Position = inPos;
	Target = inTar;
	Condition = inCond;
	MoveSpeed = inMS;
	AttackSpeed = inAS;

	Sword = inSword;
	Armor = inArmor;
};

void Knight::Attack() {
	if (Condition <= 0 || AttackSpeed == 0 ) return;

	TactAttackSpeed--;
	if (TactAttackSpeed <= 0) {
		std::cout << "Knight swings sword (Damage: " << Sword << ")!\n";
		TactAttackSpeed = 5 - AttackSpeed;
	};
}

class Monster: public GameUnit {
private:
	int Nails;
	int Teeth;

public:
	Monster();
	Monster(TPoint inPos, TPoint inTar, int inCond, int inMS, int inAS, int inNails, int inTeeth);
	void Attack() override;
};

Monster::Monster() {
	Nails = 0;
	Teeth = 0;
};

Monster::Monster(TPoint inPos, TPoint inTar, int inCond, int inMS, int inAS, int inNails, int inTeeth){
	Position = inPos;
	Target = inTar;
	Condition = inCond;
	MoveSpeed = inMS;
	AttackSpeed = inAS;

	Nails = inNails;
	Teeth = inTeeth;
}

void Monster::Attack() {
	if (Condition <= 0 || AttackSpeed == 0) return;

	TactAttackSpeed--;
	if (TactAttackSpeed <= 0) {
		std::cout << "Monster bites with teeth (Damage: " << Teeth << ")!\n";
		TactAttackSpeed = 5 - AttackSpeed;
	};
}

class GameEngine {
private:
	GameUnit* array[100];
	int unitCount;

public:
	GameEngine();
	void addElement(GameUnit* unit);
	void Action();
};

GameEngine::GameEngine() {
	unitCount = 0;
}

void GameEngine::addElement(GameUnit* unit) {
	if (unitCount < 100) {
		array[unitCount] = unit;
		unitCount++;
	}
	else {
		std::cout << "GameEngine is full!\n";
	}
};

void GameEngine::Action() {
	std::cout << "--- Game Tick ---\n";
	for (int i = 0; i < unitCount; i++) {
		array[i]->Attack();
		array[i]->Move();
	}
};

int main()
{
	GameEngine engine;

	TPoint knightStart(0, 0), knightTarget(5, 5);
	Knight* k1 = new Knight(knightStart, knightTarget, 100, 3, 2, 8, 10);

	TPoint monsterStart(10, 10), monsterTarget(-1, -1);
	Monster* m1 = new Monster(monsterStart, monsterTarget, 100, 4, 4, 5, 7);

	engine.addElement(k1);
	engine.addElement(m1);

	for (int i = 0; i < 4; i++) {
		engine.Action();
	}

	delete k1;
	delete m1;

	return 0;
};