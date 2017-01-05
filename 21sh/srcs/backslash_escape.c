#include "../includes/sh.h"

void	backslash_char(t_token *token)
{
	int		pos;
	int		s;
	int		d;

	pos = 0;
	s = 0;
	d = 0;
	while (token->lexeme[pos])
	{
		if (token->lexeme[pos] == '\'')
		{
			s = pos;
			ft_memmove(&(token->lexeme[s]), &(token->lexeme[s + 1]), ft_strlen(token->lexeme) - s);
			while (token->lexeme[pos] != '\'')
				pos++;
			ft_memmove(&(token->lexeme[pos]), &(token->lexeme[pos + 1]), ft_strlen(token->lexeme) - pos);
			pos++;
		}
		else if (token->lexeme[pos] == '\"')
		{
			d = pos;
			ft_memmove(&(token->lexeme[d]), &(token->lexeme[d + 1]), ft_strlen(token->lexeme) - d);
			while (token->lexeme[pos] != '\'')
				pos++;
			ft_memmove(&(token->lexeme[pos]), &(token->lexeme[pos + 1]), ft_strlen(token->lexeme) - pos);
			pos++;
		}
		else if (token->lexeme[pos] == '\\')
		{
			ft_memmove(&(token->lexeme[pos]), &(token->lexeme[pos + 1]), ft_strlen(token->lexeme) - pos);
			pos++;
		}
		pos++;
	}
}
