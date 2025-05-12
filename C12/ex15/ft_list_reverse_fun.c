unsigned int ft_list_size(t_list *begin_list)
{
	unsigned int size = 0;
	t_list *current = begin_list;
	while (current)
	{
		size++;
		current = current->next;
	}
	return size;
}

t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int i = 0;
	t_list *current = begin_list;
	while (i < nbr && current)
	{
		current = current->next;
		i++;
	}
	return current;
}

void ft_list_reverse_fun(t_list *begin_list)
{
	if (!begin_list || !begin_list->next)
		return;

	unsigned int size = ft_list_size(begin_list);

	t_list *list_first_ptr;
	t_list *list_second_ptr;

	unsigned int i;
	void *temp;
	for (i = 0; i < size / 2; i++)
	{
		list_first_ptr = ft_list_at(begin_list, i);
		list_second_ptr = ft_list_at(begin_list, size - i - 1);

		temp = list_first_ptr->data;
		list_first_ptr->data = list_second_ptr->data;
     		list_second_ptr->data = temp;
	}
}
