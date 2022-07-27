#include "../include/blackjack.h"

void	dealer_win(t_game *game, int player_sum, int dealer_sum)
{
	printf("\033[0;34mDealer's cards : \033[0;37m  %i  \n", dealer_sum);
	print_cards(game->dcards, false);
	printf("\033[0;34mPlayer's cards : \033[0;37m  %i  \n", player_sum);
	print_cards(game->pcards, false);
	sleep(2);
	if (player_sum == dealer_sum)
		printf("\nDRAW\n");
	else
		printf("\nYOU LOSE\n");
	free_cards(&game->dcards);
	free_cards(&game->pcards);
}

void	player_win(t_game *game, int player_sum, int dealer_sum)
{
	printf("\033[0;34mDealer's cards : \033[0;37m  %i  \n", dealer_sum);
	print_cards(game->dcards, false);
	printf("\033[0;34mPlayer's cards : \033[0;37m  %i  \n", player_sum);
	print_cards(game->pcards, false);
	sleep(2);
	if (player_sum == dealer_sum)
		printf("\nDRAW\n");
	else
		dealers_turn(game, dealer_sum, player_sum);
	free_cards(&game->dcards);
	free_cards(&game->pcards);
}

void	play(t_game *game, int player_sum, int dealer_sum)
{
	char *input;
	bool	is_playing = true;
	while (is_playing)
	{
		input = readline(">");
		if (!strcmp(input, "1"))
			player_sum = player_takes(game, player_sum ,dealer_sum, &is_playing);
		else if (!strcmp(input, "2"))
		{
			is_playing = false;
			dealers_turn(game, dealer_sum, player_sum);
		}
		else if (!strcmp(input,"3"))
			exit(0);
		else
			printf("\033[0;31mPlease enter a valid value !\n\033[0;37m");
		if (player_sum > 21)
		{
			printf("You are loser\n");
			is_playing = false;
		}
		free(input);
	}
}

void	start_game(t_game *game)
{
	int		dealer_sum;
	int		player_sum;
	while(1)
	{
		game->player_is_a = false;
		game->dealer_is_a = false;
		dealer_sum = dealer_first(game);
		player_sum = player_first(game);
		if (dealer_sum == 21)
		{
			dealer_win(game, dealer_sum, player_sum);
			continue;
		}
		else if (player_sum == 21)
		{
			player_win(game, player_sum, dealer_sum);
			continue;
		}
		printf("\033[0;37mTake card : 1\nStop : 2\nExit : 3\n");
		play(game, player_sum, dealer_sum);
		free_cards(&game->dcards);
		free_cards(&game->pcards);
	}
}