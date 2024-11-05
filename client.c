
#include "my_libft/libft.h"
#include <signal.h>

void	send_int(int pid, int n)
{
	int	bin;

	bin = 0;
	while (bin < 8)
	{
		if (n & 128 >> bin)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bin++;
		usleep(250);
	}
}

int	main(int argc, char *argv[])
{
	char	*str;
	int		pid;
	int		i;

	i = 0;
	if (argc != 3)
		return (0);
	str = argv[2];
	pid = my_atoi(argv[1]);
	while (str[i])
	{
		send_int(pid, str[i]);
		i++;
	}
	send_int(pid, '\n');
}
