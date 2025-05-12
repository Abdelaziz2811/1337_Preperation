#include "ft_list.h"

void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	if (!begin_list || !*begin_list)
	{
		*begin_list = ft_create_elem(data);
		return;
	}
	
	t_list *list_other_ptr = ft_create_elem(data);

	if ((*cmp)((*begin_list)->data, list_other_ptr->data) > 0)
	{
		list_other_ptr->next = *begin_list;
		*begin_list = list_other_ptr;
		return;
	}
	
	t_list *list_ptr = *begin_list;

	while (list_ptr && list_ptr->next)
	{
		if ((*cmp)(list_ptr->next->data, list_other_ptr->data) > 0)
		{
			list_other_ptr->next = list_ptr->next;
			list_ptr->next = list_other_ptr;
			return;
		}
		list_ptr = list_ptr->next;
	}

	list_ptr->next = list_other_ptr;
}
