/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 15:57:55 by kcharla           #+#    #+#             */
/*   Updated: 2020/11/10 01:06:28 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_H
# define ERR_H

# include "srv.h"

t_msg       msg_err(char *msg);
t_msg       msg_ok(char *str);

int			rt_err(char *msg);
int			rt_error(char *msg, int ecode);

int			rt_warn(char *msg);
int			rt_warning(char *msg, int ecode);

#endif
