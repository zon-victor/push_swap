#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*nlist;
	t_list		*slist;
	t_list		*tmp;

	if (f == NULL && lst == NULL)
		return (NULL);
	tmp = f(lst);
	nlist = ft_lstnew(tmp->content, tmp->content_size);
	if (nlist == NULL)
		return (NULL);
	slist = nlist;
	while (lst->next != NULL)
	{
		tmp = f(lst->next);
		nlist->next = ft_lstnew(tmp->content, tmp->content_size);
		lst = lst->next;
		nlist = nlist->next;
	}
	return (slist);
}
