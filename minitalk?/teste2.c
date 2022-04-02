
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



size_t	ft_strlen(const char *string)
{
	size_t	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
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

void	send_leng(int ip, int len)
{
	int	i;

	i = -1;
	while (++i < 32)
	{
		while (++i < 8)
			kill(ip, ((len >> i & 1) + SIGUSR1));
	}
}

void	send_message(int ip, char *message)
{
	int	i;
	int	index;

	index = -1;
	i = -1;
	while (message[++index])
	{
		while (++i < 8)
			kill(ip, ((message[index] >> i & 1) + SIGUSR1));
	}
}

int	main(int argc, char **argv)
{
	pid_t	ip;
	int		message;

	ip = convert_pid(argv[1]);
	send_leng(ip, ft_strlen(argv[2]));
	send_message(ip, argv[2]);
	return (0);
}


