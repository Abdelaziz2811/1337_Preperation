#include "ft_list.h"

void ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
	if (!begin_list2)
		return;

	if (!*begin_list1 && begin_list2)
	{
		*begin_list1 = begin_list2;
		return;
	}
	
	t_list *next_node;

	if ((*cmp)((*begin_list1)->data, begin_list2->data) > 0)
	{
		next_node = *begin_list1;
		*begin_list1 = begin_list2;
		begin_list2 = begin_list2->next;
		(*begin_list1)->next = next_node;
	}

	t_list *list_ptr = *begin_list1;
	
	while (list_ptr->next && begin_list2)
	{
		if ((*cmp)(list_ptr->next->data, begin_list2->data) > 0)
		{
			next_node = list_ptr->next;
			list_ptr->next = begin_list2;
			
			list_ptr = list_ptr->next;
			list_ptr->next = next_node;
			
			begin_list2 = begin_list2->next;
		}
		else 
			list_ptr = list_ptr->next;
	}

	if (begin_list2)
		list_ptr->next = begin_list2;
}
