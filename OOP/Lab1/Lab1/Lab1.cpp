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
	BelRow* Get(void);
};

Bel::Bel(void) {
	TableEnd = 0;
	CurrentRecord = 0;
};

int Bel::Append(const char* Name, const char* Fam, unsigned long Tel) {
	if (TableEnd >= 100) return 0;
	strcpy_s(Table[TableEnd].Name, Name);
	strcpy_s(Table[TableEnd].Fam, Fam);
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
	return CurrentRecord = 0;
};

int Bel::Next(void) {
	if (CurrentRecord >= TableEnd - 1) return EOT;
	return ++CurrentRecord;
};

int Bel::Prev(void) {
	if (CurrentRecord == 0) {
		return EOT;
	}
	else
	{
		return CurrentRecord--;
	};
};

int Bel::Last(void) {
	if (TableEnd == 0) return EOT;
	CurrentRecord = TableEnd - 1;
	return CurrentRecord;
}

BelRow* Bel::Get(void) {
	if (TableEnd == 0) {
		return NULL;
	}
	else
	{
		return &Table[CurrentRecord];
	}
}

void main(void) {
	Bel Tef;
	BelRow* Arow;

	Tef.Append("Ivan", "Petrov", 34123L);
	Tef.Append("Maria", "Ivanova", 55512L);
	Tef.Append("Georgi", "Todorov", 98765L);

	printf("Content of Table:\n");

	Tef.First();

	for (int i = 0; i < 100; i++) {
		Arow = Tef.Get();

		if (Arow == NULL) break;

		printf("Name: %-12s | Fam: %-15s | Tel: %lu\n",
			Arow->Name, Arow->Fam, Arow->Tel);

		if (Tef.Next() == -1) break;
	}
};