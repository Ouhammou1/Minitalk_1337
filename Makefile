CC= cc 
CFLAGS = -Wall -Wextra -Werror 
PATH = ft_libft

OBJC = client.c $(PATH)/ft_atoi.c  $(PATH)/ft_strlen.c
ONBS = server.c $(PATH)/ft_putnbr.c $(PATH)/ft_putchar.c

OBJCB = client_bonus.c $(PATH)/ft_atoi.c $(PATH)/ft_strlen.c 
ONBSB =  server_bonus.c $(PATH)/ft_putnbr.c $(PATH)/ft_putchar.c

		
server = server 
client = client

server_b = server_bonus 
client_b = client_bonus

all : $(server) $(client)

$(server): $(ONBS) 
	
	$(CC)  $(CFLAGS) $(ONBS) -o $(server)

$(client): $(OBJC) 
	$(CC) $(CFLAGS) $(OBJC) -o $(client)
	
bonus : $(server_b) $(client_b)


$(server_b): $(ONBSB) 
	$(CC) $(CFLAGS) $(ONBSB) -o $(server_b)

$(client_b): $(OBJCB) 
	$(CC) $(CFLAGS) $(OBJCB) -o $(client_b)

clean : 
	rm -rf $(server) $(client) $(server_b) $(client_b)

fclean : clean
	
re : fclean all
