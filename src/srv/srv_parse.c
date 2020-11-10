/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:09:44 by kcharla           #+#    #+#             */
/*   Updated: 2020/11/10 05:00:55 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_msg		srv_parse_str(t_srv *srv, const char* request)
{
	t_msg	msg;
	msg.status = MSG_NONE;
	if (request == NULL)
		return ((t_msg){MSG_ERROR, "request is NULL pointer"});
	if (ft_strcmp(request, "exit") == 0)
	{
		msg.str = "Closing connection. Have a nice day :) lol\n";
		msg.status = MSG_EXIT;
	}
	else if (ft_strcmp(request, "shutdown") == 0)
	{
		msg.str = "Shutting down...\n";
		msg.status = MSG_SHUT;
	}
	else if (ft_strcmp(request, "") == 0)
	{
		msg.str = ft_strdup("\n");
		msg.status = MSG_OK;
	}
	else
	{
		// if (parse_cmd_line(srv->rt, request) != -1)
		// 	;//OK
		ft_printf("parsing line \'%s\'\n", srv->client_line);
		msg = cmd_parse_line(srv->rt, (char *)request);
		ft_printf("done parsing line \'%s\'\n", srv->client_line);
//		if (msg.status == MSG_ERROR)
//		{
//			if (msg.)
//		}
//		msg.status = MSG_OK;
	}
	return (msg);
}
