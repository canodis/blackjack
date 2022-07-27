#include "../include/blackjack.h"

int	win = 0;
int lose = 0;

int	main(int argc, char **argv)
{
	t_game	game;
	init_all(&game);
	start_game(&game);
	free_game(&game);
}