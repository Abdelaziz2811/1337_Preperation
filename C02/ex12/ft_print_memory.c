#include <unistd.h>
#include <stdio.h>
void *ft_print_memory(void *addr, unsigned int size)
{
	if (size > 0)
	{
		unsigned char *str = addr;
		int i = 0;
		int n_bytes = 16;

		char hex[] = "0123456789abcdef";
		char buffer[16];
		int j;
		char content_in_hex[2];
		char printable_chars[16];

		while (i < size - 1)
		{
			if (n_bytes == 16)
			{
				// print the hexadecimal address of the first char of each 16 bytes				
				unsigned long address = (unsigned long)&str[i];
				j = 15;

				while (j >= 0)
				{
					buffer[j] = hex[address % 16];
					address /= 16;
					j--;
				}
	
				write(1, buffer, 16);
				write(1, ": ", 2);
				
				n_bytes = 0;
			}

			// print content in hexadecimal of the 16 bytes
				
			content_in_hex[0] = hex[(unsigned char)str[i] / 16];
			content_in_hex[1] = hex[(unsigned char)str[i] % 16];

			write(1, &content_in_hex[0], 1);
			write(1, &content_in_hex[1], 1);
			
			if ((i + 1) % 2 == 0) write(1, " ", 1);

			printable_chars[n_bytes] = str[i];

			if (n_bytes == 15) 
			{
				write(1, printable_chars, 16);
				write(1, "\n", 1);
			}
			
			i++;
			n_bytes++;
		}

		if (n_bytes < 16  && printable_chars[0] != '\0')
		{
			int remaining = 16 - n_bytes;
			while (remaining--)
			{
				write(1, "  ", 2);
				if ((n_bytes + remaining) % 2 == 1)
					write(1, " ", 1);
			}			

			int k = 0;
			while (k < n_bytes)
			{
				write(1, &printable_chars[k], 1);
				k++;
			}			
			write(1, "\n", 1);
		}
	}
	return addr;
}

int main()
{
	char str[] = "Bonjour les aminches...c. est fou.tout.ce qu on peut faire avec...print_memory...";

	ft_print_memory(str, sizeof(str));

	return 0;
}
