#include "ft_list.h"
#include <stdio.h>

void ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new_node = ft_create_elem(data);

	if (new_node != NULL)
	{
		new_node->next = *begin_list;
		*begin_list = new_node;
	}
}

void print_list(t_list *head)
{
    while (head)
    {
        printf("%s -> ", (char *)head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main(void)
{
    t_list *list = NULL;

    ft_list_push_front(&list, "third");
    ft_list_push_front(&list, "second");
    ft_list_push_front(&list, "first");

    print_list(list);

    return 0;
}

