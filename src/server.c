/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:14:23 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/06/02 16:28:34 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handle_signals(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("signal 1");
	if (signal == SIGUSR2)
		ft_printf("signal 2");
}
int	main(int argc, char **argv)
{
	ft_putstr_fd(ft_itoa(getpid()));
	struct sigaction sig;

	(void) argc;
	(void) argv;
	sig.sa_handler = &handle_signals;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	
	while (1)
	{
		pause();
		// kill(ft_atoi(argv[1]), SIGUSR2);
	}
}

// void	sigusr_handler(int signal)
// {
// 	if (signal == SIGINT)
// 		printf("\nHEY\n");
// }

// void	set_signal_action(void)
// {
// 	struct sigaction hyrule;

// 	bzero(&hyrule, sizeof(hyrule));
// 	hyrule.sa_handler = &sigusr_handler;
// 	sigaction(SIGINT, &hyrule, NULL);	
// }

// int main()
// {
// 	pid_t pid;

// 	pid = getpid();
// 	set_signal_action();
// 	printf("%d", getpid());
// 	while (1)
// 		continue ;
// 	return (0);
// }


// int x = 0;

// void handle_sigusr1(int sig)
// {
// 	if (x == 0)
// 		printf("eh oh");
// 	(void) sig;
// }

// int main()
// {
// 	int pid = fork();
// 	if (pid == -1)
// 		return 1;
	
// 	if (pid == 0)
// 	{
// 		sleep(5);
// 		kill(getppid(), SIGUSR1);
// 	} else {
// 		struct sigaction sa;
// 		// sa.sa_flags = SA_RESTART;
// 		sa.sa_handler = &handle_sigusr1;
// 		sigaction(SIGUSR1, &sa, NULL);
// 	}

// 	int x;
// 	printf("3 x 5 = ?");
// 	scanf("%d", &x);
// 	if (x == 15)
// 		printf("r");
// 	else
// 		printf("w");
// 	// wait(NULL);
// }

// // Variable globale partagée entre le programme
// // principal et la routine SIGINT. La routine mettra
// // cette variable à 1 lorsqu'on fait ctrl-c.
// // Déclarée volatile pour éviter quelle se retrouve
// // dans la mémoire cache à cause du compilateur
// volatile int	g_unblock_sigquit = 0;

// Fonction pour bloquer le signal spécifié
// void	block_signal(int signal)
// {
// //	L'ensemble des signaux à bloquer
// 	sigset_t	sigset;

// //	Initialise l'ensemble à 0
// 	sigemptyset(&sigset);
// //	Ajoute le signal à l'ensemble
// 	sigaddset(&sigset, signal);
// //	Ajoute les signaux de l'ensemble aux
// //	signaux bloqués pour ce processus
// 	sigprocmask(SIG_BLOCK, &sigset, NULL);
// 	if (signal == SIGQUIT)
// 		printf("\e[36mSIGQUIT (ctrl-\\) blocked.\e[0m\n");
// }

// // Fonction pour débloquer le signal spécifié
// void	unblock_signal(int signal)
// {
// //	L'ensemble des signaus à débloquer
// 	sigset_t	sigset;

// //	Initialise l'ensemble à 0
// 	sigemptyset(&sigset);
// //	Ajoute le signal à l'ensemble
// 	sigaddset(&sigset, signal);
// //	Retire les signaux de l'ensemble des
// //	signaux bloqués pour ce processus
// 	sigprocmask(SIG_UNBLOCK, &sigset, NULL);
// 	if (signal == SIGQUIT)
// 		printf("\e[36mSIGQUIT (ctrl-\\) unblocked.\e[0m\n");
// }

// // Routine de gestion du signal SIGINT
// void	sigint_handler(int signal)
// {
// 	if (signal != SIGINT)
// 		return ;
// //	Bloque les autres signaux SIGINT pour
// //	protéger la variable globale le temps
// //	de la modifier
// 	block_signal(SIGINT);
// 	g_unblock_sigquit = 1;
// 	unblock_signal(SIGINT);
// }

// void set_signal_action(void)
// {
// //	Déclaration de la structure sigaction
// 	struct sigaction	act;

// //	Initialiser la structure à 0.
// 	bzero(&act, sizeof(act));
// //	Nouvelle routine de gestion de signal
// 	act.sa_handler = &sigint_handler;
// //	Applique la nouvelle routine à SIGINT (ctrl-c)
// 	sigaction(SIGINT, &act, NULL);
// }

// int	main(void)
// {
// //	Change l'action par défaut de SIGINT (ctrl-c)
// 	set_signal_action();
// //	Bloque le signal SIGQUIT (ctrl-\)
// 	block_signal(SIGQUIT);
// //	Boucle infinie pour avoir le temps de faire ctrl-\ et
// //	ctrl-c autant de fois que ça nous chante.
// 	while(1)
// 	{
// //		Bloque le signal SIGINT le temps de lire la variable
// //		globale.
// 		block_signal(SIGINT);
// //		Si la routine de gestion de SIGINT a indiqué qu'elle a
// //		été invoquée dans la variable globale
// 		if (g_unblock_sigquit == 1)
// 		{
// //			SIGINT (ctrl-c) a été reçu.
// 			printf("\n\e[36mSIGINT detected. Unblocking SIGQUIT\e[0m\n");
// //			Débloque SIGINT et SIGQUIT
// 			unblock_signal(SIGINT);
// 			unblock_signal(SIGQUIT);
// 		}
// //		Sinon, on débloque SIGINT et on continue la boucle
// 		else
// 			unblock_signal(SIGINT);
// 		sleep(1);
// 	}
// 	return (0);
// }