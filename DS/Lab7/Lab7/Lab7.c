#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned** m;
    unsigned n;
} matrix;

matrix adj_mat;
int** inc_mat;
unsigned num_nodes;
unsigned num_edges;
FILE* f;
unsigned u, v;
unsigned i, j;
unsigned edge_idx;
unsigned max_val;
unsigned count;

unsigned getMaxNode() {
    max_val = 0;
    f = fopen("graph.txt", "r");
    if (!f) return 0;
    while (fscanf(f, "%u %u", &u, &v) == 2) {
        if (u > max_val) max_val = u;
        if (v > max_val) max_val = v;
    }
    fclose(f);
    return max_val;
}

void allocAdjacency() {
    adj_mat.n = num_nodes;
    adj_mat.m = (unsigned**)malloc(num_nodes * sizeof(unsigned*));
    for (i = 0; i < num_nodes; i++) {
        adj_mat.m[i] = (unsigned*)calloc(num_nodes, sizeof(unsigned));
    }
}

void populateAdjacency() {
    f = fopen("graph.txt", "r");
    if (!f) return;
    while (fscanf(f, "%u %u", &u, &v) == 2) {
        adj_mat.m[u - 1][v - 1] = 1;
    }
    fclose(f);
}

unsigned getEdgeCount() {
    count = 0;
    f = fopen("graph.txt", "r");
    if (!f) return 0;
    while (fscanf(f, "%u %u", &u, &v) == 2) {
        count++;
    }
    fclose(f);
    return count;
}

void allocIncidence() {
    inc_mat = (int**)malloc(num_nodes * sizeof(int*));
    for (i = 0; i < num_nodes; i++) {
        inc_mat[i] = (int*)calloc(num_edges, sizeof(int));
    }
}

void populateIncidence() {
    f = fopen("graph.txt", "r");
    if (!f) return;
    edge_idx = 0;
    while (fscanf(f, "%u %u", &u, &v) == 2) {
        inc_mat[u - 1][edge_idx] = 1;
        inc_mat[v - 1][edge_idx] = -1;
        edge_idx++;
    }
    fclose(f);
}

int main() {
    num_nodes = getMaxNode();
    if (num_nodes == 0) {
        printf("Error reading graph.txt\n");
        return 1;
    }

    allocAdjacency();
    populateAdjacency();

    num_edges = getEdgeCount();
    allocIncidence();
    populateIncidence();

    printf("Matrica na sasedstvo:\n");
    for (i = 0; i < num_nodes; i++) {
        for (j = 0; j < num_nodes; j++) {
            printf("%u ", adj_mat.m[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrica na incidentnost:\n");
    for (i = 0; i < num_nodes; i++) {
        for (j = 0; j < num_edges; j++) {
            printf("%3d ", inc_mat[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < num_nodes; i++) {
        free(adj_mat.m[i]);
        free(inc_mat[i]);
    }
    free(adj_mat.m);
    free(inc_mat);

    return 0;
}