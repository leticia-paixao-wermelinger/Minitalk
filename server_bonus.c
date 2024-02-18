/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:44:39 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/02/17 11:14:29 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libft/libft.h"
#include <signal.h>

void	action(int sig)
{
	static int	byte = 0;
	static int	i = 0;
	int			arr[8];

	arr[0] = 128;
	arr[1] = 64;
	arr[2] = 32;
	arr[3] = 16;
	arr[4] = 8;
	arr[5] = 4;
	arr[6] = 2;
	arr[7] = 1;
	if (i == 8)
	{
		byte = 0;
		i = 0;
	}
	if (sig == SIGUSR1)
		byte += arr[i];
	else if (sig == SIGUSR2)
		byte += 0;
	if (i == 7)
		write(1, &byte, 1);
	i++;
}

int	main(void)
{
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	my_printf("%d\n", getpid());
	while (1)
		pause();
}
