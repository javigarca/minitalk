# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 15:38:08 by javigarc          #+#    #+#              #
#    Updated: 2022/07/13 15:38:18 by javigarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------ Sources ------------------------------

# Files
SDIR		=	sources/

SERVER		=	$(SDIR)/server.c

SER_B		=	$(SDIR)/server_bonus.c

CLIENT		=	$(SDIR)/client.c

CLI_B		=	$(SDIR)/client_bonus.c

LIBFT		=	cd Libft && make

LIB			=	Libft/libft.a

# Sources and objects
SERVER_SRC	=	$(SERVER)

SERVER_OBJS	=	$(SERVER_SRC:.c=.o)

CLIENT_SRC	=	$(CLIENT)

CLIENT_OBJS	=	$(CLIENT_SRC:.c=.o)

SER_B_SRC	=	$(SER_B)

SER_B_OBJS	=	$(SER_B_SRC:.c=.o)

CLI_B_SRC	=	$(CLI_B)

CLI_B_OBJS	=	$(CLI_B_SRC:.c=.o)


OBJS		=	$(CLIENT_OBJS) \
				$(CLI_B_OBJS) \
				$(SERVER_OBJS) \
				$(SER_B_OBJS)

# ------------------------------ Constant strings ------------------------------

GCC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

INCLUDE		=	-I include

SERVER_NAME	=	server

SER_B_NAME	=	server_bonus

CLIENT_NAME	=	client

CLI_B_NAME	=	client_bonus

NAME		=	minitalk

# ------------------------------ Colors ------------------------------

BOLD_PURPLE	=	\033[1;35m

BOLD_CYAN	=	\033[1;36m

BOLD_YELLOW	=	\033[1;33m

NO_COLOR	=	\033[0m

# ------------------------------ Messages ------------------------------

COMP_START	=	echo "\n🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)Starting the compilation...\n"

SERV_READY	=	echo "\n📥 Server ready!\n"

CLI_READY	=	echo "\n📟 Client ready!\n"

SER_B_READY	=	echo "\n📥 Server BONUS ready!\n"

CLI_B_READY	=	echo "\n📟 Client BONUS ready!\n"

CLEANED		=	echo "\n💧 $(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"

FCLEANED	=	echo "\n🧼 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executables \n"

# ------------------------------ Rules ------------------------------

all: $(NAME)

$(NAME): comp_start server client

bonus: comp_start ser_b cli_b
		 
comp_start:
	@$(COMP_START)
	@$(LIBFT)

server: $(SERVER_OBJS)
	@$(GCC) $(FLAGS) $(SERVER_OBJS) $(LIB) -o $(SERVER_NAME)
	@$(SERV_READY)

client: $(CLIENT_OBJS)
	@$(GCC) $(FLAGS) $(CLIENT_OBJS) $(LIB) -o $(CLIENT_NAME)
	@$(CLI_READY)

ser_b: $(SER_B_OBJS)
	@$(GCC) $(FLAGS) $(SER_B_OBJS) $(LIB) -o $(SER_B_NAME)
	@$(SER_B_READY)

cli_b: $(CLI_B_OBJS)
	@$(GCC) $(FLAGS) $(CLI_B_OBJS) $(LIB) -o $(CLI_B_NAME)
	@$(CLI_B_READY)

clean:
	@rm -rf $(OBJS)
	@cd libft && make clean
	@$(CLEANED)

fclean: clean
	@rm -rf $(SERVER_NAME) $(CLIENT_NAME) $(SER_B_NAME) $(CLI_B_NAME)
	@cd libft && make fclean
	@$(FCLEANED)

.c.o:
	@${GCC} ${FLAGS} $(INCLUDE) -c $< -o ${<:.c=.o}

re:	fclean all

.PHONY: all minitalk server client clean fclean re libft bonus
