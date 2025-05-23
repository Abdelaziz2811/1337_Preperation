#include <unistd.h>
#include "options.h"

int main(int argc, char **argv)
{
	if (argc == 1 || h_flag(argv))
	{
		write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
	}
	else
	{
		if (valid_options(argv))
		{
			unsigned int value = options_to_int(argv);
			presentation_display(value);
		}
		else
			write(1, "Invalid Option", 14);
	}

	return 0;
}
