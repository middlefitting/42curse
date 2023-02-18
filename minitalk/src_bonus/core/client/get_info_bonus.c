/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:18:30 by sechung           #+#    #+#             */
/*   Updated: 2022/12/29 19:17:06 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	get_server_pid(int pid)
{
	static int	server_pid = -1;

	if (pid != -1)
		server_pid = pid;
	return (server_pid);
}

char	*get_msg(char *msg)
{
	static char	*message = 0;

	if (msg)
		message = msg;
	return (message);
}
