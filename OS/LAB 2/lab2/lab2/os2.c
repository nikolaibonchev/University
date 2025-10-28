#include <windows.h>
#include <stdio.h>

struct threadinfo {
    int index;
    HANDLE h;
    DWORD tid;
};

threadinfo* thread_arr;

DWORD WINAPI thread_func(void* p) {
    threadinfo* p1 = (threadinfo*)p;
    printf("\nThread %d started", p1->index);
    for (int i = 0; i < 100000; i++); // dummy work
    printf("\nThread %d terminated", p1->index);
    return 0;
}

int main() {
    int n, m;
    printf("Enter number of threads: ");
    scanf("%d", &n);

    printf("Enter array size: ");
    scanf("%d", &m);

    int* arr = new int[m];
    for (int i = 0; i < m; i++)
        arr[i] = i;

    thread_arr = new threadinfo[n];

    for (int i = 0; i < n; i++) {
        thread_arr[i].index = i;
        thread_arr[i].h = CreateThread(
            NULL, 0, thread_func, &thread_arr[i],
            CREATE_SUSPENDED, &thread_arr[i].tid
        );
    }

    for (int i = 0; i < n; i++)
        ResumeThread(thread_arr[i].h);

    WaitForMultipleObjects(n,
        reinterpret_cast<HANDLE*>(thread_arr),
        TRUE, INFINITE);

    for (int i = 0; i < n; i++)
        CloseHandle(thread_arr[i].h);

    delete[] arr;
    delete[] thread_arr;

    printf("\nAll threads finished.\n");
    return 0;
}