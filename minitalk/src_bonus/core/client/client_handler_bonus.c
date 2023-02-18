/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_handler_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:18:25 by sechung           #+#    #+#             */
/*   Updated: 2022/12/29 19:17:03 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	send_message(void)
{
	static int	ind = 0;
	static int	bit = 8;
	char		*msg;

	msg = get_msg(0);
	if (*(msg + ind) == '\0' && bit == 0)
		return (1);
	if (bit == 0)
	{
		ind ++;
		bit = 8;
	}
	if ((*(msg + ind) >> --bit) & 1)
		usleep_kill(get_server_pid(-1), SIGUSR1);
	else
		usleep_kill(get_server_pid(-1), SIGUSR2);
	return (0);
}

void	send_message_handler(int signo, siginfo_t *siginfo, void *context)
{
	int	end;

	end = 0;
	(void) context;
	if (signo == SIGUSR1 && get_server_pid(-1) == siginfo->si_pid)
		end = send_message();
	if (end == 1)
	{
		ft_putstr_fd("Finish\n", 1);
		exit(1);
	}
}

void	exit_process(int signo)
{
	if (signo != SIGUSR2)
		return ;
	ft_putstr_fd("Something wrong..\n", 1);
	exit(1);
}

void	valid_connection_handler(int signo, siginfo_t *siginfo, void *context)
{
	(void) context;
	if (signo == SIGUSR1 && get_server_pid(-1) == siginfo->si_pid)
	{
		ft_putstr_fd("connection success!\n", 1);
		client_sigaction_init(send_message_handler, exit_process);
		send_message();
	}
}
