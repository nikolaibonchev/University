#include <iostream>

class lekEd {
    char indentificator[10];
    char type[10];
    char descriptor[2];
    long address;

public:
    lekEd();
    lekEd(const char* id, const char* tp, int desc, long addr);
    ~lekEd();
    void print();
};

lekEd::lekEd() {
    sprintf(descriptor, "V%d", 0);
    address = 0;
};

lekEd::lekEd(const char* id, const char* tp, int desc, long addr) {
    strcpy_s(indentificator, sizeof(indentificator), id);
    strcpy_s(type, sizeof(type), tp);
    sprintf(descriptor, "V%d", desc);
    address = addr;
};

class descTable {
    lekEd Table;
    int lekEdCount;

public:
    descTable();
    descTable();
    int search(const char* id);
    void add(lekEd ed);
    void del(const char* id);
    void print();
};

int main()
{
    std::cout << "Hello World!\n";
}

