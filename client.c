/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:44:53 by rteles            #+#    #+#             */
/*   Updated: 2022/04/02 23:01:12 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_minitalk.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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

int	main(int argc, char **argv)
{
	pid_t	ip;
	int		message;

	ip = convert_pid(argv[1]);
	kill(ip, message);
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