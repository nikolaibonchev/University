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
    Participant(const char* name, const char* famname, int teamno, bool flag);
    ~Participant();
    void printInfo();
    void flipFlag();
    void saveToFile(std::ofstream& out);
    void loadFromFile(std::ifstream& in);
};

Participant::Participant() {
    TeamNo = 0;
    InOutFLAG = false;
}

Participant::Participant(const char* name, const char* famname, int teamno, bool flag) {
    strcpy_s(Name, sizeof(Name), name);
    strcpy_s(FamName, sizeof(FamName), famname);
    TeamNo = teamno;
    InOutFLAG = flag;
}

Participant::~Participant() {}

void Participant::printInfo() {
    std::cout << "Name: " << Name << "\n";
    std::cout << "Family Name: " << FamName << "\n";
    std::cout << "Team Number: " << TeamNo << "\n";
    std::cout << "Is playing: " << InOutFLAG << "\n";
}

void Participant::flipFlag() {
    InOutFLAG = !InOutFLAG;
}

void Participant::saveToFile(std::ofstream& out) {
    out << Name << " " << FamName << " " << TeamNo << " " << InOutFLAG << "\n";
}

void Participant::loadFromFile(std::ifstream& in) {
    in >> Name >> FamName >> TeamNo >> InOutFLAG;
}

class Team {
private:
    char TeamName[20];
    Participant* Participants;
    int ParticipantsCount;
    int PointsCount;
    bool WLFLAG;

public:
    Team();
    Team(const char* teamname, int partcount, int pcount, bool flag, Participant* players);
    ~Team();
    void printTeamInfo();
    Participant searchParticipant(const char* name, const char* fname);
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
}

Team::Team(const char* teamname, int partcount, int pcount, bool flag, Participant* players) {
    strcpy_s(TeamName, sizeof(TeamName), teamname);
    ParticipantsCount = partcount;
    PointsCount = pcount;
    WLFLAG = flag;

    Participants = new Participant[partcount];
    for (int i = 0; i < partcount; i++) {
        Participants[i] = players[i];
    }
}

Team::~Team() {
    delete[] Participants;
}

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
    std::cout << "Team Name: " << TeamName << "\n";
    std::cout << "Number of Participants: " << ParticipantsCount << "\n";
    std::cout << "Number of Points: " << PointsCount << "\n";
}

Participant Team::searchParticipant(const char* name, const char* fname) {
    for (int i = 0; i < ParticipantsCount; i++) {
        if (strcmp(Participants[i].Name, name) == 0 && strcmp(Participants[i].FamName, fname) == 0) {
            return Participants[i];
        }
    }
    std::cout << "Participant not found!\n";
    return Participant();
}

void Team::addPoints(int points) {
    PointsCount += points;
}

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
    Tournament(Team* teams);
    ~Tournament();
    void addTeam(Team team);
    void playRound();
    void eliminateTeam();
    void printTournamentStatus();

    void searchInfo(const char* name);
    void deleteInfo(const char* name);
};

Tournament::Tournament() {
    Teams = new Team[16];
    teamsCount = 0;
}

Tournament::Tournament(Team* teams) {
    Teams = new Team[16];
    for (int i = 0; i < teamsCount; i++) {
        Teams[i] = teams[i];
    }
}

void Tournament::addTeam(Team team) {
    if (teamsCount >= 16) {
        std::cout << "The Tournament is full!\n";
    }
    else {
        Teams[teamsCount] = team;
        teamsCount++;
    }
}

void Tournament::searchInfo(const char* name) {
    for (int i = 0; i < teamsCount; i++) {
        if (strcmp(Teams[i].getTeamName(), name) == 0) {
            std::cout << "\n--- Намерена информация ---\n";
            Teams[i].printTeamInfo();
            return;
        }
    }
    std::cout << "Отбор с име '" << name << "' не е намерен!\n";
}

void Tournament::deleteInfo(const char* name) {
    for (int i = 0; i < teamsCount; i++) {
        if (strcmp(Teams[i].getTeamName(), name) == 0) {
            for (int j = i; j < teamsCount - 1; j++) {
                Teams[j] = Teams[j + 1];
            }
            teamsCount--;
            std::cout << "Отборът '" << name << "' е изтрит успешно!\n";
            return;
        }
    }
    std::cout << "Отбор с име '" << name << "' не е намерен!\n";
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
}

void Tournament::printTournamentStatus() {
    if (teamsCount == 0) {
        std::cout << "Няма добавени отбори в турнира.\n";
        return;
    }
    std::cout << "\n=== Отбори в турнира (" << teamsCount << ") ===\n";
    for (int i = 0; i < teamsCount; i++) {
        std::cout << "- ";
        Teams[i].printTeamInfo();
        std::cout << "---------------------\n";
    }
}

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
}

int main()
{
    Tournament tour;
    int choice;

    do {
        std::cout << "\n========== MENU ==========\n";
        std::cout << "1. Add team\n";
        std::cout << "2. Search team\n";
        std::cout << "3. Delete team\n";
        std::cout << "4. Print all teams\n";
        std::cout << "5. Play a round\n";
        std::cout << "6. Exit\n";
        std::cout << "==========================\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        if (choice == 1) {
            char teamName[20];
            int partCount;
            std::cout << "Enter team name: ";
            std::cin >> teamName;
            std::cout << "Enter number of participants: ";
            std::cin >> partCount;

            Participant* tempPlayers = new Participant[partCount];
            for (int i = 0; i < partCount; i++) {
                char pName[12], pFamName[12];
                std::cout << "Participant's Name " << i + 1 << ": ";
                std::cin >> pName;
                std::cout << "Participant's Family Name " << i + 1 << ": ";
                std::cin >> pFamName;

                tempPlayers[i] = Participant(pName, pFamName, 1, true);
            }

            Team newTeam(teamName, partCount, 0, false, tempPlayers);
            tour.addTeam(newTeam);

            delete[] tempPlayers;

            std::cout << "Team added successfully!\n";
        }
        else if (choice == 2) {
            char searchName[20];
            std::cout << "Enter the name of searched team: ";
            std::cin >> searchName;
            tour.searchInfo(searchName);
        }
        else if (choice == 3) {
            char deleteName[20];
            std::cout << "Enter the name of the team for deletion: ";
            std::cin >> deleteName;
            tour.deleteInfo(deleteName);
        }
        else if (choice == 4) {
            tour.printTournamentStatus();
        }
        else if (choice == 5) {
            tour.playRound();
            tour.eliminateTeam();
        }
        else if (choice == 6) {
            std::cout << "Exiting from the program!\n";
        }
        else {
            std::cout << "Invalid chooice! Please try again!\n";
        }

    } while (choice != 6);

    return 0;
}