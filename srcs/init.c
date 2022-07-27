#include "../include/blackjack.h"

void	ft_lstadd_back(t_cards **lst, t_cards *new)
{
	t_cards	*last_elem;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_elem = *lst;
	while(last_elem->next != NULL)
		last_elem = last_elem->next;
	last_elem->next = new;
	new->prev = last_elem;
}

t_cards	*new_card(int value, char name)
{
	t_cards	*new = malloc(sizeof(t_cards));
	new->name = name;
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	init_cards(t_cards	**all_cards)
{
	for (int i = 0; i < 8; i++)
		ft_lstadd_back(all_cards, new_card(1, 'A'));
	for(int i = 1; i < 9; i++)
	{
		for (int j = 0; j < 8; j++)
			ft_lstadd_back(all_cards, new_card(i + 1, i + 49));
	}
	for(int i = 0; i < 8; i++)
		ft_lstadd_back(all_cards, new_card(10, 't'));
	for(int i = 0; i < 8; i++)
		ft_lstadd_back(all_cards, new_card(10, 'j'));
	for(int i = 0; i < 8; i++)
		ft_lstadd_back(all_cards, new_card(10, 'q'));
	for(int i = 0; i < 8; i++)
		ft_lstadd_back(all_cards, new_card(10, 'k'));
}

void	init_all(t_game *game)
{
	game->cards = NULL;
	game->pcards = NULL;
	game->dcards = NULL;
	game->player_is_a = false;
	game->dealer_is_a = false;
	game->card_count = 104;
	init_cards(&game->cards);
}