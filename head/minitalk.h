/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:56:56 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/16 14:03:50 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <signal.h>

typedef struct s_signal
{
	int				received_len;
	int				client_id;
	int				received_string;
	int				nb_char;
	int				nb_bit_char;
	unsigned char	c;
	char			*str;
	size_t			len;
}	t_signal;

typedef struct s_client
{
	int				len_sent;
	int				bit_32;
	int				bit_8;
	int				nb_char;
	unsigned char	c;
	size_t			len;
	char			*str;
}	t_client;

//prototypes error messages
int				ft_msg_error(int msg);

//prototypes utils
size_t			ft_reverse_len(size_t len);
unsigned char	ft_reverse_char(unsigned char c);
int				ft_initialize_sa(struct sigaction *sa, int flag);
void			ft_initialize_client(t_client *client, size_t len, char *str);

#endif
