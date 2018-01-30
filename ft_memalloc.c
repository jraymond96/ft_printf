/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:58:18 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/03 15:34:22 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*new_str;

	if (!(new_str = (char*)malloc(sizeof(*new_str) * size)))
		return (NULL);
	ft_bzero(new_str, size);
	return (new_str);
}
