#include<stdio.h>
#include<stdlib.h>

//BST structure

struct node {
    
    int key;
    struct node *left;
    struct node *right;
    struct node *parent;
};

typedef struct node node;

//function prototypes
void insert_node(node *root, node *new_node);
void traverse_inorder(node *root);
void padding(char ch, int n);
void displayTree(node *root, int depth);
void dump(node *tree, int level);
node* create_node(int key);

int main(int argc, const char *argv[])
{
    node *root;

    //creating nodes;
    root = create_node(21);

    insert_node(root,create_node(13));
    insert_node(root,create_node(35));
    insert_node(root,create_node(25));
    insert_node(root,create_node(10));

    //traverse_inorder(root);
    displayTree(root,0);
    //free_inorder(root);
    return 0;
}


node* create_node(int key) {
    node *temp_node;
    temp_node = (node *) malloc(sizeof(node ));

    //initialization with values
    temp_node->key = key;
    temp_node->left = NULL;
    temp_node->right = NULL;
    temp_node->parent = NULL;
    
    return temp_node;
}

void insert_node(node *root, node *new_node){
    node *y = NULL, *x = root;
    while( x != NULL) {
        y = x;
        if (new_node->key < x->key) 
            x = x->left;
        else
            x = x->right;
    }

    new_node->parent = y;
    if(y == NULL)
        root = new_node; //z is made root if tree is empty
    else if( new_node->key < y->key)
        y->left = new_node;
    else
        y->right = new_node;
}

void traverse_inorder(node *root){
    if(root != NULL) {
        traverse_inorder(root->left);
        printf("\n %d ",root->key);
        traverse_inorder(root->right);
    }
}

void free_inorder(node *root){
    if(root != NULL) {
        free_inorder(root->left);
        printf("\n %d ",root->key);
        free_inorder(root->right);
    }
}

void padding(char ch, int n)
{
    	int i=0;
	for (i = 0; i < n; i++)
        	printf("%c%c%c%c", ch, ch, ch, ch);
}

void displayTree(node *root, int depth)
{
    if (root == NULL) {
        padding (' ', depth);
        printf("-\n");
    }
    else {
        displayTree(root->right, depth+1);
        padding(' ', depth);
        printf ( "%d\n", root->key);
        displayTree(root->left, depth+1);
    }
}

