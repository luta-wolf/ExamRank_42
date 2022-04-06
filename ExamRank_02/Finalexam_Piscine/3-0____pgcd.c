/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-0____pgcd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/01/19 10:23:04 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** 


Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Напишите программу, которая принимает две строки, представляющие два строго 
положительных целых числа, которые помещаются в int.

Представив что это знаменатели двух чисел покажите их наибольший общий знаменатель,
за которым следует новая строка (это всегда строго положительное целое число)

Если количество параметров не равно 2, отобразите новую строку.


Примеры:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e
1$
$> ./pgcd | cat -e
$


** ************************************************************************** **
** ************************************************************************** **

В этом заданиии нас просят написать программу находящую наибольший общий делитель
двух чисел:

https://zen.yandex.ru/media/haknem_shkola/poleznye-sovety-o-tom-kak-legko-sokratit-slojnye-drobi-i-privesti-ih-k-naimenshemu-obscemu-znamenateliu-5f9d76db1f9f73799244c6b6

https://www.google.com/search?q=gcd&oq=gcd&aqs=chrome..69i57j0i1i10j0l6.4213j0j1&client=ubuntu&sourceid=chrome&ie=UTF-8


** ************************************************************************** */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

int		ft_atoi(char *s)
{
	int		num;
	int		sign;

	sign = 1;
	num = 0;
	while (*s == '\t' || *s == '\n' || *s == '\v' || \
			*s == '\f' || *s == '\r' || *s == ' ')
		s++;
	if (*s == '-')
		sign = -1;
	while ((*s == '-') || (*s == '+'))
		s++;
	while (*s && *s >= '0' && *s <= '9')
		num = (num * 10) + ((int)(*(s++)) - '0');
	return (num * sign);
}

int		ft_pgcd(int nbr1, int nbr2)
{
	if ((nbr1 > 0 && nbr2 > 0))
	{
		while (nbr1 != nbr2)
		{
			if (nbr1 > nbr2)
				nbr1 -= nbr2;
			else
				nbr2 -= nbr1;
		}
	}
	return (nbr1);
}

int		main(int argc, char *argv[])
{
	if (argc == 3)
		ft_putnbr(ft_pgcd(ft_atoi(argv[1]), ft_atoi(argv[2])));
	ft_putchar('\n');
	return (0);
}

