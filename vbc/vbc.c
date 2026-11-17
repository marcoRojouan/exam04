#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void unexpected(char c)
{
	if (c)
		printf("Invalid token '%c'\n", c);
	else 
		printf("Invalid token\n");
	return;
}

void expect(char c, char **s)
{
	if (!accept(c, s))
		unexpected(**s);
}

int accept(char c, char **s)
{
	if (c == **s)
	{
		(**s)++;
		return 1;
	}
	return 0;
}


static int parsing_factor(char **s)
{
	if (isdigit((unsigned char)**s))
	{
		int val = **s - '0';
		(**s)++;
		return val;
	}
	if (accept('(', s))
	{
		int val = parse_add(s);
		expect(')', s);
		return (val);
	}
	unexpected(**s);
	return 0;
}

static int parsing_multi(char **s)
{
	int left = parsing_factor(s);

	if (accept('+', s))
	{
		int right = parsing_factor(s);
		left += right;
	}
	return left;
}

static int parsing_add(char **s)
{
	int left = parsing_multi(s);

	if (accept('+', s))
	{
		int right = parsing_multi(s);
		left += right;
	}
	return left;
}

static int	parsing(char *s)
{
	char	*p = s;
	int		res = parsing_add(*p);

	if (*p)
		unexpected(*p);
	return res;
}

int main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	int result = parsing(av[1]);
	printf("%d", result);
	return 0;
}