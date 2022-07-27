#include "../include/blackjack.h"

void	play(t_game *game, bool is_playing, int player_sum, int dealer_sum)
{
	char *input;
	while (is_playing)
	{
		input = readline(">");
		if (!strcmp(input, "1"))
			player_sum += player_takes(game, player_sum);
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
	bool	is_playing;
	while(1)
	{
		is_playing = true;
		game->player_is_a = false;
		game->dealer_is_a = false;
		dealer_sum = dealer_first(game);
		player_sum = player_first(game);
		//printf("\ndealer : %i\nplayer : %i\n",dealer_sum, player_sum);
		printf("\033[0;37mTake card : 1\nStop : 2\n");
		play(game, is_playing, player_sum, dealer_sum);
		free_cards(&game->dcards);
		free_cards(&game->pcards);
	}
}