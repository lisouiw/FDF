#include "fdf.h"

t_w *ft_add(t_w *begin_lst, char *str)
{
	t_w *tmp_lst;

	tmp_lst = begin_lst;
	while (tmp_lst->next != NULL)
		tmp_lst = tmp_lst->next;
	tmp_lst->next = (t_w*)malloc(sizeof(t_w));
	tmp_lst->next->list = str;
	tmp_lst->next->next = NULL;
	return (begin_lst);
}

void 	ft_afficher(t_w *begin_lst)
{
	t_w		*tmp;

	tmp = begin_lst;
	while (tmp->next != NULL)
	{
		printf("%s\n", tmp->list);
		tmp = tmp->next;
	}
	printf("%s\n", tmp->list);
}

int main()
{
	t_w *begin_lst;

	begin_lst = (t_w*)malloc(sizeof(t_w));
	begin_lst->list = "liste 1";
	begin_lst->next = NULL;
	
	begin_lst = ft_add(begin_lst, "liste 2");
	begin_lst = ft_add(begin_lst, "liste 3");
	begin_lst = ft_add(begin_lst, "liste 4");
	begin_lst = ft_add(begin_lst, "liste 5");
	ft_afficher(begin_lst);
	return (0);
}


