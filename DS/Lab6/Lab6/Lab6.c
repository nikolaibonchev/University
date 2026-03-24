#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996);

typedef struct {
    int** m;
    unsigned n;
} matrix;

int find_max();
matrix* CreateMatrix(unsigned max);
void PrintMatrix(matrix* m, int r, int c);
void FillMatrix(matrix* m);
int edge_count();
matrix* CreateMatrix2(unsigned max, unsigned edges);
void FillMatrix2(matrix* m);

int main()
{
    unsigned max = find_max();
    printf("max: %d\n", max);

    matrix* m1 = CreateMatrix(max);
    PrintMatrix(m1, m1->n, m1->n);
    printf("\n");

    FillMatrix(m1);
    PrintMatrix(m1, m1->n, m1->n);
    printf("\n");
    printf("\nedge count: %d\n", edge_count());

    matrix* m2 = CreateMatrix2(find_max(), edge_count());
    printf("Matrix 1:\n");
    PrintMatrix(m2, find_max(), edge_count());
    printf("\n");

    FillMatrix2(m2);
    printf("Matrix 2:\n");
    PrintMatrix(m2, find_max(), edge_count());
    printf("\n");
}

int find_max() {
    // 1. Use standard fopen
    FILE* fp = fopen("textfile.txt", "r");

    // 2. Added a newline (\n) to your error message
    if (!fp) {
        printf("Could not open file in find_max\n");
        return 1;
    }

    unsigned max = 0;
    char c;
    char str[2] = "\0";
    do {
        c = fgetc(fp);
        if (feof(fp)) {
            break;
        }

        str[0] = c;

        if (atoi(str) > max) {
            max = atoi(str);
        }
    } while (1);

    // 3. YOU MUST CLOSE THE FILE!
    fclose(fp);

    return max;
}

matrix* CreateMatrix(unsigned max) {
    matrix* new_matrix = (matrix*)malloc(sizeof(matrix));
    new_matrix->n = max;
    new_matrix->m = (int**)malloc(new_matrix->n * sizeof(int*));
    int i;
    for (i = 0; i < new_matrix->n; i++) {
        new_matrix->m[i] = (int*)malloc(new_matrix->n * sizeof(int));
    }

    for (i = 0; i < new_matrix->n; i++) {
        int j;
        for (j = 0; j < new_matrix->n; j++) {
            new_matrix->m[i][j] = 0;
        }
    }
    return new_matrix;
}

void PrintMatrix(matrix* m, int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        printf("\n");
        for (j = 0; j < c; j++) {
            printf("%d", m->m[i][j]);
        }
    }
}

void FillMatrix(matrix* m) {
    int n1, n2, i;
    FILE* fp = fopen("textfile.txt", "r");

    // 1. Check if the file opened successfully
    if (fp == NULL) {
        printf("Error: Could not open textfile.txt\n");
        return;
    }

    for (i = 0; i < 10; i++) {
        // 2. Check if fscanf successfully read exactly 2 items
        if (fscanf(fp, "%d %d", &n1, &n2) == 2) {

            // 3. Ensure the indices are valid before accessing memory
            // (Assuming m->n is the dimension of the matrix)
            if (n1 > 0 && n1 <= m->n && n2 > 0 && n2 <= m->n) {
                m->m[n1 - 1][n2 - 1] = 1;
            }
            else {
                printf("Warning: Ignored out-of-bounds indices: %d, %d\n", n1, n2);
            }

        }
        else {
            // If fscanf didn't read 2 items, we probably hit the End of File
            break;
        }
    }

    fclose(fp);
}

int edge_count() {
    FILE* fp = fopen("textfile.txt", "r");
    char c;
    int count = 0;
    do {
        c = fgetc(fp);
        if (feof(fp)) {
            break;
        }

        if (c == '\n')count++;
    } while (1);

    return count + 1;
}

matrix* CreateMatrix2(unsigned max, unsigned edges) {
    matrix* m = (matrix*)malloc(sizeof(matrix));
    m->n = max;
    m->m = (int**)malloc(max * sizeof(int*));
    int i, j;
    for (i = 0; i < max; i++) {
        m->m[i] = (int*)malloc(edges * sizeof(int));
    }

    for (i = 0; i < max; i++) {
        for (j = 0; j < edges; j++) {
            m->m[i][j] = 0;
        }
    }

    return m;
}

void FillMatrix2(matrix* m) {
    int n1, n2, i;
    FILE* fp = fopen("textfile.txt", "r");
    for (i = 0; i < 10; i++) {
        fscanf(fp, "%d %d\n", &n1, &n2);
        m->m[n1 - 1][i] = 1;
        m->m[n2 - 1][i] = -1;
    }
}