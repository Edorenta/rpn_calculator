/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 12:54:26 by exam              #+#    #+#             */
/*   Updated: 2018/03/20 13:54:04 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int				not_valid(char *s)
{
	int nums;
	int ops;

	nums = 0;
	ops = 0;
	while (*s)
	{
		if (ft_isoperator(*s)) ops++;
		else if (ft_isdigit(*s)) nums++;
		else if (!ft_isoperator(*s) && !ft_isdigit(*s) && !ft_isspace(*s))
			return (1);
		s++;
	}
	if (ops != (nums - 1))
		return (1);
	return (0);
}

static int				evaluate(int x, int y, char op)
{
	printf("%d %c %d\n", x, op, y);
		 if (op == '+') return (x + y);
	else if (op == '-') return (x - y);
	else if (op == '*') return (x * y);
	else if (op == '/') return (x / y);
	else if (op == '%') return (x % y);
	return (0);
}

int		main(int ac, char **av)
{
	int		i = 0, j = 0;
	int		mkop = 0, mk1 = 0, mk2 = 0;
	char 	operand1[5] = {0};
	char 	operand2[5] = {0};
	char	op = 0;
	char	*s = av[1];
	int		res = 0;
	if (ac != 2 || not_valid(av[1])){printf("Error\n"); return (0);}
	while (s[i])
	{
		if (ft_isoperator(s[i]))
		{
			op = s[i];
			mkop = i;
			while (ft_isspace(s[--i]));
			while (ft_isdigit(s[--i]));
			mk1 = i;
			j = -1;
			while (ft_isdigit(s[++i]))
				operand2[++j] = s[i];
			i = mk1;
			while (ft_isspace(s[--i]));
			while (ft_isdigit(s[--i]));
			j = -1;
			mk2 = i;
			while (ft_isdigit(s[++i]))
				operand1[++j] = s[i];
			res = evaluate(atoi(operand1), atoi(operand2), op);
			while (mk2 <= mkop)
			{
				s[mk2] = 32; mk2++;
			}
			i = mkop;
			break;
		}
		i++;
	}
	while (s[i])
	{
		if (ft_isoperator(s[i]))
		{
			op = s[i];
			mkop = i;
			while (ft_isspace(s[--i]));
			while (ft_isdigit(s[--i]));
			j = -1;
			mk2 = i;
			while (ft_isdigit(s[++i]))
				operand1[++j] = s[i];
			res = evaluate(res, atoi(operand1), op);
			while (mk2 <= mkop)
			{
				s[mk2] = 32; mk2++;
			}
			i = mkop;
		}
		i++;
	}
	printf("%d\n", res);
	return (0);
}
