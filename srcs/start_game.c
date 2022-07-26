#include "../include/blackjack.h"

void	stats()
{
	printf("\n\nWins : %i\n\nLoses : %i\n\n", win, lose);
	readline("Press Enter...");
}

void	play(t_game *game, int player_sum, int dealer_sum)
{
	char *input;
	bool	is_playing = true;
	while (is_playing)
	{
		printf("\033[0;37mTake card : 1\nStop : 2\nExit : 3\nStats : 4\n");
		input = readline(">");
		if (!strcmp(input, "1"))
			player_sum = player_takes(game, player_sum ,dealer_sum, &is_playing);
		else if (!strcmp(input, "2"))
		{
			is_playing = false;
			dealers_turn(game, dealer_sum, player_sum);
		}
		else if (!strcmp(input,"3"))
		{
			free_cards(&game->cards);
			exit(0);
		}
		else if (!strcmp(input,"4"))
			stats();
		else
			printf("\033[0;31mPlease enter a valid value !\n\033[0;37m");
		if (player_sum > 21)
		{
			printf("\n\033[0;31mYOU LOSE\033[0;37m\n");
			lose++;
			sleep(1);
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
		if(game->card_count < 10)
		{
			printf("\n\033[0;31mDestelerde kart kalmadi deste kariliyor...\033[0;37m\n");
			init_cards(&game->cards);
			game->card_count += 104;
			sleep(3);
		}
		game->player_is_a = false;
		game->dealer_is_a = false;
		dealer_sum = dealer_first(game);
		player_sum = player_first(game);
		if (dealer_sum == 21)
		{
			dealer_win(game, player_sum, dealer_sum);
			continue;
		}
		else if (player_sum == 21)
		{
			player_win(game, player_sum, dealer_sum);
			continue;
		}
		play(game, player_sum, dealer_sum);
		free_cards(&game->dcards);
		free_cards(&game->pcards);
	}
}