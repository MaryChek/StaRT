/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scn_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 22:55:50 by kcharla           #+#    #+#             */
/*   Updated: 2020/11/16 22:03:32 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				scn_deinit(t_scn *scn)
{
	size_t		i;

	if (scn == NULL)
		return (rt_err("scn_deinit(): scn is NULL pointer"));
	ft_free(scn->filename);
	(void)i;
//	obj_deinit(scn->main_group);
	i = 0;
	while (i < scn->materials_num)
		mat_deinit(scn->materials[i++]);
	ft_free(scn->materials);
	i = 0;
	while (i < scn->cameras_num)
		cam_deinit(scn->cameras[i++]);
	ft_free(scn->cameras);
	i = 0;
	while (i < scn->textures_num)
		txr_deinit(scn->textures[i++]);
	ft_free(scn->textures);
	ft_free(scn);
	return (0);
}

int				scn_init_cam(t_scn *scn)
{
	if (scn == NULL)
		return (rt_err("Given pointer is NULL"));
	scn->cameras = ft_memalloc(sizeof(t_cam *));
	if (cam_init_default(scn->cameras, scn))
	{
		scn_deinit(scn);
		return (rt_err("scn_init(): cannot init camera"));
	}
	scn->cameras_num = 1;
	scn->cameras[0]->id = DEFAULT_CAMERA_ID;
	scn->camera_active = scn->cameras[0];
	return (0);
}

int				scn_init_mat(t_scn *scn)
{
	if (scn == NULL)
		return (rt_err("Given pointer is NULL"));
	scn->materials = ft_memalloc(sizeof(t_mat *));
	if (mat_init_default(scn->materials, scn))
	{
		scn_deinit(scn);
		return (rt_err("scn_init(): cannot init material"));
	}
	scn->materials_num = 1;
	return (0);
}

int				scn_init(t_scn **dest)
{
	t_scn		*scn;

	if (dest == NULL)
		return (rt_err("scn_init(): rt is NULL pointer"));
	if ((scn = ft_memalloc(sizeof(t_scn))) == NULL)
		return (rt_err("scn_init(): malloc returned NULL pointer"));
	scn->filename = ft_strdup(DEFAULT_GROUP_NAME);
	if (obj_grp_init(&(scn->main_group), ft_strdup(DEFAULT_GROUP_NAME)))
	{
		scn_deinit(scn);
		return (rt_err("scn_init(): cannot init main group"));
	}
	if (scn_init_mat(scn))
		return (rt_err("scn_init(): cannot init default material"));
	if (scn_init_cam(scn))
		return (rt_err("scn_init(): cannot init default camera"));
	scn->textures = NULL;
	scn->textures_num = 0;
//	if (scn_init_txr(scn))
//		return (rt_err("scn_init(): cannot init camera"));
	*dest = scn;
	return (0);
}
