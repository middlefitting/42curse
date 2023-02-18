/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_handler_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:44:52 by sechung           #+#    #+#             */
/*   Updated: 2022/12/29 19:17:30 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_global_data	g_global_data;

void	global_data_init(siginfo_t *siginfo)
{
	g_global_data.client_pid = siginfo->si_pid;
	g_global_data.msg = ft_strdup("");
	if (g_global_data.msg == 0)
	{
		usleep_kill(siginfo->si_pid, SIGUSR2);
		exit(1);
	}
}

void	global_data_refresh(void)
{
	free(g_global_data.msg);
	g_global_data.client_pid = 0;
	g_global_data.msg = "";
}

void	connection_handler(int signo, siginfo_t *siginfo, void *context)
{
	(void) context;
	if (signo == SIGUSR2)
		return ;
	global_data_init(siginfo);
	sigaction_init(message_handler);
	kill(siginfo->si_pid, SIGUSR1);
}

void	message_handler(int signo, siginfo_t *siginfo, void *context)
{
	static int	bit = 8;
	static char	temp_char = '\0';

	(void) context;
	if (!client_check(g_global_data, siginfo))
		return ;
	if (!signal_check(signo, siginfo))
		return ;
	if (signo == SIGUSR1)
		temp_char += (1 << --bit);
	else if (signo == SIGUSR2)
		--bit;
	if (bit == 0)
	{
		if (temp_char != '\0')
			append_char(&g_global_data, &temp_char);
		else
			write_and_refresh(g_global_data);
		bit = 8;
		temp_char = '\0';
	}
	usleep_kill(siginfo->si_pid, SIGUSR1);
}
