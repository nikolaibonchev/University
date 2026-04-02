#include<stdio.h>

// Дефиниране на стойност за "безкрайност", използвана за липса на път между възлите
#define INFINITY 9999
// Максимален брой върхове, които графът може да съдържа
#define MAX 50

// Прототип на функцията за алгоритъма на Дейкстра
void dijkstra(int G[MAX][MAX], int n, int startnode);

int main() {
    // Твърдо кодиран брой върхове (например 5)
    int n = 5;

    // Твърдо кодирана матрица на съседство
    // 0 означава липса на директен път между съответните върхове
    int G[MAX][MAX] = {
        {0, 10,  0,  0,  5},
        {0,  0,  1,  0,  2},
        {0,  0,  0,  4,  0},
        {7,  0,  6,  0,  0},
        {0,  3,  9,  2,  0}
    };

    // Твърдо кодиран начален възел (започваме от връх 0)
    int u = 0;

    printf("Graph: Shortest Path to Other Vertices: Dijkstra Algorithm >>\n\n");

    printf("Number of Vertices: %d\n", n);
    printf("Starting Node: %d\n", u);

    // Отпечатване на матрицата на съседство за преглед
    printf("\nThe Adjacency Matrix is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Форматиране с %2d за по-добро подравняване на колоните
            printf("%2d ", G[i][j]);
        }
        printf("\n");
    }

    // Извикване на функцията за пресмятане на най-кратките пътища
    dijkstra(G, n, u);

    return 0;
}

// Функция, реализираща алгоритъма на Дейкстра
void dijkstra(int G[MAX][MAX], int n, int startnode) {
    // cost - матрица на цените; distance - масив с най-кратките разстояния
    // pred - масив с предшествениците (за възстановяване на пътя)
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    // visited - масив, отбелязващ посетените възли
    int visited[MAX], count, mindistance, nextnode, i, j;

    // Създаване на матрицата на цените (cost matrix)
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            // Ако няма директен път (стойност 0), задаваме цената на БЕЗКРАЙНОСТ
            if (G[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];

    // Инициализиране на масивите distance, pred и visited спрямо началния възел
    for (i = 0; i < n; i++) {
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0; // 0 означава, че възелът не е посетен
    }

    // Разстоянието от началния възел до самия него е 0, а възелът се маркира като посетен
    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1; // Брояч на посетените възли

    // Главен цикъл на алгоритъма, който се изпълнява докато не посетим всички възли
    while (count < n - 1) {
        mindistance = INFINITY;

        // Намиране на възела с най-малко разстояние, който все още не е посетен
        for (i = 0; i < n; i++)
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }

        // Маркиране на намерения възел като посетен
        visited[nextnode] = 1;

        // Обновяване на разстоянията до съседните непосетени възли
        for (i = 0; i < n; i++)
            if (!visited[i])
                // Ако новият път през nextnode е по-кратък от досегашния, го обновяваме
                if (mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode; // Записваме nextnode като предшественик
                }
        count++;
    }

    // Отпечатване на резултатите за всеки възел (разстояние и самия път)
    for (i = 0; i < n; i++) {
        if (i != startnode) {
            // Проверка дали изобщо съществува път до този възел
            if (distance[i] == INFINITY) {
                printf("\nThere is no Possible Path Between %d and %d.", i, startnode);
            }
            else {
                // Извеждане на най-краткото разстояние
                printf("\nDistance of Node %d to %d is: %d", i, startnode, distance[i]);
                printf("\nAnd the Path (Destination <- Source) is: %d", i);

                // Възстановяване на пътя отзад напред чрез масива pred
                j = i;
                do {
                    j = pred[j];
                    printf(" <- %d", j);
                } while (j != startnode);
            }
        }
    }
    printf("\n");
}