#include "ft_printf.h"

char	dtoa(unsigned char digit, char uppercase)
{
	if (digit < 10)
		return (char)(digit + '0');
	else
		return (char)(digit - 10 + 'A' + (!uppercase) * 32);
}

int	ft_putchar(char c)
{
	return ((int)write(1, &c, 1));
}

int	ft_puthex(unsigned long n, char upper)
{
	int len;

	len = 0;
	if (n >= 16)
		len += ft_puthex(n / 16, upper);
	n = n % 16;
	len += ft_putchar(dtoa(n, upper));
	return (len);
}

int	ft_putstr(const char *str)
{
	int i;

	i = -1;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[++i])
	{
		write(1, &str[i], 1);
	}
	return (i);
}

char	*ft_itoa_base_signed(long long value, unsigned char base, char upper)
{
	char	*s;
	long long	n;
	int		sign;
	int		i;

	sign = 0;
	if (value == INT64_MIN && base == 10)
		return (ft_strdup("-9223372036854775808"));
	if (value == INT64_MAX && base == 10)
		return (ft_strdup("9223372036854775807"));
	if (value < 0)
	{
		value = -value;
		sign = 1;
	}
	n = value;
	i = sign ? 2 : 1;
	while ((n /= base) > 0)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	while (i-- - sign)
	{
		s[i] = dtoa((unsigned char)(value % base), upper);
		value /= base;
	}
	if (sign)
		s[0] = '-';
	return (s);
}

char	*ft_itoa_base(unsigned long long value, unsigned char base, char upper)
{
	char	*s;
	unsigned long long	n;
	int		i;

	n = value;
	i = 1;
	if ((long)value == INT64_MIN && base == 10)
		return (ft_strdup("-9223372036854775807"));
	if (value == INT64_MAX && base == 10)
		return (ft_strdup("9223372036854775807"));
	while ((n /= base) > 0)
	{
		i++;
	}
	s = (char*)malloc(sizeof(char) * (4096));
	s[i] = '\0';
	while (i--)
	{
		s[i] = dtoa((unsigned char)(value % base), upper);
		value /= base;
	}
	return (s);
}


char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (s1 == NULL)
		return ("(null)");
	while (s1[i])
		i++;
	if ((cpy = malloc(sizeof(char) * 4096)) == NULL)
		return (NULL);
	while (s1[j])
	{
		cpy[j] = s1[j];
		j++;
	}
	cpy[j] = '\0';
	return (cpy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	new = (char*)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new == NULL)
		return (NULL);
	ft_strcpy(new, s1);
	ft_strcat(new, s2);
	return (new);
}

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int 	is_carac(char c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

