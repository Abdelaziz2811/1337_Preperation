#ifndef FT_CONVERT_BASE2_H
#define FT_CONVERT_BASE2_H

int ft_strlen(char *str);

int is_valid_base(char *base);

int is_in_base(char c, char *base);

int get_char_index(char c, char *base);

int ft_atoi_base(char *nbr, char *base_from);

void set_num_base(unsigned int nbr, char *base, unsigned int base_len, char *num_base, int *index);

void ft_getnbr_base(int nbr, char *base, char *buffer);

#endif
