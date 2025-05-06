#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

int ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return s1[i] - s2[i];
		i++;
	}
	if (s1[i] != s2[i])
		return s1[i] - s2[i];

	return 0;
}

int is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return 1;
	return 0;
}

void print_offset(size_t offset)
{
	char buffer[8];

	int i = 7;
	while(i >= 0)
	{
		buffer[i] = "0123456789abcdef"[offset % 16];
		offset /= 16;
		i--;
	}

	write(1, buffer, 8);
	write(1, "  ", 2);
}

void print_hex(char *buffer, ssize_t bytes_read)
{
	int i;
	char *hex = "0123456789abcdef";
	char chars[2];
	for (i = 0; i < bytes_read; i++)
	{
		chars[0] = hex[(unsigned)buffer[i] / 16];
		chars[1] = hex[(unsigned)buffer[i] % 16];

		write(1, chars, 2);
		write(1, " ", 1);

		if (i == 7) write(1, " ", 1);
	}
	write(1, " ", 1);
}

void print_last_spaces(ssize_t bytes_read)
{
	int i;
	int left_bytes = 16 - bytes_read;
	for (i = 1; i <= left_bytes; i++)
	{
		write(1, "   ", 3);
	}
	if (left_bytes > 8) write(1, " ", 1);
}

void process_buff(char *buffer, ssize_t bytes_read)
{
	int i = 0;
	while (i < bytes_read)
	{
		if (buffer[i] < 32 || buffer[i] > 126)
			buffer[i] = '.';
		i++;
	}
}

void print_line(char *buffer, size_t *offset, ssize_t bytes_read)
{
	print_offset(*offset);
	
	print_hex(buffer, bytes_read);
	
	print_last_spaces(bytes_read);
	
	process_buff(buffer, bytes_read);
	
	write(1, "|", 1);
	write(1, buffer, bytes_read);
	write(1, "|\n", 2);
	
	*offset += bytes_read;
}

void process_line(int fd, char *buffer, size_t *offset, int total_files)
{
	static char temp_buff[16];
	ssize_t bytes_read = 0;
	static int i = 0;

	while ((bytes_read = read(fd, buffer, 1)) > 0)
	{
		temp_buff[i] = buffer[0];
			i++;

		if (i == 16) 
		{
			print_line(temp_buff, offset, i);
			i = 0;
		}
	}
	if (i != 0 && total_files == 1)
		print_line(temp_buff, offset, i);
	
	if (total_files == 1)
		print_offset(*offset);
}

void print_error_message(char *program_name, char *file_name)
{
	char *error = strerror(errno);
		
	int i = 0;
	while (program_name[i])
		write(2, &program_name[i++], 1);

	write(2, ": ", 2);

	i = 0;
	while (file_name[i])
		write(1, &file_name[i++], 1);

	write(2, ": ", 2);
				
	i = 0;
	while (error[i])
		write(2, &error[i++], 1);

	write(1, "\n", 1);	 
} 

int main(int argc, char **argv)
{
	if (argc >= 2)
	{
		if (ft_strcmp(argv[1], "-C") != 0) return 1;

		char *buffer = malloc(sizeof(char) * 16);
		ssize_t bytes_read = 0;
		size_t offset = 0;

		if (argc == 2)
		{ 
			char temp_buff[16];
			int i = 0;
			while ((bytes_read = read(0, buffer, 1)) > 0) 
			{
				temp_buff[i] = buffer[0];
				i++;

				if (i == 16) 
				{
					print_line(temp_buff, &offset, i);
					i = 0;
				}
			}
		}
		else
		{
			int i;
			int total_files = argc  - 2;
			for (i = 2; i < argc; i++)
			{
				int fd = open(argv[i], O_RDONLY);
				
				if (fd != -1)
				{
					process_line(fd, buffer, &offset, total_files--);
				
					close(fd);
				}
				else 
					print_error_message(argv[0], argv[i]);
			}
		}
		free(buffer);
	}

	return 0;
}
