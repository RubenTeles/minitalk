/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:35:53 by rteles            #+#    #+#             */
/*   Updated: 2022/04/02 23:01:13 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "ft_minitalk.h"

volatile sig_atomic_t	shutdown_flag = 1;

static void	action(int sig, siginfo_t *info, void *context)
{

}

void	cleanupRoutine(int signal_number)
{
    shutdown_flag = 0;
}

int	main(void)
{
	pid_t				ip;
	struct sigaction	signal_action;

	signal_action.sa_handler = cleanupRoutine;
	signal_action.sa_flags = 0;
	signal_action.sa_sigaction = action;
	sigaction(SIG);
	ip = getpid();
	ft_printf("PID: %i\n", ip);
	while (1)
		pause();
	return (0);
}

/*
struct sigaction {
               void     (*sa_handler)(int);
               void     (*sa_sigaction)(int, siginfo_t *, void *);
               sigset_t   sa_mask;
               int        sa_flags;
               void     (*sa_restorer)(void);
           };
		   
		   
int kill(pid_t ip, int sig) envia sinal para o processo
		   
		   
		   
		   */


