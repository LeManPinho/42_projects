#include "../includes/21sh.h"

int		main(void)
{
	t_all	*all;

	if (!(all = (t_all *)malloc(sizeof(t_all))))
		return (0);
	while (1)
	{
		ft_putstr("$> ");
		get_next_line(0, &(all->line));
		if ((ft_strcmp(all->line, "\0") == 0) || (ft_isallspace(all->line) == 1))
			;
		else
		{
			all->epured_line = epur_str(all->line);
			analise_line(all->epured_line);
		}
	}
	return (0);
}

void	analise_line(char *line)
{

}

char	*lire_lexeme(t_lexlst *lexlst, char *line, int pos)
{
	if (pos >= ft_strlen(line))
		lexlst->type = END_LINE;
	else
	{
		if (line[pos] == "SYMBOL")
		{
			lexlst->type = "SYMBOL";
			"add line[pos] to lexeme";
			pos++;
		}
		else if (ft_isprint(line[pos]) == 1)
		{
			lexlst->type = WORDS;
			while (ft_isalnum(line[pos]) == 1)
			{
				"add line[pos] to lexlst->lexeme";
				pos++;
			}
		}
	}
}