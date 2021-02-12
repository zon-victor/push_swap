#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	void	*ctnt;

	ctnt = (void *)ft_memalloc(content_size + 1);
	if (!ctnt)
		return (NULL);
	if (content == NULL)
	{
		ctnt = NULL;
		content_size = 0;
	}
	else
		ctnt = ft_memcpy(ctnt, content, content_size);
	list = (t_list *)ft_memalloc(sizeof(t_list));
	if (list != (t_list *)NULL)
	{
		list->content_size = content_size;
		list->next = NULL;
		list->content = ctnt;
	}
	return (list);
}
