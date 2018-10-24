#include <stdio.h>
#include <stdlib.h>

#include "linked.c"

int main(int argc, char **argv)
{
NODE *new, *list = (NODE *) NULL;

new = get_node(10);
list = new;

new = get_node(20);
new->next = list;
list = new;

new = get_node(30);
new->next = list;
list = new;

print_list(list);

return 1;
}
