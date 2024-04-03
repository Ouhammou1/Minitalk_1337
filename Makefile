FLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

server	=	server
client	=	client


OBJs	=	server.c
OBJc	=	client.c


all: ${server} ${client}

${server}: ${OBJs}
			${CC} ${CFLAGS} ${OBJs} -o ${server}
${client}: ${OBJc}
			${CC} ${CFLAGS} ${OBJc} -o ${client}

clean:
	${RM} ${server} ${client} 

fclean:	clean

re:	fclean all