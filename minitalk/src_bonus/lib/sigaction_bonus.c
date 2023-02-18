/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigaction_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:44:40 by sechung           #+#    #+#             */
/*   Updated: 2022/12/29 19:47:50 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	sigaction_init(void *handler)
{
	struct sigaction	s_server;

	s_server.sa_flags = SA_SIGINFO;
	s_server.sa_sigaction = handler;
	sigaddset(&s_server.sa_mask, SIGUSR1);
	sigaddset(&s_server.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &s_server, NULL);
	sigaction(SIGUSR2, &s_server, NULL);
}

void	client_sigaction_init(void *sigusr1_handler, void *sigusr2_handler)
{
	struct sigaction	sig1_client;
	struct sigaction	sig2_client;

	sig1_client.sa_flags = SA_SIGINFO;
	sig1_client.sa_sigaction = sigusr1_handler;
	sig2_client.sa_handler = sigusr2_handler;
	sigemptyset(&sig1_client.sa_mask);
	sigemptyset(&sig2_client.sa_mask);
	sigaction(SIGUSR1, &sig1_client, NULL);
	sigaction(SIGUSR2, &sig2_client, NULL);
}

void	usleep_kill(int pid, int signo)
{
	usleep(125);
	kill(pid, signo);
}
