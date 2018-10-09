/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 18:13:49 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/07 01:09:30 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf.h"

int		ft_printf(const char *fmt, ...)
{
	va_list args;
	va_list args2;
	t_flags *flags;
	t_list *lst;
	char buf[4096];
	char *arr;
	int len;
	int i;

	i = 0;
	len = 0;
	va_start(args, fmt);
	lst = NULL;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			flags = init_list();
			va_copy(args2, args);
			buf[i] = '\0';
			i = 0;
			fmt++;
			parse_everything(&flags, &fmt);
			append(&lst, buf, i);
			arr = ft_strdup(choose_conversion(flags, fmt, args));
			flags->len = (int)ft_strlen(arr);
			flags->len_total = handle_flags(&lst, flags, args2);
			handle_flags2(&lst, flags, &arr, fmt);
			value_zero(&arr, &flags);
			value_negative(&arr, &lst, &flags);
			append(&lst, arr, flags->len);
			ft_strdel(&arr);
		}
		else
		{
			buf[i] = *fmt;
			i++;
		}
		fmt++;
		print_list(lst);
		len += list_size(lst);
		delete_list(&lst);
	}
	buf[i] = '\0';
	append(&lst, buf, i);
	len += list_size(lst);
	print_list(lst);
	va_end(args);
	return (len);
}

// int main()
// {


// //	ft_printf("%.2s is a string\n", "this");
// //	printf("%.2s is a string\n", "this");
// //	ft_printf("%5.2s is a string\n", "this");
// //	printf("%5.2s is a string\n", "this");

// //
// //	ft_printf("%-5.2s is a string\n", "this");
// //	printf("%-5.2s is a string\n", "this");

// //	ft_printf("%-10s is a string\n", "");
// //	printf("%-10s is a string\n", "");

// //   ft_printf("%10s is a string\n", "");
// //   printf("%10s is a string\n", "");

//   //   ft_printf("'%-10.5o'\n", 2500);
//   // printf("'%-10.5o'\n", 2500);


//   // ft_printf("%0+5d\n", 42);
//   // printf("%0+5d\n", 42);

// 	 //  ft_printf("%03.2d\n", 1);
//   // printf("%03.2d\n", 1);

//   //   ft_printf("%010x\n", 542);
//   // printf("%010x\n", 542);

//   // ft_printf("'%03.2d'\n", 0);
//   // printf("'%03.2d'\n", 0);

//   // ft_printf("%#x\n", 0);
//   // printf("%#x\n", 0);

//   //  ft_printf("'@moulitest: %#.x %#.0x'\n", 0, 0);
//   // printf("'@moulitest: %#.x %#.0x'\n", 0, 0);
//   // ft_printf("'@moulitest: %5.x %5.0x'\n", 0, 0);
//   // printf("'@moulitest: %5.x %5.0x'\n", 0, 0);

//   // ft_printf("'%#8x'\n", 42);
//   // printf("'%#8x'\n", 42);

// //  printf("@moulitest: %#.x %#.0x\n", 0, 0);
// //   ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
// //
// //	ft_printf("test\n");
// //	printf("test\n");

// //	printf("%lld\n", -9223372036854775808);
// //	ft_printf("%lld\n", -9223372036854775808);
// //
// //	char c = 0;
// //	printf("%c\n", c);
// //	ft_printf("%c\n", c);
// //
// //	ft_printf("'%-5%'\n");
// //	printf("'%-5%'\n");
// //
// //	ft_printf("%5.2s is a string\n", "this");
// //	printf("%5.2s is a string\n", "this");

// //	ft_printf("%05d\n", -42);
// //	printf("%05d\n", -42);
// //
// //
// //	ft_printf("%d %d %d\n", 1, -2, 33);
// //	printf("%d %d %d\n", 1, -2, 33);
// //
// //	ft_printf("'@moulitest: %.d %.0d'\n", 0, 0);
// //	printf("'@moulitest: %.d %.0d'\n", 0, 0);

// //	ft_printf("'@moulitest: %5.x %5.0x'\n", 0, 0);
// //	printf("'@moulitest: %5.o %5.0o'\n", 0, 0);

// //ft_printf("%c\n", NULL);
// }

// int		main()
// {
// 		 printf("%c\n", 0);
// 		 ft_printf("%c\n", 0);
// 	 ft_printf("%c\n", 0);
//   	 ft_printf("%-05o\n", 2500);
// 	 printf("%-05o\n", 2500);

// 	 ft_printf("%+d\n", 0);
// 	 printf("%+d\n", 0);

//   	 ft_printf("% +d\n", -42);
//   	 printf("% +d\n", -42);

// 	 ft_printf("%05d\n", -42);
//  	// printf("%05d\n", -42);

//    ft_printf("'%-10.5d'\n", 4242);
//    printf("'%-10.5d'\n", 4242);

//    ft_printf("%U\n", 18700000000);
//    printf("%U\n", 18700000000);

//    ft_printf("%hU\n", 4294967296);
//    printf("%hU\n", 4294967296);

//   ft_printf("%#x\n", 42);
//   printf("%#x\n", 42);

// 	 ft_printf("%#08x\n", 42);
// 	 printf("%#08x\n", 42);

// 	 ft_printf("%0+5d\n", -42);
// 	 printf("%0+5d\n", -42);

// 	 ft_printf("%05d\n", -42);
// 	 printf("%05d\n", -42);

// 	 ft_printf("%5.2s is a string\n", "this");
// 	 printf("%5.2s is a string\n", "this");

// 	 ft_printf("%.2s is a string\n", "this");
//   	printf("%.2s is a string\n", "this");

//   	  ft_printf("%5.2s is a string\n", "");
//   printf("%5.2s is a string\n", "");



// }

 
 // int		main()
 // {
 // 	printf("\n----------WIDTH1--------\n");
 // 	printf("%10d\n", 15);
 // 	ft_printf("%10d\n", 15);

 // 	printf("\n----------WIDTH2--------\n");
 // 	printf("%10d\n", 255);
 // 	ft_printf("%10d\n", 255);

 // 	printf("\n----------WIDTH2--------\n");
 // 	printf("%#10x\n", 255);
 // 	ft_printf("%#10x\n", 255);

 // 	printf("%-15x\n", 542);
 // 	ft_printf("%-15x\n", 542);

 // 	ft_printf("%#x\n", 42);
 // 	printf("%#x\n", 42);
 // }

// int 	main()
// {
// //	int i = printf("hey\n");
// //	int i2 = ft_printf("hey\n");
// //	printf("%d: %d\n", i, i2);
// //
// //	ft_printf("tst: %d\n", -55555555555555);
// 	// printf("value: %d\n", printf("salut %ld\n", -55555555555));
// 	//  printf("value: %d\n", ft_printf("salut %ld\n", -55555555555));

// 	printf("%%\n");
// 	ft_printf("%%\n");
// //	 printf("%ld\n", -55555555555);

// }

// int main()
// {
// //	unsigned int number = 5;
// //	char c = -16;
// //	signed int a = -255;
// //	// ft_printf("\nTEST\n");
// //	// ft_printf("tst: %d\n", -55555555555555);
// //	// printf("%d\n", -55555555555555);
// //	// ft_printf("%ld\n", -55555555555);
// //	// printf("%ld\n", -55555555555);
// //	// printf("%lo\n", 55555555555555);
// //	// ft_printf("%lo\n", 55555555555555);
// //	// printf("%jo\n", 555555555555555);
// //	// ft_printf("%jo\n", 555555555555555);
// //	// printf("%lld\n", 55555555555555);
// //	// ft_printf("%lld\n", 55555555555555);
// //	// printf("%hd\n", -55555555555555);
// //	// ft_printf("%hd\n", -55555555555555);
// //	// printf("%+d %d\n", -17, 17);
// //	// ft_printf("%+d %d\n", 17, 17);
// //	// ft_printf("%#x %+d %d %s\n", 17, 17, 1, "Salut");
// //	// printf("%#x %+d %d %s\n", 17, 17, 1, "Salut");
// //
// 	ft_printf("%#x %+d %d %s\n", 17, 17, 1, "Salut");
// 	printf("%#x %+d %d %s\n", 17, 17, 1, "Salut");

// 	ft_printf("%#10x %+d %d %s\n", 17, 17, 1, "Salut");
// 	printf("%#10x %+d %d %s\n", 17, 17, 1, "Salut");

// //	// ft_printf("Salut %#x %+d %d %s\n", 17, 17, 1, "Salut");
// //	// printf("Salut %#x %+d %d %s\n", 17, 17, 1, "Salut");
// //
// 	// ft_printf("\nSalut: %s: %+d: %#o %#X %#x %d %u %s\n", "salut", 150, -654, 147, 147, 78954, -987, "salit");
// 	// printf("Salut: %s: %+d: %#o %#X %#x %d %u %s\n", "salut", 150, -654, 147, 147, 78954, -987, "salit");
// //
// //	// ft_printf("%#o  % d %#x\n", 355, -17, 18);
// //	// printf("%#o  % d %#x\n", 355, -17, 18);
// //
// //	// printf("REAL: %+010d\n", 17);
// //	// ft_printf("MINE: %+010d\n", 17);
// //
// //	printf("\n--------TEST1------\n");
// //	ft_printf("%10.10d\n", 17);
// //	printf("%10.10d\n", 17);
// //
// //	printf("\n--------TEST2------\n");
// //	ft_printf("%5.10x\n", 98798);
// //	printf("%5.10x\n", 98798);
// //
// //		printf("\n--------TEST3------\n");
// //	ft_printf("%5.10s\n", "salit");
// //	printf("%5.10s\n", "salit");
// //
// ////	printf("\n--------TEST1------\n");
// ////	printf("%17d\n", 17);
// ////	ft_printf("%17d\n", 17);
// ////
// ////	printf("\n--------TEST2------\n");
// ////	printf("%3d\n", 17);
// ////	ft_printf("%3d\n", 17);
// ////
// ////	printf("\n--------TEST3------\n");
// ////	ft_printf("%3d: %#o: %3s\n", 17, 12, "salut");
// ////	printf("%3d: %#o: %3s\n", 17, 12, "salut");
// ////
// ////	printf("\n--------TEST4------\n");
// ////	ft_printf("%3s\n", "salut");
// ////	printf("%3s\n", "salut");
// ////
// ////	printf("\n--------TEST5------\n");
// ////	ft_printf("%7d\n", 77157);
// ////	printf("%7d\n", 77157);
// ////
// ////	printf("\n--------TEST6------\n");
// ////	ft_printf("%7d %17s %12s\n", 77157, "sadsasda", "sdasd");
// ////	printf("%7d %17s %12s\n", 77157, "sadsasda", "sdasd");
// ////
// ////	printf("\n--------TEST7------\n");
// ////	ft_printf("number: %10d #03x, %02o\n", 17, 17, 17);
// ////	printf("number: %10d #03x, %02o\n", 17, 17, 17);
// ////
// ////	printf("\n--------TEST7------\n");
// ////	ft_printf("number: %10hhd #03x, %02o\n", 17, 17, 17);
// ////	printf("number: %10hhd #03x, %02o\n", 17, 17, 17);
// ////
// ////	printf("\n--------TEST1------\n");
// ////	ft_printf("'%-10d'\n", 77157);
// ////	printf("'%-10d'\n", 77157);
// ////
// ////	printf("\n--------TEST7------\n");
// ////	ft_printf("'number: %-10hhd #03x, %02o'\n", 17, 17, 17);
// ////	printf("'number: %-10hhd #03x, %02o'\n", 17, 17, 17);
// ////
// ////	printf("\n--------TEST4------\n");
// ////	ft_printf("'%-10s'\n", "salut");
// ////	printf("'%-10s'\n", "salut");
// ////
// //	// printf("\n--------------PRECISION:-----------------\n");
// //	// printf("'%10.10x'\n", 100);
// //	// printf("'%15.10x'\n", 100);
// //	// ft_printf("'%5.10x'\n", 100);
// //
// //
// //	// ft_printf("'%10.10x'\n", 100);
// //
// //
// //	printf("'%+d'\n", 14);
// //	printf("%hd\n", number);
// //	printf("%d\n", 1000);
// //	printf("%-10d\n", 1000);
// //	printf("%10d\n", a);
// //
// //	printf("%hhx\n", c);
// //	printf("%010d \n", number);
// //	printf("%-#10x \n", number);
// //	printf("%#x \n", number);
// //	printf("\n-------------TEST X------------\n");
// //	ft_printf("MINE: %X\n", 45656465);
// //	printf("REAL: %X\n", 45656465);
// //	printf("\n-------------TEST D------------\n");
// //	ft_printf("MINE: %D\n", 989898989);
// //	printf("REAL: %D\n", 989898989);
// //	printf("\n-------------TEST o------------\n");
// //	ft_printf("MINE: %o\n", 989898989);
// //	printf("REAL: %o\n", 989898989);
// //	printf("\n-------------TEST O------------\n");
// //	ft_printf("MINE: %O\n", 989898989);
// //	printf("REAL: %O\n", 989898989);
// //	printf("\n-------------TEST U------------\n");
// //	ft_printf("MINE: %U\n", -30);
// //	printf("REAL: %U\n", -30);
// //	printf("\n-------------TEST P------------\n");
// //	ft_printf("MINE: %p\n", &number);
// //	printf("REAL: %p\n", &number);
// //	printf("\n-------------TEST x------------\n");
// //	ft_printf("MINE: %x\n", 45656465);
// //	printf("REAL: %x\n", 45656465);
// //	printf("\n-------------TEST C------------\n");
// //	ft_printf("MINE: %C\n", 45);
// //	printf("REAL: %C\n", 45);
// //	printf("\n-------------TEST %%------------\n");
// //	printf("REAL: %%\n");
// //	ft_printf("MINE: %%\n");
// //	printf("\n------------XTEST SPACEX----------\n");
// //	printf("REAL: %           d\n", 100);
// //	ft_printf("MINE: % d\n", 100);
// //	printf("\n-------------TEST '-'-----------\n");
// //	printf("REAL: %-Od\n", 100);
// //	printf("REAL: %100x\n", 564556);
// //	printf("\n-------------TEST 'h'-----------\n");
// //	ft_printf("MINE: %hd\n", 20);
// //	printf("REAL: %d\n", 20);
// //
// //	printf("\n-------------TEST 'hh'-----------\n");
// //	ft_printf("MINE: %hhd\n", 20);
// //	printf("REAL: %d\n", 20);
// //
// //	printf("\n-------------TEST '-'-----------\n");
// //	printf("REAL: %-s\n", "salut");
// //
// //	printf("\n-------------TEST '0'-----------\n");
// //	printf("REAL: %05d\n", 50);
// //	printf("%-10d \n", number);
// //	printf("%010d \n", number);
// //	printf("%-#10x \n", number);
// //	printf("%#x \n", number);
// //	printf("%#.0o\n", 0);
// //	long long values[] = {
// //		LONG_LONG_MIN,
// //		(long)INT_MIN,
// //		(long)(-1000L),
// //		(long)-10,
// //		(long)-1,
// //		0L,
// //		1L,
// //		10L,
// //		1000L,
// //		(long)INT_MAX,
// //		LONG_LONG_MAX,
// //	};
// //
// //	ft_printf("ft_printf = %d\n", -1);
// //	for (int i = 0; i < 11; i++) {
// //		printf("\n==== %llu ====\n", (unsigned long long)values[i]);
// //		   printf("   printf = %d\n", (int)values[i]);
// //		ft_printf("ft_printf = %d\n", (int)values[i]);
// //		   printf("   printf = %u\n", (unsigned)values[i]);
// //		ft_printf("ft_printf = %u\n", (unsigned)values[i]);
// //		   printf("   printf = %o\n", (unsigned)values[i]);
// //		ft_printf("ft_printf = %o\n", (unsigned)values[i]);
// //		   printf("   printf = %x\n", (unsigned)values[i]);
// //		ft_printf("ft_printf = %x\n", (unsigned)values[i]);
// //		   printf("   printf = %X\n", (unsigned)values[i]);
// //		ft_printf("ft_printf = %X\n", (unsigned)values[i]);
// //		   printf("   printf = %D\n", (unsigned)values[i]);
// //		ft_printf("ft_printf = %D\n", (unsigned)values[i]);
// //		   printf("   printf = %c\n", (char)values[i]);
// //		ft_printf("ft_printf = %c\n", (char)values[i]);
// //	}
// //}
// }
