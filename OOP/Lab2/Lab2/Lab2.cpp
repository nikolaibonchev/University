#include <iostream>

class BankAccount {
    char type[7];
    char IBAN[22];
    float sum;
};

class ClientBank {
    char Name[16];
    char Fam[16];
    int bankAccCount;
    int clientNum;
    static int AutoNumber;

public:
    void Init(char* Name, char* Fam, int bankAccCount, int clientNum);
    void AddBankAcc(char* type, char* IBAN, float sum, char accName);
    void RemoveBankAcc(char* IBAN);
    int FindBankAcc(char* IBAN);
    void AddSum(float toAdd);
    int CombinedSum();
    void PrintInformation();
};

void ClientBank::Init(char* Name, char* Fam, int bankAccCount, int clientNum) {
    Name = Name;
    Fam = Fam;
    bankAccCount = bankAccCount;
    clientNum = clientNum;
}

void ClientBank::AddBankAcc(char* type, char* IBAN, float sum, char* accName) {
    BankAccount 
}

int main()
{
    //ClientBank.Init("Georgi", "Ivanov")
    std::cout << "Hello World!\n";
}