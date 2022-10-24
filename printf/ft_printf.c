/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:42:08 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/24 07:32:58 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static ssize_t	ft_putnbr_base(ssize_t nbr, char *base)
{
	ssize_t	base_len;
	ssize_t	nbr_len;
	ssize_t	power_index;

	base_len = ft_strlen(base);
	nbr_len = 0;
	power_index = 1;
	if (nbr < 0)
	{
		nbr_len += write(1, "-", 1);
		nbr *= -1;
	}
	while (nbr >= base_len * power_index)
		power_index *= base_len;
	while (power_index)
	{
		nbr_len += write(1, &base[nbr / power_index % base_len], 1);
		nbr %= power_index;
		power_index /= base_len;
	}
	return (nbr_len);
}

static void	ft_proc_per(const char **format, ssize_t *printed, va_list *ap)
{
	(*format)++;
	if (**format == 'c')
		*printed += ft_put_char((char)va_arg(*ap, int));
	else if (**format == 's')
		*printed += ft_put_str(va_arg(*ap, char *));
	else if (**format == 'p')
		*printed += ft_put_ptr(va_arg(*ap, uintptr_t));
	else if (**format == 'd' || **format == 'i')
		*printed += ft_putnbr_base((ssize_t)va_arg(*ap, int), DEC);
	else if (**format == 'u')
		*printed += ft_putnbr_base((ssize_t)va_arg(*ap, unsigned int), DEC);
	else if (**format == 'x')
		*printed += ft_putnbr_base((ssize_t)va_arg(*ap, unsigned int),
				HEX_LOWER);
	else if (**format == 'X')
		*printed += ft_putnbr_base((ssize_t)va_arg(*ap, unsigned int),
			HEX_UPPER);
	else if (**format == '%')
		*printed += write(1, "%", 1);
	(*format)++;
}

static void	ft_print_str(const char **format, ssize_t *printed)
{
	const char	*start;

	start = *format;
	while (**format != '%' && **format)
		(*format)++;
	*printed += write(1, start, *format - start);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	ssize_t	printed;

	printed = 0;
	va_start(ap, format);
	while (*format && printed < INT_MAX)
	{
		if (*format != '%')
			ft_print_str(&format, &printed);
		else
			ft_proc_per(&format, &printed, &ap);
	}
	va_end(ap);
	if (printed >= INT_MAX)
		return (-1);
	return (printed);
}

// #include "ft_printf.h"
// #include "libft/libft.h"
// #include <stdio.h>

// int	main(void)
// {
// 	int	i;

// 	i = 0;
// 	printf("#c\n");
// 	ft_printf("%c\t%c\n", 'c', '%');
// 	printf("%c\t%c\n\n", 'c', '%');

// 	printf("#str\n");
// 	ft_printf("%s\t%s\t%s\n", "42Tokyo", "", NULL);
// 	printf("%s\t%s\t%s\n\n", "42Tokyo", "", NULL);

// 	printf("#int\n");
// 	ft_printf("%d\t%d\t%d\t%d\n", i, 100, INT_MAX, INT_MIN);
// 	printf("%d\t%d\t%d\t%d\n\n", i, 100, INT_MAX, INT_MIN);

// 	printf("#uint\n");
// 	ft_printf("%u\t%u\t%u\n", i, 100, UINT_MAX);
// 	printf("%u\t%u\t%u\n\n", i, 100, UINT_MAX);

// 	printf("#hex\n");
// 	printf("%x\t%x\t%x\n", i, 255, UINT_MAX);
// 	printf("%x\t%x\t%x\n\n", i, 255, UINT_MAX);

// 	printf("#HEX\n");
// 	printf("%x\t%X\t%X\n", i, 255, UINT_MAX);
// 	printf("%x\t%X\t%X\n\n", i, 255, UINT_MAX);

// 	printf("#ptr\n");
// 	ft_printf("%p\t%p\t%p\t%p\n", &i, SIZE_MAX, NULL, 0);
// 	printf("%p\t%p\t%p\t%p\n\n", &i, SIZE_MAX, NULL, 0);

// 	printf("#percent\n");
// 	ft_printf("%%\n");
// 	printf("%%\n\n");

// 	printf("#mix\n");
// 	ft_printf("abc\t%c\t%s\t%d\t%i\t%u\t%x\t%X\t%p\t%%\n", 'd', "def", 1, 10,
// 			100, 100, 100, &i);
// 	printf("abc\t%c\t%s\t%d\t%i\t%u\t%x\t%X\t%p\t%%\n\n", 'd', "def", 1, 10,
// 			100, 100, 100, &i);

// 	printf("#return\n");
// 	printf("%d\n", ft_printf("abc\t%c\t%s\t%d\t%i\t%u\t%x\t%X\t%p\t%%\n", 'c',
// 				"str", 1, 10, 100, 255, 255, &i));
// 	printf("%d\n", printf("abc\t%c\t%s\t%d\t%i\t%u\t%x\t%X\t%p\t%%\n", 'c',
// 				"str", 1, 10, 100, 255, 255, &i));
// 	return (0);
// }
