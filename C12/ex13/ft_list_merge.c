void ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	if (begin_list2 == NULL)
		return;

	if (*begin_list1 == NULL)
	{
		*begin_list1 = begin_list2;
		return;
	}

	t_list *list_ptr = *begin_list1;
	while (list_ptr->next)
		list_ptr = list_ptr->next;

	list_ptr->next = begin_list2;
}
