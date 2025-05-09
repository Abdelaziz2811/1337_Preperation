#include <stdio.h>

unsigned char   reverse_bits(unsigned char octet)
{
	int i;
    	unsigned char result = 0;

    	for (i = 0; i < 8; i++)
    	{
        	result = result << 1;               
		result = result | (octet & 1);      
		octet = octet >> 1;                
    	}

	return result;
}

int main()
{
	printf("%c", reverse_bits('&') );
	return 0;
}
