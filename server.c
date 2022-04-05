/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:31:18 by rteles            #+#    #+#             */
/*   Updated: 2022/04/05 22:12:34 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	a;

	a = ' ';
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n > -2147483648 && n < 0)
	{
		a = '-';
		write(fd, &a, 1);
		ft_putnbr_fd(n *= -1, fd);
	}
	else if (n < 10)
	{
		a = n + '0';
		write(fd, &a, 1);
	}
	else if (n > -2147483648 && n <= 2147483647)
	{
		a = (n % 10) + '0';
		ft_putnbr_fd(n /= 10, fd);
		write(fd, &a, 1);
	}
}

static void	action(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				i = 0;

	(void)context;
	if (sig == SIGINT)
	{
		write(STDOUT_FILENO, "Bye bye... 👋\n", 15);
		exit(-1);
	}
	if (i < 9)
		c = ((sig - 30) << i++) | c;
	if (i == 8)
	{
		i = 0;
		write(STDOUT_FILENO, &c, 1);
		if (!c)
		{
			write(STDOUT_FILENO, "\n", 1);
			kill(info->si_pid, SIGUSR1);
			return ;
			usleep(1000);
		}
		c = 0;
	}
}

int	main(void)
{
	pid_t				ip;
	struct sigaction	signal_action;

	signal_action.sa_flags = SA_SIGINFO;
	signal_action.sa_sigaction = action;
	sigaction(SIGINT, &signal_action, NULL);
	sigaction(SIGUSR1, &signal_action, NULL);
	sigaction(SIGUSR2, &signal_action, NULL);
	ip = getpid();
	write(STDOUT_FILENO, "PID: ", 5);
	ft_putnbr_fd(ip, 1);
	write(STDOUT_FILENO, "\n", 1);
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


/*
struct sigaction {
               void     (*sa_handler)(int); 						- e onde lidamos com os sinais
               void     (*sa_sigaction)(int, siginfo_t *, void *);  - 
               sigset_t   sa_mask;									- bloquear sinais 
               int        sa_flags;
               void     (*sa_restorer)(void);
           };
*/