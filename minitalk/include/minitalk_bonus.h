/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:44:58 by sechung           #+#    #+#             */
/*   Updated: 2022/12/29 19:17:39 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_global_data
{
	pid_t	client_pid;
	char	*msg;
}	t_global_data;

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
void	connection_handler(int signo, siginfo_t *siginfo, void *context);
void	message_handler(int signo, siginfo_t *siginfo, void *context);
int		client_check(t_global_data global_data, siginfo_t *siginfo);
int		signal_check(int signo, siginfo_t *siginfo);
void	append_char(t_global_data *global_data, char *temp_char);
void	write_and_refresh(t_global_data global_data);
void	global_data_refresh(void);
void	sigaction_init(void *handler);
void	client_sigaction_init(void *sigusr1_handler, void *sigusr2_handler);
void	usleep_kill(int pid, int signo);
int		get_server_pid(int pid);
char	*get_msg(char *msg);
int		send_message(void);
void	send_message_handler(int signo, siginfo_t *siginfo, void *context);
void	exit_process(int signo);
void	valid_connection_handler(int signo, siginfo_t *siginfo, void *context);
#endif
