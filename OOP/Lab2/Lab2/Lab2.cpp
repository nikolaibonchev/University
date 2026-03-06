#include <iostream>
#include <cstring>


class BankAccount {

public:
    char IBAN[22];
    char type[7];
    float sum;
    void InitAcc(char* type, char* IBAN, float sum);
};

class ClientBank {
private:
    char Name[16];
    char Fam[16];
    int bankAccCount;
    int currentCount;
    int clientNum;
    static int AutoNumber;
    BankAccount* bankAccs;

public:
    ClientBank();
    ClientBank(char* _Name, char* _Fam, int _bankAccCount, int _clientNum);
    ~ClientBank();
    ClientBank(const ClientBank& other);
    void AddBankAcc();
    void RemoveBankAcc(char* IBAN);
    void FindBankAcc(char* IBAN);
    void AddSum(char* IBAN, float toAdd);
    float CombinedSum();
    void PrintInformation();
};

int ClientBank::AutoNumber = 0;

ClientBank::ClientBank() {
    bankAccCount = 0;
    currentCount = 0;
    bankAccs = nullptr;
}

ClientBank::ClientBank(char* _Name, char* _Fam, int _bankAccCount, int _clientNum) {
    strcpy_s(Name, sizeof(Name), _Name);
    strcpy_s(Fam, sizeof(Fam), _Fam);
    clientNum = _clientNum;
    bankAccCount = _bankAccCount;
    currentCount = 0;
    bankAccs = new BankAccount[bankAccCount];
};

ClientBank::ClientBank(const ClientBank& other) {
    strcpy_s(Name, sizeof(Name), other.Name);
    strcpy_s(Fam, sizeof(Fam), other.Fam);
    clientNum = other.clientNum;
    bankAccCount = other.bankAccCount;
    currentCount = other.currentCount;
    bankAccs = new BankAccount[bankAccCount];
    for (int i = 0; i < currentCount; i++) {
        bankAccs[i] = other.bankAccs[i];
    }
}

void BankAccount::InitAcc(char* _type, char* _IBAN, float _sum) {
    strcpy_s(type, sizeof(type), _type);
    strcpy_s(IBAN, sizeof(IBAN), _IBAN);
    sum = _sum;
};

void ClientBank::AddBankAcc() {
    char _type[7];
    char _IBAN[22];
    float _sum;

    if (currentCount < bankAccCount) {
        std::cout << "\nEnter Account No " << currentCount + 1 << " type: ";
        std::cin >> _type;

        std::cout << "Enter Account No " << currentCount + 1 << " IBAN: ";
        std::cin >> _IBAN;

        std::cout << "Enter Account No " << currentCount + 1 << " sum: ";
        std::cin >> _sum;

        bankAccs[currentCount].InitAcc(_type, _IBAN, _sum);
        currentCount++;
        std::cout << "\nThe Bank Account has been added" << std::endl;
    }
    else {
        std::cout << "Error! you got to the limit of possible amount of Bank Account" << std::endl;
    }
};

void ClientBank::RemoveBankAcc(char* _IBAN) {
    for (int i = 0; i < currentCount; i++) {
        if (strcmp(bankAccs[i].IBAN, _IBAN) == 0) {
            for (int j = i; j < currentCount - 1; j++) {
                bankAccs[j] = bankAccs[j + 1];
            }

            currentCount--;
            std::cout << "The Bank Account with IBAN " << _IBAN << " has been removed!" << std::endl;
            return;
        }
    }

    std::cout << "\nA Bank Account with " << _IBAN << " was not found" << std::endl;
};

void ClientBank::FindBankAcc(char* _IBAN) {
    for (int i = 0; i < currentCount; i++) {
        if (strcmp(bankAccs[i].IBAN, _IBAN) == 0) {
            std::cout << "\nThe Bank Account with IBAN: " << _IBAN << " was found";
            return;
        }

        std::cout << "\nBank Account with IBAN: " << _IBAN << " was not found";
    };
};

void ClientBank::AddSum(char* _IBAN, float toAdd) {
    for (int i = 0; i < currentCount; i++) {
        if (strcmp(bankAccs[i].IBAN, _IBAN) == 0) {
            bankAccs[i].sum += toAdd;
            std::cout << "\nThe " << toAdd << " were added to the account\n";
            return;
        }

        std::cout << "\nBank Account with IBAN: " << _IBAN << " was not found\n";
    };
}

float ClientBank::CombinedSum() {
    float amount = 0;

    for (int i = 0; i < currentCount; i++) {
        amount += bankAccs[i].sum;
    };

    return amount;
};

void ClientBank::PrintInformation() {
    std::cout << "\nName: " << Name << std::endl;
    std::cout << "Family Name: " << Fam << std::endl;
    std::cout << "Client Number: " << clientNum << std::endl;
    
    for (int i = 0; i < currentCount; i++) {
        std::cout << "\nAccount " << i + 1 << std::endl;
        std::cout << "  type: " << bankAccs[i].type << std::endl;
        std::cout << "  IBAN: " << bankAccs[i].IBAN << std::endl;
        std::cout << "  sum: " << bankAccs[i].sum << std::endl;
    }
};

ClientBank::~ClientBank() {
    delete[] bankAccs;
};

int main()
{
    char Name[16];
    char Fam[16];
    int bankAccCount;
    int clientNum;

    std::cout << "Enter a Name: ";
    std::cin >> Name;

    std::cout << "Enter a Family Name: ";
    std::cin >> Fam;

    std::cout << "Enter an amount of Bank Accounts: ";
    std::cin >> bankAccCount;

    std::cout << "Enter the client number: ";
    std::cin >> clientNum;

    ClientBank user(Name,Fam,bankAccCount,clientNum);

    for (int i = 0; i < bankAccCount; i++) {
        user.AddBankAcc();
    }
    //user.PrintInformation();

    //char iban[22] = "BG813573496840";
    //user.FindBankAcc(iban);
    //user.RemoveBankAcc(iban);
    //user.AddSum(iban, 500);

    ClientBank user2(user);

    user.PrintInformation();
    user2.PrintInformation();

    //float fullAmount = user.CombinedSum();
    //std::cout << "\n Your full amount of money of all accounts is: " << fullAmount;

    return 0;
}