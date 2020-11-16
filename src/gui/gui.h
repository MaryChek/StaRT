/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 23:44:57 by kcharla           #+#    #+#             */
/*   Updated: 2020/11/16 11:28:41 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GUI_H
# define GUI_H

# include "rt_types.h"

# define RT_GTK_THEME "src/gui/theme.css"

int				gui_loop(t_rt *rt, int ac, char **av);
int				gui_init(t_rt *rt);
int				gui_deinit(t_rt *rt);
void			gui_style(GtkWidget *widget);

#endif
