#include <stdlib.h>

int	cycle_detector(const t_list *list)
{
	t_list *slow = list;
	t_list *fast = list;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (fast == slow)
			return 1;
	}
	return 0;
}
