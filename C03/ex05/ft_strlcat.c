unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int dest_len = 0;
	while (dest[dest_len] != '\0')
		dest_len++;

	unsigned int src_len = 0;
	while (src[src_len] != '\0')
		src_len++;

	if (size <= dest_len) return size + src_len;
	
	int i = 0;
	unsigned int j = dest_len;
	while (j < size - 1 && src[i] != '\0')
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';

	return dest_len + src_len;
}
