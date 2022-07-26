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
}	t_game;

void	free_game(t_game *game);
void	init_all(t_game *game);
void	start_game(t_game *game);
int		random_range(int start, int end);

#endif