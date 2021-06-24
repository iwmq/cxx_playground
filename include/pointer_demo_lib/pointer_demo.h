#ifndef POINTER_DEMO_
#define POINTER_DEMO_

typedef struct node
{
    int val;
    struct node *next;
} node;

// Utilities
node* make_list();
void print_nodes(node* head);

typedef _Bool (*rm_fn)(node const *p);

#endif // POINTER_DEMO_