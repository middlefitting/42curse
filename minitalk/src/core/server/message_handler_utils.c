/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_handler_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:18:34 by sechung           #+#    #+#             */
/*   Updated: 2022/12/29 17:28:09 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	client_check(t_global_data g_global_data, siginfo_t *siginfo)
{
	if (g_global_data.client_pid != siginfo->si_pid)
	{
		kill(siginfo->si_pid, SIGUSR2);
		return (0);
	}
	return (1);
}

int	signal_check(int signo, siginfo_t *siginfo)
{
	if (signo == SIGUSR1 || signo == SIGUSR2)
		return (1);
	kill(siginfo->si_pid, SIGUSR2);
	return (0);
}

void	append_char(t_global_data *g_global_data, char *temp_char)
{
	char		*temp_str;

	temp_str = ft_strjoin(g_global_data->msg, temp_char);
	if (temp_str == 0)
	{
		usleep_kill(g_global_data->client_pid, SIGUSR2);
		exit(1);
	}
	free(g_global_data->msg);
	g_global_data->msg = temp_str;
}

void	write_and_refresh(t_global_data g_global_data)
{
	ft_putstr_fd(g_global_data.msg, 1);
	global_data_refresh();
	sigaction_init(connection_handler);
}
