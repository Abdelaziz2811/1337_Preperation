#include "../list_test_files/ft_list.h"

t_list *ft_list_push_strs(int size, char **strs)
{
	t_list *strs_list = NULL;
	int i;
	for (i = 0; i < size; i++)
	{
		t_list *new_node = ft_create_elem(strs[i]);

		if (new_node) 
		{
			new_node->next = strs_list;
			strs_list = new_node;
		}		
	}
	return strs_list;
}
