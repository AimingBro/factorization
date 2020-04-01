/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factorization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjo <jjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 01:11:36 by jjo               #+#    #+#             */
/*   Updated: 2020/04/02 01:11:36 by jjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int						digit_check (char *str);
void					ft_factorization(unsigned int num);
unsigned int			ft_atoi_check(char *str);
unsigned long long		ft_atoull(const char *nptr);

int		main(int argc, char **argv)
{
	unsigned long long	num;
	int					flag;

	if (argc == 2)
	{
		flag = digit_check(argv[1]);
		if(flag == -1)
			printf("올바른 값을 입력하세요.\n");
		else if(flag == -2)
			printf("숫자의 범위를 확인 하세요.(2 ~ 4,294,967,295)\n");
		else
		{
			num = ft_atoull(argv[1]);
			if(num >= 2 && num <= 4294967295)
				ft_factorization(num);
			else
				printf("숫자의 범위를 확인 하세요.(2 ~ 4,294,967,295)\n");
		}
	}
	else
		printf("하나의 인자를 입력하세요.\n");
	return (0);
}

int		digit_check (char *str)
{
	int	i;

	if(str[0] != '+' && (str[0] <= '0' || str[0] > '9'))
		return (-1);
	else
	{
		i = 1;
		while(str[i] != '\0')
		{
			if(str[i] < '0' || str[i] > '9')
			{
				return (-1);
			}
			i++;
		}
		if(i > 10 || (str[0] == '+' && i > 11))
			return (-2);
	}
	return (i);
}

int		is_prime(unsigned int num)
{
	unsigned long long	i;

	if(num < 2)
		return (0);
	i = 2;
	while(i * i <= num)
	{
		if(num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

unsigned long long	ft_atoull(const char *num_str)
{
	unsigned long long	num;
	int				i;

	i = 0;
	if(num_str[i] == '+')
		num_str++;
	num = 0;
	while(num_str[i] >= '0' && num_str[i] <= '9')
		num = (num * 10) + (num_str[i++] - '0');
	return (num);
}

void	ft_factorization(unsigned int num)
{
	unsigned int	i;

	i = 2;
	while (num != 1)
	{
		if(num % i == 0)
		{
			while(num % i == 0)
				num = num / i;
			printf("%u", i);
			if(num != 1)
				printf(" ");
		}
		if(is_prime(num))
		{
			printf("%u", num);
			break;
		}
		i++;
	}
	printf("\n");
}
