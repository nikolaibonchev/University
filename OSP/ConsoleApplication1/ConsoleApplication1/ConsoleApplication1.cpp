#include <stdlib.h>
#include <stdio.h>
const int M = 16;
int r[16][16] =
{    //0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
     { 0, 1, 0, 1, -500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, //0
     { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, //1
     { 0, 1, 0, 0, 0, 0, 0, 0, 0, -500, 1, 0, 0, 0, 0, 0,}, //2
     { 1, 0, 0, 0, -500, 1, -500, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, //3
     { 1, 0, 0, 1, 0, 1, -500, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, //4
     { 0, 0, 0, 1, -500, 0, -500, 1, 0, 0, 0, 0, 0, 0, 0, 0,}, //5
     { 0, 0, 0, 1, -500, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,}, //6
     { 0, 0, 0, 0, 0, 1, -500, 0, 1, 0, 0, 0, 0, 0, 0, 0,}, //7
     { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 200,}, //8
     { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, -500, 1, 0, 0, 0,}, //9
     { 0, 0, 1, 0, 0, 0, 0, 0, 0, -500, 0, -500, 1, 0, 0, 0,}, //10
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, -500, 1, 0, 1, 1, 0, 0,}, //11
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, -500, 1, -500, 0, 1, 0, 0,}, //12
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0,}, //13
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 200,}, //14
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 200,}, //15
};

int q[16][16] =
{
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
};
int find_naslednitzi(int naslednitsi[], int randoms)
{
    int i, n = 0;
    for (i = 0; i < M; i++)
        naslednitsi[i] = 0;

    for (i = 0; i < M; i++)
        if (r[randoms][i] != 0)
        {
            naslednitsi[n] = i;
            n++;
        }
    return n;
}

void show_path()
{
    int state;
    int goal = M - 1;
    int naslednitsi[M];
    int broy_naslednitsi, i, next_state, max_q;
    int steps = 0;

    printf("\nVavedete nachalno sastoyanie (0 - %d): ", M - 1);
    scanf_s("%d", &state);

    if (state < 0 || state >= M)
    {
        printf("Nevalidno sastoyanie!\n");
        return;
    }

    printf("Optimalen pat: %d", state);

    while (state != goal && steps < M)
    {
        broy_naslednitsi = find_naslednitzi(naslednitsi, state);
        if (broy_naslednitsi == 0)
        {
            printf(" -> (nyama izhod)");
            break;
        }

        next_state = naslednitsi[0];
        max_q = q[state][next_state];

        for (i = 1; i < broy_naslednitsi; i++)
        {
            int candidate = naslednitsi[i];
            if (q[state][candidate] > max_q)
            {
                max_q = q[state][candidate];
                next_state = candidate;
            }
        }

        state = next_state;
        printf(" -> %d", state);
        steps++;
    }
    printf("\n");
}

int main()
{

    int naslednitsi[M];

    int broy_naslednitsi, biggest, i, randoms = 0, state, action;
    for (i = 0; i < 600; i++)
    {
        action = 0; state = rand() % M;

        broy_naslednitsi = find_naslednitzi(naslednitsi, state);
        while (action != M - 1)
        {
            randoms = rand() % broy_naslednitsi;
            action = naslednitsi[randoms];
            broy_naslednitsi = find_naslednitzi(naslednitsi, action);
            int i, j;
            biggest = q[action][naslednitsi[0]];
            for (i = 0; i < broy_naslednitsi; i++)
            {
                j = naslednitsi[i];
                if (biggest < q[action][j])
                    biggest = q[action][j];
            }

            q[state][action] = r[state][action] + (0.8 * biggest);
            state = action;
            broy_naslednitsi = find_naslednitzi(naslednitsi, state);
        }

    }

    printf("q={\n{");
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
            printf("%d, ", q[i][j]);
        printf("},\n{");
    }

    show_path();

    return 0;
}