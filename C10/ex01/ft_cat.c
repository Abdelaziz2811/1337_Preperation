#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

int main(int argc, char **argv)
{
	char buffer[30000];
	ssize_t bytes_read;

	if (argc == 1)
	{
		while ((bytes_read = read(0, buffer, sizeof(buffer))))
		{
			write(1, buffer, bytes_read);
		}	
	}
	else
	{
		int i = 1;
		char *program_name;
		char *file_name;
		char *error;
		
		while (i < argc)
		{
			int fd = open(argv[i], O_RDONLY);
			if (fd != -1)
			{
				while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
				{
					write(1, buffer, bytes_read);
				}
				close(fd);		
			}
			else
			{
				program_name = argv[0];
				file_name = basename(argv[i]);
				error = strerror(errno);
				
				int l = 0;
				while (program_name[l])
					write(1, &program_name[l++], 1);

				write(1, ": ", 2);

				int j = 0;
				while (file_name[j])
					write(1, &file_name[j++], 1);
	
				write(1, ": ", 2);
				
				int k = 0;
				while (error[k])
					write(2, &error[k++], 1);

				write(1, "\n", 1);
			}
			i++;	
		}
	}

	return 0;	
}
