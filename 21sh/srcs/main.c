#include "../includes/sh.h"

int		main(void)
{
	t_all	*all;

	if (!(all = (t_all *)malloc(sizeof(t_all))))
		return (0);
	while (1)
	{
		ft_putstr("$> ");
		get_next_line(0, &(all->line));
		if ((ft_strcmp(all->line, "\0") == 0) || (isallspace(all->line) == 1))
			;
		else
		{
			analise_line(all);
			print_tokens(all->token);
		}
	}
	return (0);
}

void	analise_line(t_all *all)
{
	int			pos;

	all->token = malloc(sizeof(t_token));
	pos = 0;
	while (all->line[pos])
	{
		pos = lire_lexeme(all->token, all->line , pos);
		all->token = all->token->next;
	}
}

int		lire_lexeme(t_token *token, char *line, int pos)
{
	int		i;

	i = 0;
	if (line[pos] == '\"')
	{
		token->type = SQUOTE;
		i = pos + 1;
		while (line[pos] != '\"')
			pos++;
		add_lexeme(token, line, pos, i);
	}
	else if (line[pos] == '\'')
	{
		token->type = DQUOTE;
		i = pos + 1;
		while (line[pos] != '\'')
			pos++;
		add_lexeme(token, line, pos, i);
	}		
	else if (ft_isprintnotope(line[pos]) == 1)
	{
		token->type = WORDS;
		i = pos;
		while (ft_isprintnotope(line[pos]) == 1)
			pos++;
		add_lexeme(token, line, pos, i);
	}
	else if (ft_isope(line[pos]) >= 1)
	{
		check_ope(token, line, pos, i);
	}
	pos++;
	return (pos);
}

void	add_lexeme(t_token *token, char *line, int pos, int i)
{
	token->lexeme = ft_strndup(&(line[i]), pos - i);
}

int        ft_isope(char c)
{
    if (c == '&')
        return (1);
    else if (c == '<')
        return (2);
    else if (c == '>')
        return (3);
    else if (c == '|')
        return (4);
    else if (c == ';')
        return (5);
    return (0);
}
