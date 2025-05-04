#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

int ft_atoi(char *str)
{
	int i = 0;
	int number = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			number = number * 10 + (str[i] - '0');
		i++;
	}
	return number;
}

int ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i]) return 0;
		i++;
	}
	return (s1[i] == '\0' && s2[i] == '\0');
}

int is_num(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return 0;
		i++;
	}
	return 1;
}

void print_n_bytes(char *file_name, int bytes_read, int n_bytes, char *program_name, int argc)
{
	int fd = open(file_name, O_RDONLY);
	if (fd != -1)
	{
		char *buffer = malloc(sizeof(char) * n_bytes);
		
		int total_bytes = lseek(fd, 0, SEEK_END);
		close(fd);		

		fd = open(file_name, O_RDONLY);
		int current = 0;
		
		// print file name in case multiple files
		if (argc > 4)
		{
			int j = 0;
			write(1, "==> ", 4);
			while (file_name[j])
				write(1, &file_name[j++], 1);
			write(1, " <==\n", 5);
		}
		
		// print n bytes
		while ((bytes_read = read(fd, buffer, 1)) > 0)
		{
			if (n_bytes >= total_bytes)
			{
				char temp_buffer[total_bytes + 1];
 				temp_buffer[0] = buffer[0]; 
				read(fd, temp_buffer + 1, total_bytes - 1);
				write(1, temp_buffer, total_bytes);
				break;
			}
			
			current++;	
			if (current == (total_bytes - n_bytes))
			{
				read(fd, buffer, n_bytes);
				write(1, buffer, n_bytes);
			}
		}
		close(fd);
		free(buffer);
		write(1, "\n", 1);
	}
	else 
	{
		char *error = strerror(errno);
		
		int l = 0;
		while (program_name[l])
			write(2, &program_name[l++], 1);

		write(2, ": cannot open '", 15);

		l = 0;
		while (file_name[l])
			write(1, &file_name[l++], 1);

		write(2, "' for reading: ", 15);
				
		l = 0;
		while (error[l])
			write(2, &error[l++], 1);

		write(1, "\n", 1);		
	}
}

int main(int argc, char **argv)
{
	if (argc > 2)
	{
		if (!ft_strcmp(argv[1], "-c")) 
			return 1;

		int n_bytes = ft_atoi(argv[2]);

		if (!is_num(argv[2]))
		{	
			int i = 0;
			while (argv[0][i])
				write(2, &argv[0][i++], 1);

			write(2, ": invalid number of bytes: '", 28);

			i = 0;
			while (argv[2][i])
				write(2, &argv[2][i++], 1);
			write(2, "'", 1);			
		}	

		ssize_t bytes_read = 0;

		if (argc == 3 && is_num(argv[2]))
		{
			char buffer[1];
			while (read(0, buffer, 1)) {}
		}
		else if (argc == 4)
		{			
			print_n_bytes(argv[3], bytes_read, n_bytes, argv[0], argc);
		}
		else
		{
			int i;
			for (i = 3; i < argc; i++)
			{
				print_n_bytes(argv[i], bytes_read, n_bytes, argv[0], argc);
			}
		}
	}	
	return 0;
}
