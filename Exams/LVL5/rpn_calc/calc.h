#ifndef _CALC_H_
#define _CALC_H_

int ft_add(int a, int b);
int ft_sub(int a, int b);
int ft_mul(int a, int b);
int ft_div(int a, int b);
int ft_mod(int a, int b);

int operator_index(char op);
int perform_op(int op_index, int num1, int num2);

#endif
