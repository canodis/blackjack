#include "../include/blackjack.h"

bool	charcmp(char a, char b)
{
	if (a == b)
		return true;
	return false;
}

void	delete_card(t_cards **lst, t_cards *card)
{
	t_cards	*tmp;

	tmp = *lst;
	while(tmp->next)
	{
		if (charcmp(tmp->name, card->name))
		{
			tmp->prev->next = tmp->next;
			tmp->next = NULL;
			tmp->prev = NULL;
			free(tmp);
			break;
		}
		tmp = tmp->next;
	}
}

t_cards	*card_dup(t_cards *card)
{
	t_cards	*new = malloc(sizeof(t_cards));
	new->name = card->name;
	new->value = card->value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_cards	*take_card(t_game *game, int card_i)
{
	t_cards	*tmp = game->cards;
	//t_cards	*res;
	for (int i = 0; i < card_i && tmp; i++)
		tmp = tmp->next;
	game->cards--;
	//res = card_dup(tmp);
	//delete_card(&game->cards, tmp);
	return (tmp);
}

void	dealer(t_game *game)
{
	t_cards	*select_card;
	int	card_i = random_range(0, game->card_count - 1);
	select_card = take_card(game, card_i);
	printf("Kurpiyerin karti : %c\n", select_card->name);
	//free(select_card);
}

void	start_game(t_game *game)
{
	char	*input;
	while(1)
	{
		dealer(game);
		printf("\033[0;37mKart iste : 1\nDur : 2\n");
		input = readline(">");
		printf("input : %s\n",input);
		if (!strcmp(input, "1"))
			printf("a : 1\n");
		else if (!strcmp(input, "2"))
			printf("b : 2\n");
		else
			printf("\033[0;31mLutfen gecerli bir deger giriniz !\n\033[0;37m");

	}
}