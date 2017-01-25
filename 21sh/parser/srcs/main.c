#include "../includes/parse.h"

int		start_parse(t_token *token)
{
	t_tree	*tree;

	tree = create_node();
	parse(tree, token);
	free_tree(tree);
}


char	*get_token(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		if (tmp->type = SEMICOLON)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

t_token	*copy_token_left(t_token *begin, t_token *ope)
{
	t_token	*left;
	t_token	*tmp;
	t_token	*begin_left;

	left = init_token();
	tmp = begin;
	begin_left = left;
	while (tmp->type != ope->type)
	{
		left->type = tmp->type;
		left->content = ft_strdup(tmp->lexeme);
		left->next = init_token();
		left = left->next;
		tmp = tmp->next;
	}
	return (begin_left);
}

t_token	*copy_token_right(t_token *ope)
{
	t_token	*right;
	t_token	*tmp;
	t_token	*begin_right;

	right = init_token();
	begin_right = right;
	tmp = ope->next;
	while (tmp)
	{
		right->type = tmp->type;
		right->content = ft_strdup(tmp->lexeme);
		right->next = init_token();
		right = right->next;
		tmp = tmp->next;
	}
	return (begin_right);
}