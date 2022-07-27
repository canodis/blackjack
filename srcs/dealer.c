#include "../include/blackjack.h"

int	dealer_first(t_game *game)
{
	int		card_sum = 0;
	t_cards	*select_card;
	int	card_i = random_range(0, game->card_count - 1);
	select_card = take_card(game, card_i);
	card_sum += card_lister(&game->dcards, select_card);
	if (select_card->name == 'A' && card_sum < 11)
		card_sum += 10;
	card_i = random_range(0, game->card_count - 1);
	select_card = take_card(game, card_i);
	card_sum += card_lister(&game->dcards, select_card);
	if (select_card->name == 'A' && card_sum < 11)
	{
		card_sum += 10;
		game->dealer_is_a = true;
	}
	printf("\033[0;34mDealer's cards : \033[0;37m\n");
	print_cards(game->dcards, true);
	return (card_sum);
}

int		dealer_takes(t_game *game, int dealer_sum)
{
	int	res;
	t_cards	*select_card;
	int	card_i = random_range(0, game->card_count - 1);
	select_card = take_card(game, card_i);
	res = card_lister(&game->dcards, select_card);
	if (select_card->name == 'A' && dealer_sum < 11)
	{
		res += 10;
		game->dealer_is_a = true;
	}
	else if (dealer_sum + res > 21 && game->dealer_is_a)
	{
		res -= 10;
		game->dealer_is_a = false;
	}
	return (res);
}

void	dealers_turn(t_game *game, int dealer_sum, int player_sum)
{
	printf("\033[0;34mDealer's cards : \033[0;37m\n");
	print_cards(game->dcards, false);
	printf("\033[0;34mPlayer's cards : \033[0;37m\n");
	print_cards(game->pcards, false);
	sleep(2);
	while (dealer_sum < 17 && player_sum > dealer_sum)
	{
		dealer_sum += dealer_takes(game, dealer_sum);
		printf("\033[0;34mDealer's cards : \033[0;37m\n");
		print_cards(game->dcards, false);
		printf("\033[0;34mPlayer's cards : \033[0;37m\n");
		print_cards(game->pcards, false);
		sleep(1);
	}
	if (dealer_sum > 21 || dealer_sum < player_sum)
		printf("\nYOU WIN\n");
	else if (dealer_sum == player_sum)
		printf("\nDRAW\n");
	else
		printf("\nYOU ARE A FAKING LOSER\n");
	readline("Devam etmek icin ENTER'a basiniz...");
}