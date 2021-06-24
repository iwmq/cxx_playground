#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include "pointer_demo_lib/pointer_demo.h"

// Make a linked list in an ugliy way
node* make_list()
{
    node* head;
    node* tail;

    const int NUM_NODES = 10;
    int values[10] = {1, -5, 6, 2, -3, 11, 7, 9, -12, 8};

    // Add first node
    tail = (node *)malloc(sizeof(node));
    tail->val = values[0];
    head = tail;

    // Add rest of nodes
    for(int i = 1; i < NUM_NODES; i++)
    {
        tail->next = (node *)malloc(sizeof(node));
        tail = tail->next;
        tail->val = values[i];
        tail->next = NULL;
    }

    return head;
}

void print_nodes(node* head)
{
    while(head != NULL)
    {
        printf("%d\t", head->val);
        head = head->next;
    }
    printf("\n");
}
