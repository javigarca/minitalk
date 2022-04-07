# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javi_pop <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 18:16:14 by javi_pop          #+#    #+#              #
#    Updated: 2021/11/18 11:35:36 by javigarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a

SRCS		= ft_atoi.c \
			ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
		  	ft_isascii.c \
		 	ft_isdigit.c \
		 	ft_isprint.c \
		 	ft_memchr.c \
		 	ft_memcpy.c \
			ft_memcmp.c \
		 	ft_memmove.c \
		  	ft_memset.c \
		  	ft_strchr.c \
		  	ft_strlcat.c \
		  	ft_strlcpy.c \
		 	ft_strlen.c \
		  	ft_strncmp.c \
		  	ft_strnstr.c \
		  	ft_strrchr.c \
		  	ft_tolower.c \
		  	ft_toupper.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_strmapi.c \
			ft_striteri.c

BONUSSRCS	= ft_lstnew.c \
			  ft_lstadd_front.c \
			  ft_lstsize.c \
			  ft_lstlast.c \
			  ft_lstadd_back.c \
			  ft_lstdelone.c \
			  ft_lstclear.c \
			  ft_lstiter.c \
			  ft_lstmap.c

HEADER		= libft.h

OBJS		= ${SRCS:.c=.o}

BONUSOBJS	= ${BONUSSRCS:.c=.o}

CC			= gcc

RM			= rm -f

AR			= ar rc

LIB			= ranlib

CFLAGS		= -Wall -Wextra -Werror -I. -c

.c.o:
			${CC} ${CFLAGS} $< -o ${<:.c=.o}

$(NAME):	${OBJS} ${HEADER}
				${AR} ${NAME} ${OBJS} 
				${LIB} ${NAME}
 
all:		${NAME}

bonus:		${BONUSOBJS} ${HEADER}
				${AR} ${NAME} ${BONUSOBJS}
				${LIB} ${NAME}

clean:		
			${RM} ${OBJS} ${BONUSOBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all


.PHONY:		all clean fclean re bonus
