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
			while (token->lexeme[pos] != '\"')
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

int		quote_in_word(char *line, int pos)
{
	if (line[pos] == '\"')
	{
		pos++;
		while (line[pos] != '\"')
			pos++;
		pos++;
	}
	else if (line[pos] == '\'')
	{
		pos++;
		while (line[pos] != '\'')
			pos++;
		pos++;
	}
	return (pos);
}

int		get_lexeme_pos(char *line, int pos)
{
	int		exit;

	exit = 0;
	while (!exit)
	{
		while (ft_isprintnotope(line[pos]) == 1)
			pos++;
		pos = quote_in_word(line, pos);
		if (ft_isprintnotope(line[pos]) == 0)
			exit = 1;
	}
	return (pos);
}
