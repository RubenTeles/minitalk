/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:32:27 by rteles            #+#    #+#             */
/*   Updated: 2022/04/23 14:26:00 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

static void	action(int sig)
{
	if (sig == SIGUSR1)
	{
		write(STDOUT_FILENO, "Received!", 9);
		write(STDOUT_FILENO, "\n", 1);
		exit(-1);
	}
}

int	convert_pid(char *pid)
{
	int	ip;
	int	i;
	int	p;

	p = 1;
	i = 0;
	ip = 0;
	while (pid[i])
		i++;
	i--;
	while (i >= 0)
	{
		ip += (pid[i] - '0') * p;
		p *= 10;
		i--;
	}
	return (ip);
}

static void	send_char(pid_t ip, char c)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		kill(ip, ((c >> i & 1) + SIGUSR1));
		usleep(100);
	}
}

void	send_message(pid_t ip, char *message)
{
	int	index;

	index = 0;
	while (message[index])
	{
		send_char(ip, message[index]);
		index++;
	}
	if (message[index] == '\0')
		send_char(ip, message[index]);
}

int	main(int argc, char **argv)
{
	pid_t	ip;

	if (argc != 3)
		return (0);
	signal(SIGUSR1, action);
	ip = convert_pid(argv[1]);
	send_message(ip, argv[2]);
	while (1)
		pause();
	return (0);
}
