#include <unistd.h>
#include <fcntl.h>

int main (int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "File name missing.\n", 19);
		return 1;
	}
	else if (argc > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return 1;
	}
	else 
	{
		int fd = open(argv[1], O_RDONLY);

		if (fd != -1)
		{
			char buffer[100];
			int i = 0;
			ssize_t bytes_read;
			while ((bytes_read = read(fd, buffer, 100)) > 0)
			{
				write(1, buffer, bytes_read);
			}
			close(fd);
		}
		else 
		{
			write(1, "Cannot read file.\n", 18);
			return 1;
		}
	}

	return 0;
}
