#ifndef BLACKJACK_H
# define BLACKJACK_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <time.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_cards
{
	int				value;
	char			name;
	struct s_cards	*next;
	struct s_cards	*prev;
}	t_cards;


typedef struct s_blackjack
{
	int		card_count;
	t_cards	*cards;
	t_cards	*pcards;
	t_cards	*dcards;
	bool	player_is_a;
	bool	dealer_is_a;
}	t_game;

void	free_game(t_game *game);
void	init_all(t_game *game);
void	start_game(t_game *game);
int		random_range(int start, int end);

t_cards	*take_card(t_game *game, int card_i);
void	print_cards(t_cards *cards, bool isPrivate);
void	free_cards(t_cards **cards);
int		card_lister(t_cards **lst, t_cards *new);
void	delete_card(t_cards **lst, t_cards *card);


bool	charcmp(char a, char b);
void	ft_lstadd_back(t_cards **lst, t_cards *new);
t_cards	*new_card(int value, char name);

int		player_first(t_game *game);
int		player_takes(t_game *game, int player_sum, int dealer_sum, bool *is_playing);
void	player_win(t_game *game, int player_sum, int dealer_sum);

int		dealer_first(t_game *game);
void	dealers_turn(t_game *game, int dealer_sum, int player_sum);
void	dealer_win(t_game *game, int player_sum, int dealer_sum);

void	init_cards(t_cards	**all_cards);


#endif