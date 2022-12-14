/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:56:56 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/14 18:23:24 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <signal.h>

typedef struct s_signal
{
	int				received_len;
	int				received_string;
	int				nb_char;
	int				nb_bit_char;
	unsigned char	c;
	char			*str;
	size_t			len;
}	t_signal;

//prototypes error messages
int				ft_msg_error(int msg);

//prototypes utils
size_t			ft_reverse_len(size_t len);
unsigned char	ft_reverse_char(unsigned char c);

#endif
