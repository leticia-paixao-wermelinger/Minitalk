/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:44:39 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/02/17 00:52:25 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "my_libft/libft.h"
#include <signal.h>

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void	action(int sig)
{
	static int	byte;
	static int	i;
	int	arr[8] = {128, 64, 32, 16, 8, 4, 2, 1};

	if (!byte)
		byte = 0;
	if (!i || i == 8)
	{
		byte = 0;
		i = 0;
	}
	if (sig == SIGUSR1) // É 1
		byte += arr[i];
	else if (sig == SIGUSR2) // É 0
		byte += 0;
	if (i == 7)
		write(1, &byte, 1);
	i++;
}

int	main()
{
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	my_printf("%d\n", getpid());
	while (1)
		pause();
}
