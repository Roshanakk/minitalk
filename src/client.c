/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:27:54 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/06/01 16:46:12 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <sys/types.h>
#include <sys/wait.h>

int x;

void handle_signals(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("signal 1");
	if (signal == SIGUSR2)
		ft_printf("signal 2");
}

int main(int argc, char **argv)
{
	struct sigaction sig;
	int pid;

	(void) argc;
	sig.sa_handler = &handle_signals;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	pid = getpid();
	ft_putstr_fd("PID :");
	ft_putstr_fd(ft_itoa(getpid()));
	
	while (1)
	{
		pause();
		kill(ft_atoi(argv[1]), SIGUSR2);
	}
}

// int x = 0;

// void handle_sigusr1(int signal)
// {
// 	(void) signal;
// 	if (x == 0)
// 		printf("un indice");
// }

// int main(int argc, char **argv)
// {
// 	(void) argc;
// 	(void) argv;

// 	int pid = fork();
// 	if (pid == -1)
// 		return 1;
	
// 	// int pid = 0;
// 	if (pid == 0)
// 	{
// 		// sleep(5);
// 		kill(getpid(), SIGUSR1);
// 	} else {
// 		struct sigaction set;
// 		set.sa_flags = SA_RESTART;
// 		set.sa_handler = &handle_sigusr1;
// 		sigaction(SIGUSR1, &set, NULL);


// 		printf("3 x 5 ?");
// 		scanf("%d", &x);
// 		if (x == 15)
// 			printf("OK");
// 		else
// 			printf("KO");
// 		// wait(NULL);
// 	}
// }

// void sigusr_handler(int signal)
// {
// 	if (signal == SIGUSR1)
// 		printf("signal recu");
// }

// void	serveur(char *pid_server)
// {
// 	pid_t	pid_client;
// 	struct sigaction act;

// 	pid_client = getpid();
	
// 	sigaction(SIGUSR2, &act, NULL);
// }
 
// void	aff_msg()
// {
	
// }
 
// int	main(int argc, char **argv)
// {
// 	(void) argc;
// 	(void) argv;
// 	serveur(argv[1]);

// 	while (1);
// }