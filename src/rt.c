/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 18:25:33 by kcharla           #+#    #+#             */
/*   Updated: 2020/11/16 20:31:06 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				rt_init(t_rt **rt)
{
	if (rt == NULL)
		return (rt_err("rt is NULL pointer"));
	*rt = (t_rt*)malloc(sizeof(t_rt));
	if (*rt == NULL)
		return (rt_err("rt malloc fail"));
	// if (gpu_init(*rt))
	// 	return (rt_err("scn_init() fail"));
	if (scn_init(&((*rt)->scene)))
		return (rt_err("gpu_init() fail"));
	(*rt)->mutex = &((*rt)->mutex_true);
	g_mutex_init((*rt)->mutex);
	return (0);
}

int				rt_deinit(t_rt *rt)
{
	if (rt == NULL)
		return (rt_err("rt is NULL pointer"));
	g_mutex_clear(rt->mutex);
	scn_deinit(rt->scene);
	ft_free(rt);
	return (0);
}
