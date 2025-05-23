#include <unistd.h>

void 	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	put_hex(unsigned char byte)
{
	char hex[] = "0123456789abcdef";

	write(1, &hex[byte / 16], 1);
	write(1, &hex[byte % 16], 1);
}

void    print_memory(const void *addr, size_t size)
{
	unsigned char *bytes = (unsigned char *)addr;

	size_t i = 0;
	size_t n_bytes = 1, j = 0;
	while (i < size)
	{
		j = i;
		n_bytes = 0;
		while (n_bytes < 16 && (n_bytes + i) < size)
		{
			put_hex(bytes[j]);

			if ((j + 1) % 2 == 0)
				write(1, " ", 1);

			n_bytes++;
			j++;
		}

		int remain_bytes = n_bytes;
		while (remain_bytes < 16)
		{
			if (remain_bytes % 2 == 0)
			{
				ft_putchar(' ');
			}
			ft_putchar(' ');
			ft_putchar(' ');

			remain_bytes++;
		}

		j = i;
		while (j < (n_bytes + i))
		{
			if (bytes[j] >= ' ' && bytes[j] <= '~')
				ft_putchar(bytes[j]);
			else
				ft_putchar('.');
			j++;
		}

		i += n_bytes;
		ft_putchar('\n');
	}	
}
