/*
 *
 *  Author: Vinay Hiremath
 *          vhiremath4@gmail.com
 *          www.vhmath.com
 *
 *  Description: Header file for a graph data structure.
 */

#ifndef GRAPH_T__
#define GRAPH_T__

// the graph data struct
typedef struct _graph_t {
    // the adjacency matrix
    int **matrix;

    // the number of vertices
    int numVertices;

    // the number of edges
    int numEdges;
} graph_t;

// Functionals.
void graph_add(graph_t *g, char* a, char *b, int weight);
void graph_delete(graph_t *g, char *a, char *b);
int graph_adjacent(graph_t *g, char *a, char *b);
char **graph_neighbors(graph_t *g, char *a);
int graph_get_edgeweight(grapht_t *g, char *a, char *b);
void graph_set_edgeweight(graph_t *g, char *a, char *b, int weight);

// Utility functions.
void graph_init(graph_t *g);
void graph_print(graph_t *g);
void graph_destroy(graph_t *g);

#endif
