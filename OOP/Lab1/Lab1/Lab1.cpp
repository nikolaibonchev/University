#include <stdio.h>
#include <string.h>

#define EOT -1;

struct BelRow {
	char Name[12];
	char Fam[15];
	unsigned long Tel;
};

class Bel {
	BelRow Table[100];
	int TableEnd;
	int CurrentRecord;
public:
	Bel(void);
	int Append(const char* Name, const char* Fam, unsigned long Tel);
	BelRow* FindRowByName(const char* Name);
	int First(void);
	int Next(void);
	int Prev(void);
	int Last(void);
	int Get(void);
};

Bel::Bel(void) {
	TableEnd = 0;
};

int Bel::Append(const char* Name, const char* Fam, unsigned long Tel) {
	if (TableEnd >= 100) return 0;
	strcpy(Table[TableEnd].Name, Name);
	strcpy(Table[TableEnd].Fam, Fam);
	Table[TableEnd].Tel = Tel;
	TableEnd++;
	return 1;
};

BelRow* Bel::FindRowByName(const char* Name) {
	for (int i = 0; i < TableEnd; i++)
		if (!strcmp(Table[i].Name, Name)) return &Table[i];
	return NULL;
};

int Bel::First(void) {
	CurrentRecord = 0;
};

int Bel::Next(void) {
	if (CurrentRecord > TableEnd) {
		return EOT;
	}
	else {
		CurrentRecord++;
	};
};

int Bel::Prev(void) {
	if (CurrentRecord == 0) {
		return EOT;
	}
	else
	{
		CurrentRecord--;
	};
};

int Bel::Last(void) {
	CurrentRecord == TableEnd;
}

int Bel::Get(void) {

}

void main(void) {
	Bel Tef;
	BelRow* Arow;
	Tef.Append("Ivan", "Petrov", 34123L);
	Tef.First();
	Tef.FindRowByName("Ivan");
	Tef.Next();

};