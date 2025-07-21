/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:36:51 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/21 13:46:52 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//Inclusion des librairies

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <string.h>
# include <fcntl.h>
# include "libft.h"

//Macro

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

//Utils
char	*ft_strjoin_gnl(char *s1, char *s2);
//char	*ft_strdup(const char *s1);
//size_t	ft_strlen(const char *s);
//char	*ft_strchr(const char *s, int c);
//char	*ft_substr(const char *s, unsigned int start, size_t len);

//GNL
char	*get_next_line(int fd);

#endif