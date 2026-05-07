#include <iostream>

class Participant {
private:
	char Name[12];
	char FamName[12];
	int TeamNo;
	bool InOutFLAG;

public:
	Participant();
	Participant(char* name, char* famname, int teamno, bool flag);
	~Participant();
	void printInfo();
	void flipFlag();
};

Participant::Participant() {
	TeamNo = 0;
	InOutFLAG = FALSE;
};

Participant::Participant(char* name, char* famname, int teamno, bool flag) {
	strcpy_s(Name, sizeof(Name), name);
	strcpy_s(FamName, sizeof(FamName), famname);
	TeamNo = teamno;
	InOutFLAG = flag;
};

Participant::~Participant() {};

class Team {
private:
	char TeamName[20];
	Participant* Participants;
	int ParticipantsCount;
	int PointsCount;
	bool WLFLAG;

public:
	Team();
	Team(char* teamname, int partcount, int pcount, bool flag, Participant participant);
	~Team();
	void printTeamInfo();
	char searchParticipant(char* name);
	void addPoints();
};

Team::~Team() {
	delete[] Participants;
};

class Tournament {
private:
	Team* Teams[16];
	int teamsCount;

public:
	Tournament();
	Tournament(int count, Team team);
	~Tournament();
	void addTeam(Team team);
	void playRound();
	void eliminateTeam();

};

Tournament::~Tournament() {
	delete[] Teams;
};

int main()
{

}
