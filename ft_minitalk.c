/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:44:53 by rteles            #+#    #+#             */
/*   Updated: 2022/02/15 23:05:04 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_minitalk.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static void	handler(int signal)
{
	if (signal == SIGINT && write(1, "Bye bye...", 10))
		exit(-1);
}

int	main(void)
{
	pid_t	ip;

	signal(SIGINT, handler);
	ip = getpid();
	printf("PID: %i", ip);
	while (1)
		pause();
	return (0);
}

/*
kill() - envia um sinal para um outro processo ou para um outro grupo de processos
signal
SIGINT       terminate process    interrupt program
SIGUSR1 terminate process    User defined signal 1
SIGUSR2 terminate process    User defined signal 2
*/