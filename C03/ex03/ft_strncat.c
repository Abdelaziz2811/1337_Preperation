char *ft_strncat(char *dest, char *src, unsigned int nb)
{
	int i = 0;
        while (dest[i] != '\0')
                i++;

        int j = 0;
        while (j < nb && src[j] != '\0')
        {
                dest[i] = src[j];
                j++;
                i++;
        }
        dest[i] = '\0';

        return dest;
}
