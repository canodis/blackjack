#include "../include/blackjack.h"

int	main(int argc, char **argv)
{
	t_game	game;
	init_all(&game);
	start_game(&game);
	free_game(&game);

	// while(game.cards)
	// {
	// 	printf("name : %c --- value : %i\n", game.cards->name, game.cards->value);
	// 	game.cards = game.cards->next;
	// }
}