/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi_pop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 21:16:26 by javi_pop          #+#    #+#             */
/*   Updated: 2021/11/18 14:14:54 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINITALK_H__
# define __MINITALK_H__

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include "../Libft/libft.h"

void	ft_send_message(char *mess, int pid);

#endif
