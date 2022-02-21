/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:44:53 by rteles            #+#    #+#             */
/*   Updated: 2022/02/21 20:22:22 by rteles           ###   ########.fr       */
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

int	main(int argc, char **argv)
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
retorna 0 se o sinal for enviado com sucesso e -1 se deu erro
signal
SIGINT       terminate process    interrupt program
SIGUSR1 terminate process    User defined signal 1
SIGUSR2 terminate process    User defined signal 2
*/