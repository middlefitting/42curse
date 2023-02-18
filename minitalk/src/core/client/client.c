/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:31:59 by sechung           #+#    #+#             */
/*   Updated: 2022/12/29 17:20:05 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	argc_check(int argc)
{
	if (argc != 3)
	{
		ft_putstr_fd("ARGUMENTS MUST BE THREE\n", 1);
		exit(1);
	}
}

void	server_pid_check(int pid)
{
	if (pid < 100 || pid >= 100000)
	{
		ft_putstr_fd("PID IS NOT VALID\n", 1);
		exit(1);
	}
}

void	make_connection(void)
{
	ft_putstr_fd("connection..\n", 1);
	usleep_kill(get_server_pid(-1), SIGUSR1);
}

int	main(int argc, char **argv)
{
	argc_check(argc);
	server_pid_check(ft_atoi(argv[1]));
	get_server_pid(ft_atoi(argv[1]));
	get_msg(argv[2]);
	client_sigaction_init(valid_connection_handler, exit_process);
	make_connection();
	while (1)
		pause();
}
