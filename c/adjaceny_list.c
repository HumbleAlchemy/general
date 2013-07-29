#include<stdio.h>
#include<stdlib.h>

struct node {
    int key;
    struct node *next;
};

typedef struct node node;

typedef struct {
    node *head;
} node_list;

typedef struct {
    int v_num;
    node_list *array;
} graph;

/* graph function to create node */
node* create_node(int key) {
    node *new_node = malloc(sizeof(node));
    new_node->key = key;
    new_node->next = NULL;
    return new_node;
}

/* graph function to create graphs */
graph* create_graph(int v_num) {
    int i=0;
    graph* new_graph = malloc(sizeof(graph));
    new_graph->v_num = v_num;
    
    new_graph->array = malloc(v_num*sizeof(node_list));
    
    for( i = 0 ; i < v_num ; i++ )
    {
        new_graph->array[i].head = NULL;
    }
    
    return new_graph;
}

void add_edge(graph *g , int src, int dest) {
    
    node *new_node = create_node(dest);
    new_node->next = g->array[src].head;
    g->array[src].head = new_node;

    //for undirected graph
    new_node = create_node(src);
    new_node->next = g->array[dest].head;
    g->array[src].head = new_node->next;
}

void print_graph(graph *g) {
    int v;
    for( v = 0 ; v < g->v_num ; ++v )
    {
        node *crawler = g->array[v].head;
        printf("\n vertex: %d\n head ",v);
        while(crawler != NULL) {
            printf("-> %d", crawler->key);
            crawler = crawler->next;
        }
        printf("\n");
    }
    
}


int main(int argc, char *argv[])
{
    /* creating graph */
    graph* g = create_graph(5);
    add_edge(g, 0, 1);
    add_edge(g, 0, 4);
    add_edge(g, 1, 2);
    add_edge(g, 1, 4);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);

    print_graph(g);
    printf("%d",g->array[0].head->next->key);
    return 0;

}


