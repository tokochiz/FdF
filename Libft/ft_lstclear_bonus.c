/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:23:18 by  ctokoyod         #+#    #+#             */
/*   Updated: 2023/12/26 21:05:16 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*temp;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		temp = current->next;
		del(current->content);
		free(current);
		current = temp;
	}
	*lst = NULL;
}

// void	de_content(void *content)
// {
// 	if (content != NULL)
// 		free(content);
// }

// int	main(void)
// {
// 	t_list *head;
// 	t_list *new_node1;
// 	t_list *new_node2;
// 	t_list *current;

// 	head = NULL;
// 	new_node1 = ft_lstnew("Hello");
// 	new_node2 = ft_lstnew("World");
// 	// リストに要素を追加
// 	ft_lstadd_back(&head, new_node1);
// 	ft_lstadd_back(&head, new_node2);
// 	// リストの内容を表示
// 	current = head;
// 	while (current)
// 	{
// 		printf("%s -> ", (char *)current->content);
// 		current = current->next;
// 	}
// 	printf("NULL\n");
// 	ft_lstclear(&head, de_content);
// 	while (current)
// 	{
// 		printf("%s -> ", (char *)current->content);
// 		current = current->next;
// 	}
// 	printf("NULL\n");
// 	// リストの解放
// 	while (head)
// 	{
// 		t_list *tmp;

// 		tmp = head;
// 		head = head->next;
// 		free(tmp);
// 	}

// 	return (0);
// }