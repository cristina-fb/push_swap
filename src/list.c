#include "push_swap.h"

void	free_list(t_list **lst)
{
	t_list	*aux1;
	t_list	*aux2;

	aux1 = lst[0];
	if (lst[0])
	{
		while (aux1)
		{
			free(aux1->content);
			aux2 = aux1;
			aux1 = aux1->next;
			free(aux2);
		}
		//free(lst);
	}
}

void	print_list(t_list *lst)
{
	t_list	*aux;

	aux = lst;
	while (aux)
	{
		printf("%d\n", *(int *)aux->content);
		aux = aux->next;
	}
}

void	add_to_list(char *str, t_list **lst)
{
	int		*value;
	t_list	*aux;

	value = ft_calloc(1, sizeof(int));
	if (value)
	{
		*value = ft_atoi((const char *)str);
		aux = ft_lstnew(value);
		if (!lst[0])
			lst[0] = aux;
		else
			ft_lstadd_back(lst, aux);
	}
}
