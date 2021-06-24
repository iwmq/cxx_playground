#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include "pointer_demo_lib/pointer_demo.h"

_Bool negative_val(node const *p)
{   
    return p->val < 0;
}

node* remove_if(node** head, rm_fn rm)
{
    for(node** curr = head; *curr != NULL;)
    {
        node* entry = *curr;
        if(rm(entry))
        {
            *curr = entry->next;
            free(entry);
        }
        else
        {
            curr = &(entry->next);
        }
    }

    return *head;
}

int main(int argc, char* argv[])
{
    node* head = make_list();

    printf("Before: \n");
    print_nodes(head);

    head = remove_if(&head, negative_val);

    printf("After: \n");
    print_nodes(head);

    return 0;
}