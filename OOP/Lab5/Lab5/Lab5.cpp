#include <iostream>

class SuperLongInt {
    char Number[100];
    int Len = 0;
    char OverflowFlag;
    char NegativeFlag;

public:
    SuperLongInt();

    SuperLongInt(long int n);
    SuperLongInt(char s[]);
    SuperLongInt(double m);

    SuperLongInt(const SuperLongInt& other);

    char ToString();
    long int ToFinancial();
    
    SuperLongInt operator=(SuperLongInt& ob);
    SuperLongInt operator+(SuperLongInt& ob);
    SuperLongInt operator-(SuperLongInt& ob);
    std::ostream& operator>>(std::ostream& os, SuperLongInt& ob);
    ostream& operator<<(ostream& os, SuperLongInt& ob);
};

SuperLongInt::SuperLongInt() {
    for (int i = 0; i < 100; i++) {
        Number[i] = 0;
    };
};

int main()
{
    std::cout << "Hello World!\n";
}
