#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct GraphNode {
    char *name;
    char **neighbours;
    struct GraphNode *next;
} GraphNode;

typedef struct Graph {
    int size;
    struct GraphNode *head;
} Graph;

void add_graph_node(Graph *graph, char *name, char **neighbours) {
    GraphNode *new_node = (GraphNode *)malloc(sizeof(GraphNode));
    new_node->name = (char *)malloc(strlen(name) + 1);
    strcpy(new_node->name, name);
    new_node->neighbours = neighbours;
    new_node->next = NULL;

    if (graph->head == NULL) {
        graph->head = new_node;
    } else {
        GraphNode *current = graph->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    graph->size++;
}

GraphNode *node_from_string(Graph *graph, char *string) {
    GraphNode *current = graph->head;
    while (current != NULL) {
        if (strcmp(current->name, string) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void adjacency_matrix(Graph *graph, char **name) {
    int matrix[graph->size][graph->size];
    for (int i = 0; i < graph->size; i++) {
        for (int j = 0; j < graph->size; j++) {
            if (i == j) {
                matrix[i][j] = 0;
            } else {
                GraphNode *node_i = node_from_string(graph, name[i]);
                GraphNode *node_j = node_from_string(graph, name[j]);
                int connected = 0;
                for (int k = 0; node_i->neighbours[k] != NULL; k++) {
                    if (strcmp(node_i->neighbours[k], node_j->name) == 0) {
                        connected = 1;
                        break;
                    }
                }
                matrix[i][j] = connected;
            }
        }
    }

    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->size; i++) {
        printf("%s | ", name[i]);
    }
    printf("\n");
    for (int i = 0; i < graph->size; i++) {
        printf("%s | ", name[i]);
        for (int j = 0; j < graph->size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->head = NULL;
    graph->size = 0;

    char *name1 = "name 1";
    char *name2 = "name 2";
    char *name3 = "name 3";
    char *name4 = "name 4";
    char *names[] = {name1, name2, name3, name4};

    char *neighbours1[] = {name2, name3, NULL};
    char *neighbours2[] = {name1, name3, name4, NULL};
    char *neighbours3[] = {name1, name2, NULL};
    char *neighbours4[] = {name2, NULL};

    add_graph_node(graph, name1, neighbours1);
    add_graph_node(graph, name2, neighbours2);
    add_graph_node(graph, name3, neighbours3);
    add_graph_node(graph, name4, neighbours4);

    adjacency_matrix(graph, names);

    return 0;
}
