void ft_list_sort(t_list **begin_list, int (*cmp)())
{
	if (!begin_list || !*begin_list || !(*begin_list)->next)
		return;

	t_list *list_ptr = *begin_list;
	t_list *list_other_ptr;
	
	while (list_ptr && list_ptr->next)
	{
		list_other_ptr = list_ptr->next;
		while (list_other_ptr)
		{
			if ((*cmp)(list_ptr->data, list_other_ptr->data) > 0)
			{
				void *temp = list_ptr->data;
				list_ptr->data = list_other_ptr->data;
				list_other_ptr->data = temp;
			}
			list_other_ptr = list_other_ptr->next;
		}
		list_ptr = list_ptr->next;
	}
}
