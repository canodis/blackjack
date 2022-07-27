#include "../include/blackjack.h"

char colors[7][10] =
{
	{"\033[0;31m"},
	{"\033[0;32m"},
	{"\033[0;33m"},
	{"\033[0;34m"},
	{"\033[0;35m"},
	{"\033[0;36m"},
	{"\033[0;37m"}
};

void	delete_card(t_cards **lst, t_cards *card)
{
	t_cards	*tmp;

	tmp = *lst;
	while(tmp->next)
	{
		if (charcmp(tmp->name, card->name))
		{
			if (tmp->prev)
			{
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
			}
			else
			{
				(*lst)->next->prev = NULL;
				*lst = tmp->next;
			}
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
	t_cards	*res;
	for (int i = 0; i < card_i && tmp; i++)
		tmp = tmp->next;
	game->card_count--;
	res = card_dup(tmp);
	delete_card(&game->cards, tmp);
	return (res);
}

void	free_cards(t_cards **cards)
{
	if (*cards && (*cards)->next)
		(*cards) = (*cards)->next;
	while (*cards)
	{
		free((*cards)->prev);
		(*cards)->prev = NULL;
		*cards = (*cards)->next;
	}
}

void	print_cards(t_cards *cards, bool isPrivate)
{
	printf("\n");
	char	n;
	int		color_i = random_range(0,6);
	int		cards_len = 0;
	t_cards	*tmp = cards;
	while (tmp)
	{
		cards_len++;
		tmp = tmp->next;
	}
	for (int i = 0; i < 6; i++)
	{
		printf("%s*  \033[0;37m",colors[color_i]);
		tmp = cards;
		for (int j = 0; j < cards_len; j++)
		{
			if (i == 0)
				printf(" _____   ");
			else if (i == 1)
			{
				if (isPrivate && j == 1)
					printf("|  .  |  ");
				else
					printf("| \033[0;32m%c\033[0;37m.  |  ", tmp->name);
				tmp = tmp->next;
			}
			else if (i == 2)
				printf("| /.\\ |  ");
			else if (i == 3)
				printf("|(_._)|  ");
			else if (i == 4)
				printf("|  |  |  ");
			else
			{
				if (isPrivate && j == 1)
					printf("|____ |  ");
				else
					printf("|____\033[0;32m%c\033[0;37m|  ", tmp->name);
				tmp = tmp->next;
			}
		}
		printf("%s*  \033[0;37m",colors[color_i]);
		printf("\n");
	}
	printf("\n");
}

int	card_lister(t_cards **lst, t_cards *new)
{
	ft_lstadd_back(lst, new);
	return (new->value);
}