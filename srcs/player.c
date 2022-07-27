#include "../include/blackjack.h"

int	player_first(t_game *game)
{
	int		card_sum = 0;
	t_cards	*select_card;
	int	card_i = random_range(0, game->card_count - 1);
	select_card = take_card(game, card_i);
	card_sum += card_lister(&game->pcards, select_card);
	if (select_card->name == 'A' && card_sum < 11)
		card_sum += 10;
	card_i = random_range(0, game->card_count - 1);
	select_card = take_card(game, card_i);
	card_sum += card_lister(&game->pcards, select_card);
	if (select_card->name == 'A' && card_sum < 11)
	{
		card_sum += 10;
		game->player_is_a = true;
	}
	printf("\033[0;34mPlayer's cards : \033[0;37m\n");
	print_cards(game->pcards, false);
	return (card_sum);
}

int	player_takes(t_game *game, int player_sum)
{
	int	res;
	t_cards	*select_card;
	int	card_i = random_range(0, game->card_count - 1);
	select_card = take_card(game, card_i);
	res = card_lister(&game->pcards, select_card);
	if (select_card->name == 'A' && player_sum < 11)
	{
		res += 10;
		game->player_is_a = true;
	}
	else if (player_sum + res > 21 && game->player_is_a)
	{
		res -= 10;
		game->player_is_a = false;
	}
	printf("\033[0;34mDealer's cards : \033[0;37m\n");
	print_cards(game->dcards, true);
	printf("\033[0;34mPlayer's cards : \033[0;37m\n");
	print_cards(game->pcards, false);
	return (res);
}