/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:31:18 by rteles            #+#    #+#             */
/*   Updated: 2022/04/02 23:01:15 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*g_str;

static void	action(int sig, siginfo_t *info, void *context)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	if (sig == SIGINT)
	{
		write(STDOUT_FILENO, "Bye bye...\n", 10);
		exit(-1);
	}
	if (!g_str)
	{
		if (sig == SIGUSR1 || sig == SIGUSR2)
		{
			while (++i < 32)
				len = (*info << i && 1 | len);
		}
		g_str = malloc(sizeof(char) * (len + 1));
		if (!g_str)
			exit(-1);
	}
	else if (sig == SIGUSR1 || sig == SIGUSR2)
}

int	main(int argc, char **argv)
{
	pid_t				ip;
	struct sigaction	signal_action;

	signal_action.sa_mask = 0;
	signal_action.sa_flags = 0;
	signal_action.sa_sigaction = action;
	g_str = NULL;
	sigaction(SIGINT, &signal_action, NULL);
	sigaction(SIGUSR1, &signal_action, NULL);
	sigaction(SIGUSR2, &signal_action, NULL);
	ip = getpid();
	printf("PID: %i\n", ip);
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


/*struct sigaction {
               void     (*sa_handler)(int); 						- e onde lidamos com os sinais
               void     (*sa_sigaction)(int, siginfo_t *, void *);  - 
               sigset_t   sa_mask;									- bloquear sinais 
               int        sa_flags;
               void     (*sa_restorer)(void);
           };*/