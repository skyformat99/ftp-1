/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 15:35:45 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/09/19 13:12:38 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTP_H
# define FTP_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/param.h>
# include <stdint.h>
# include <sys/mman.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <dirent.h>
# include "libft.h"

# define BUF_SIZE 256
# define ASC_SIZE BUF_SIZE - sizeof(uint8_t)

# define CMD_LS 0x1
# define CMD_CD 0x2
# define CMD_GET 0x3
# define CMD_PUT 0x4
# define CMD_PWD 0x5
# define CMD_QUIT 0x6

typedef struct sockaddr_in	t_sockaddr_in;

typedef struct		s_sock_data
{
	int				id;
	t_sockaddr_in	addr;
}					t_sock_data;

typedef struct		s_ftp_cmd
{
	uint8_t			cmd;
	char			ascii[ASC_SIZE];
}					t_ftp_cmd;

char				*get_root(void);
char				*get_dir(void);
char				*basename(char *str);

void				cmd_ls(t_sock_data *sock);
void				cmd_cd(t_sock_data *sock, char *ascii);
void				cmd_get(t_sock_data *sock, char *ascii);
void				cmd_put(t_sock_data *sock, char *ascii);
void				cmd_pwd(t_sock_data *sock);
void				cmd_quit(t_sock_data *sock);
void				cmd_error(t_sock_data *sock, char *ascii);

void				client_get(t_sock_data *sock, t_ftp_cmd *cmd);
void				client_put(t_sock_data *sock, t_ftp_cmd *cmd);

void				pexit(char *str, int outno);
int					perr(char *str);

#endif
