#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

struct linked_node
{
    void *data;
    struct linked_node *next;
};

void llist_add(struct linked_node **list, void *data);
void llist_free(struct linked_node *list);

#endif // LINKED_LIST_H_INCLUDED
