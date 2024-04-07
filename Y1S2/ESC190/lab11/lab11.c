#include <stdio.h>

void bfs(int n, int graph[n][n], int start) {
    int visited[n];
    int queue[n];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    visited[start] = 1;
    queue[rear] = start;
    rear++;

    while (front < rear) {
        int current = queue[front];
        front++;
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear] = i;
                rear++;
            }
        }
    }
}

void dfs(int n, int graph[n][n], int start, int visited[]) {
    int stack[n];
    int top = -1;

    top++;
    stack[top] = start;

    while (top >= 0) {
        int current = stack[top];
        top--;
        if (!visited[current]) {
            printf("%d ", current);
            visited[current] = 1;

            for (int i = 0; i < n; i++) {
                if (graph[current][i] && !visited[i]) {
                    top++;
                    stack[top] = i;
                }
            }
        }
    }
}

int main() {
    int n = 6;
    int adjacency_matrix[][6] = {
        {0, 0, 1, 0, 0, 1},
        {0, 0, 1, 0, 1, 0},
        {1, 1, 0, 1, 1, 0},
        {0, 0, 1, 0, 1, 0},
        {0, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 1, 0}
    };

    printf("BFS Traversal:\n");
    bfs(n, adjacency_matrix, 0);
    printf("\n");

    printf("DFS Traversal:\n");
    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    dfs(n, adjacency_matrix, 0, visited);

    return 0;
}
