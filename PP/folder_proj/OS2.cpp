#include <windows.h>
#include <stdio.h>
#include <iostream>
using namespace std;

struct threadinfo
{
	int index; // индекс на нишката по реда на създаване
	HANDLE h; // handle (манипулатор) на нишката
	DWORD tid; // tid на нишката
};

threadinfo* thread_arr;

DWORD WINAPI thread_func(void* p)
{
	threadinfo* p1 = (threadinfo*)p;
	printf("\nthread % d started", p1->index); // извеждане на съобщение “thread nnnn started”, където
	// nnnn е index на нишката
	for (int i = 0; i < 100000; i++); // код на функцията (празен цикъл)
	printf("\nthread % d terminated", p1->index); // извеждане на съобщение “thread nnnn terminated”,
	// където nnnn е index на нишката
	return 0;
};

void main(int n, int m)
{
	int i, res;

	printf("\nEnter number of threads: ");
	scanf_s("%d", &n);

	printf("\nEnter array size: ");
	scanf_s("%d", &m);

	cin >> m;
	int* arr = new int[m];

	for (i = 0; i <= m; i++) {
		arr[i] = i;
	}

	res = m / n;

	thread_arr = new threadinfo[res];

	for (i = 0; i < n; i++)
	{
		thread_arr[i].index = i;
		thread_arr[i].h = CreateThread(NULL, 0, thread_func, &thread_arr[i], CREATE_SUSPENDED, &thread_arr[i].tid);
	}

	for (i = 0; i < n; i++)
	{
		ResumeThread(thread_arr[i].h);
	}
};