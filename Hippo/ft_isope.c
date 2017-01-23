#include <../includes/libft.h>

int		ft_isope(char c)
{
	if (c == "&")
		return (1);
	else if (c == "<")
		return (1);
	else if (c == ">")
		return (1);
	else if (c == "|")
		return (1);
	else if (c == ";")
		return (1);
	return (0);
}