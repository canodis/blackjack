#include "../include/blackjack.h"

int	random_range(int start, int end)
{
	srand(time(0));
	return ((rand() % (end - start + 1)) + start);
}