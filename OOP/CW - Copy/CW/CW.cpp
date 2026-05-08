#include <iostream>

#include <cstring>

#include <fstream>


class Participant {

private:
    int TeamNo;
    bool InOutFLAG;

public:

    char Name[12];
    char FamName[12];
    Participant();
    Participant(char* name, char* famname, int teamno, bool flag);
    ~Participant();
    void printInfo();
    void flipFlag();
    void saveToFile(std::ofstream& out);
    void loadFromFile(std::ifstream& in);

};


Participant::Participant() {
    Name[0] = '\0';
    FamName[0] = '\0';
    TeamNo = 0;
    InOutFLAG = false;
};


Participant::Participant(char* name, char* famname, int teamno, bool flag) {
    strcpy_s(Name, sizeof(Name), name);
    strcpy_s(FamName, sizeof(FamName), famname);
    TeamNo = teamno;
    InOutFLAG = flag;
};

Participant::~Participant() {};

void Participant::printInfo() {
    std::cout << "Name: " << Name;
    std::cout << "Family Name: " << FamName;
    std::cout << "Team Number: " << TeamNo;
    std::cout << "Is playing: " << InOutFLAG;
};


void Participant::flipFlag() {

    if (InOutFLAG == true) {
        InOutFLAG = false;
    }

    else {
        InOutFLAG = true;
    }
};


void Participant::saveToFile(std::ofstream& out) {
    out << Name << " " << FamName << " " << TeamNo << " " << InOutFLAG << "\n";
};


void Participant::loadFromFile(std::ifstream& in) {
    in >> Name >> FamName >> TeamNo >> InOutFLAG;
};


class Team {
private:
    char TeamName[20];
    Participant* Participants;
    int ParticipantsCount;
    int PointsCount;
    bool WLFLAG;

public:
    Team();
    Team(char* teamname, int partcount, int pcount, bool flag, Participant* players);
    ~Team();
    void printTeamInfo();
    Participant searchParticipant(char* name, char* fname);
    void addPoints(int points);
    void saveParticipants(const char* filename);
    void loadParticipants(const char* filename);

    Team& operator=(const Team& other);
    void setWLFlag(bool flag) { WLFLAG = flag; }
    bool getWLFlag() { return WLFLAG; }
    const char* getTeamName() { return TeamName; }
};


Team::Team() {
    Participants = nullptr;
    ParticipantsCount = 0;
    PointsCount = 0;
    WLFLAG = false;
};


Team::Team(char* teamname, int partcount, int pcount, bool flag, Participant* players) {
    strcpy_s(TeamName, sizeof(TeamName), teamname);
    ParticipantsCount = partcount;
    PointsCount = pcount;
    WLFLAG = flag;
    Participants = new Participant[partcount];

    for (int i = 0; i < partcount; i++) {
        Participants[i] = players[i];
    }
};


Team::~Team() {
    delete[] Participants;
};

Team& Team::operator=(const Team& other) {
    if (this != &other) {
        strcpy_s(TeamName, sizeof(TeamName), other.TeamName);
        ParticipantsCount = other.ParticipantsCount;
        PointsCount = other.PointsCount;
        WLFLAG = other.WLFLAG;

        delete[] Participants;

        if (other.ParticipantsCount > 0 && other.Participants != nullptr) {
            Participants = new Participant[other.ParticipantsCount];
            for (int i = 0; i < other.ParticipantsCount; i++) {
                Participants[i] = other.Participants[i];
            }
        }
        else {
            Participants = nullptr;
        }
    }
    return *this;
}

void Team::printTeamInfo() {
    std::cout << "Team Name: " << TeamName;
    std::cout << "Number of Participants: " << ParticipantsCount;
    std::cout << "Number of Points: " << PointsCount;
};


Participant Team::searchParticipant(char* name, char* fname) {
    for (int i = 0; i < ParticipantsCount; i++) {
        if (strcmp(Participants[i].Name, name) == 0 && strcmp(Participants[i].FamName, fname) == 0) {
            return Participants[i];
        }
    }

    std::cout << "Participant not found!\n";
    return Participant();
};


void Team::addPoints(int points) {
    PointsCount += points;
};


void Team::saveParticipants(const char* filename) {
    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        std::cout << "Error: Cannot open file for writing!\n";
        return;
    }

    outFile << ParticipantsCount << "\n";

    for (int i = 0; i < ParticipantsCount; i++) {
        Participants[i].saveToFile(outFile);
    }

    outFile.close();
    std::cout << "Participants successfully saved to " << filename << "\n";
}


void Team::loadParticipants(const char* filename) {
    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        std::cout << "Error: Cannot open file for reading!\n";
        return;
    }

    delete[] Participants;
    inFile >> ParticipantsCount;
    Participants = new Participant[ParticipantsCount];

    for (int i = 0; i < ParticipantsCount; i++) {
        Participants[i].loadFromFile(inFile);
    }

    inFile.close();
    std::cout << "Participants successfully loaded from " << filename << "\n";
}


class Tournament {
private:
    Team* Teams;
    int teamsCount;

public:
    Tournament();
    Tournament(Team* teams, int count);
    ~Tournament();
    void addTeam(const Team& team);
    void playRound();
    void eliminateTeam();
    void printTournamentStatus();
};


Tournament::Tournament() {
    Teams = new Team[16];
    teamsCount = 0;
};


Tournament::Tournament(Team* teams, int count) {
    Teams = new Team[16];
    teamsCount = count;
    for (int i = 0; i < teamsCount; i++) {
        Teams[i] = teams[i];
    }
}


void Tournament::addTeam(const Team& team) {
    if (teamsCount == 16) {
        std::cout << "The Tournament is full";
    }
    else {
        Teams[teamsCount] = team;
        teamsCount++;
    }
}


void Tournament::eliminateTeam() {
    int survivingTeamsCount = 0;

    for (int i = 0; i < teamsCount; i++) {
        if (Teams[i].getWLFlag() == true) {
            if (survivingTeamsCount != i) {
                Teams[survivingTeamsCount] = Teams[i];
            }
            survivingTeamsCount++;
        }
    }

    std::cout << "\nEliminated " << teamsCount - survivingTeamsCount << " teams.\n";
    teamsCount = survivingTeamsCount;
};


void Tournament::printTournamentStatus() {
    std::cout << "Teams currently in tournament: " << teamsCount << "\n";

    for (int i = 0; i < teamsCount; i++) {
        std::cout << "- " << Teams[i].getTeamName() << "\n";
    }
};


void Tournament::playRound() {
    if (teamsCount < 2) {
        std::cout << "Not enough teams to play a round!\n";
        return;
    }

    std::cout << "\n=== Starting new round with " << teamsCount << " teams ===\n";

    for (int i = 0; i < teamsCount - 1; i += 2) {
        std::cout << "\nMatch: " << Teams[i].getTeamName() << " [1] vs "
            << Teams[i + 1].getTeamName() << " [2]\n";

        int choice = 0;
        while (choice != 1 && choice != 2) {
            std::cout << "Who won? (Enter 1 or 2): ";
            std::cin >> choice;
        }

        int winnerIndex, loserIndex;
        if (choice == 1) {
            winnerIndex = i;
            loserIndex = i + 1;
        }
        else {
            winnerIndex = i + 1;
            loserIndex = i;
        }

        Teams[winnerIndex].setWLFlag(true);
        Teams[loserIndex].setWLFlag(false);
        Teams[winnerIndex].addPoints(3);

        std::cout << "-> Winner recorded: " << Teams[winnerIndex].getTeamName() << "!\n";
    }
}


Tournament::~Tournament() {
    delete[] Teams;
};


int main()
{
    Tournament tour;

    Participant dummyPlayers[1];
    char name1[] = "Lions";
    char name2[] = "Tigers";
    char name3[] = "Bears";
    char name4[] = "Wolves";
    char name5[] = "Pegions";
    char name6[] = "Giraffes";
    char name7[] = "Snakes";
    char name8[] = "Foxes";
    char name9[] = "Leopards";
    char name10[] = "Pirates";
    char name11[] = "Turtles";
    char name12[] = "Reptiles";
    char name13[] = "Eagles";
    char name14[] = "Dogs";
    char name15[] = "Mammoths";
    char name16[] = "Fishes";

    std::cout << "--- Adding teams ---\n";
    tour.addTeam(Team(name1, 1, 0, false, dummyPlayers));
    tour.addTeam(Team(name2, 1, 0, false, dummyPlayers));
    tour.addTeam(Team(name3, 1, 0, false, dummyPlayers));
    tour.addTeam(Team(name4, 1, 0, false, dummyPlayers));
    tour.addTeam(Team(name5, 1, 0, false, dummyPlayers));
    tour.addTeam(Team(name6, 1, 0, false, dummyPlayers));
    tour.addTeam(Team(name7, 1, 0, false, dummyPlayers));
    tour.addTeam(Team(name8, 1, 0, false, dummyPlayers));
    tour.addTeam(Team(name9, 1, 0, false, dummyPlayers));
    tour.addTeam(Team(name10, 1, 0, false, dummyPlayers));
    tour.addTeam(Team(name11, 1, 0, false, dummyPlayers));
    tour.addTeam(Team(name12, 1, 0, false, dummyPlayers));
    tour.addTeam(Team(name13, 1, 0, false, dummyPlayers));
    tour.addTeam(Team(name14, 1, 0, false, dummyPlayers));
    tour.addTeam(Team(name15, 1, 0, false, dummyPlayers));
    tour.addTeam(Team(name16, 1, 0, false, dummyPlayers));

    tour.printTournamentStatus();
    tour.playRound();

    tour.eliminateTeam();

    std::cout << "\n--- After eliminations ---\n";
    tour.printTournamentStatus();

    return 0;
}