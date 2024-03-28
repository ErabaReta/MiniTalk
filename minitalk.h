/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <eouhrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:29:33 by eouhrich          #+#    #+#             */
/*   Updated: 2024/03/22 02:41:33 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <limits.h>
//======== server ==========
void	ft_putchar(char c);
void	ft_putnbr(long nbr);
void	signal_handler(int sig, siginfo_t *info, void *context);
//======== client ==========
long	ft_minitalk_atoi(const char *str);
void	sig_handler(int sig);
void	bits_sender(pid_t pid, char **av);

#endif