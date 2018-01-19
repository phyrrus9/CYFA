#include <stdlib.h>
#include <assert.h>
#include <data_structures/linked_list.h>

void llist_add(struct linked_node **list, void *data)
{
    struct linked_node *node;
    struct linked_node *ptr;
    assert(list != NULL);
    node = malloc(sizeof(struct linked_node));
    node->data = data;
    node->next = NULL;
    if (*list != NULL)
    {
        for (ptr = *list; ptr->next != NULL; ptr = ptr->next); //go to end of list
        ptr->next = node;
    }
    else
        *list = node; //set head element
}
void llist_free(struct linked_node *list)
{
    assert(list != NULL);
    if (list->next != NULL)
        llist_free(list->next);
    free(list->data);
    free(list);
}
