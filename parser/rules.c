#include <stdlib.h>
#include <string.h>
#include <parser/rules.h>
#include <data_structures/linked_list.h>

void remove_comments(struct linked_node *list);

struct linked_node *tokenize(const char *line)
{
    struct linked_node *list;
    char *copy; // make a copy, because strtok destroys the input string
    char *token; // will store the output of strtok
    token = NULL; // init
    list = NULL; // init (so add works properly)
    copy = strdup(line);
    token = strtok(copy, " \t\r\n");
    if (token != NULL && *token != ';') //line is not empty and not comment
    {
        llist_add(&list, strdup(token));
        while ((token = strtok(NULL, " \t\r\n")))
            llist_add(&list, strdup(token));
    }
    free(copy);
    remove_comments(list);
    return list;
};

void remove_comments(struct linked_node *list)
{
    struct linked_node *curr;
    for (curr = list; curr->next != NULL; curr = curr->next)
    {
        if (*(char *)curr->next->data == ';')
        {
            llist_free(curr->next); // delete elements
            curr->next = NULL; // remove link
            break; // stop the loop
        }
    }
}
