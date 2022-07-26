#include "../include/blackjack.h"

void	free_game(t_game *game)
{
	t_cards	*tmp;
	while(game->cards)
	{
		tmp = game->cards;
		game->cards = game->cards->next;
		free(tmp);
	}
}