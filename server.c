/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:35:53 by rteles            #+#    #+#             */
/*   Updated: 2022/02/15 23:25:24 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

volatile sig_atomic_t	shutdown_flag = 1;

void	cleanupRoutine(int signal_number)
{
    shutdown_flag = 0;
}

int	main(void)
{
	pid_t				ip;
	struct sigaction	signal_action;

	sigterm_action.sa_handler = &cleanupRoutine;
	sigterm_action.sa_flags = 0;

	ip = getpid();
	printf("PID: %i", ip);
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
           };*/
