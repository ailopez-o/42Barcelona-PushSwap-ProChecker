/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ops.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailopez- <ailopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:22:49 by aitorlope         #+#    #+#             */
/*   Updated: 2023/01/13 23:01:30 by ailopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_OPS_H
# define EXEC_OPS_H

int		exec_ops(t_meta *meta, char *op);
void	get_instructions(t_meta *meta);
int		execute_next_op(t_meta *meta);
int		run_ops(void *param);

#endif
