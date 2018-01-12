/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 22:12:05 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/04 11:39:59 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	size;

	size = ft_strlen(src);
	ft_memcpy(dest, src, size);
	dest[size] = '\0';
	return (dest);
}
