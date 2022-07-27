CC = gcc -g
SRCS = srcs/main.c srcs/init.c srcs/free_game.c srcs/start_game.c \
srcs/dealer.c srcs/card_things.c srcs/utils.c srcs/player.c
NAME = blackjack
Color_s = \033[92m
Color_e = \033[0m


all: banner name

name:
	$(CC) $(SRCS) -o $(NAME) -lreadline

fclean:
	rm -rf $(NAME)

re: fclean all

banner:
	@echo "$(Color_s).------. .------. .------. .------. .------. .------. .------."
	@echo "|\x1B[31mC$(Color_s).--. | |\x1B[33mA$(Color_s).--. | |\x1B[34mN$(Color_s).--. | |\x1B[35mO$(Color_s).--. | |\x1B[36mD$(Color_s).--. | |\x1B[37mI$(Color_s).--. | |\x1b[31mS$(Color_s).--. |"
	@echo "| :/\: | | (\/) | | :(): | | :/\: | | :/\: | | (\/) | | :/\: |"
	@echo "| :\/: | | :\/: | | ()() | | :\/: | | (__) | | :\/: | | :\/: |"
	@echo "| '--'\x1B[31mC$(Color_s)| | '--'\x1B[33mA$(Color_s)| | '--'\x1B[34mN$(Color_s)| | '--'\x1B[35mO$(Color_s)| | '--'\x1B[36mD$(Color_s)| | '--'\x1B[37mI$(Color_s)| | '--'\x1b[31mS$(Color_s)|"
	@echo "\`------' \`------' \`------' \`------' \`------' \`------' \`------'\$(Color_e)"