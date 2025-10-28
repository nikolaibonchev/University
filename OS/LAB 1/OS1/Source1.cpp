#include <windows.h>
#include <stdio.h>

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

void main(int n)
{
	int i;
	thread_arr = new threadinfo[n];
	for (i = 0; i < n; i++)
	{
		thread_arr[i].index = i;
		thread_arr[i].h = CreateThread(NULL, 0, thread_func, &thread_arr[i], 0, &thread_arr[i].tid);
	}

	for (i = 0; i < n; i++)
	{
		ResumeThread(thread_arr[i].h);
	}
};