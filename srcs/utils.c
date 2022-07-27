#include "../include/blackjack.h"

bool	charcmp(char a, char b)
{
	if (a == b)
		return true;
	return false;
}

int	random_range(int start, int end)
{
	srand(time(0));
	return ((rand() % (end - start + 1)) + start);
}

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