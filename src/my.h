/*
** EPITECH PROJECT, 2020
** Day04
** File description:
** librairy file
*/

#ifndef my_h
#define my_h

#include <stdio.h>
#include <stdlib.h>

void my_putchar(char);
int my_putstr(char const *);
int my_strlen(char const *);
char * my_strcpy(char *, char const *);
char * my_revstr(char *);
char *my_strcat(char *, char *);
int my_str_isprintable(char const *);
int my_showstr(char *);
int my_char_isprintable(char);
char *my_convhexa(int);
char *my_strdup(char *);
int my_printf(char *format, ...);
char *int_read(int nb);
char *fill_missing(char *, int);
char *my_conv_octal(int);
char *my_showstr_octal(char *);
char *my_convbin(int);
char *rm_zero(char *);
int get_flag(char);
void s_flag(char *);
void c_flag(int);
void di_flag(int);
void d_flag(int);
void i_flag(int);
void sh_flag(char *);
void o_flag(int);
void x_flag(int);
void xh_flag(int);
void xs_flag(int);
void b_flag(int);
void p_flag(unsigned long);
void of_flag(int);
typedef struct s_form
{
    char *bef;
    char arg_type;
    int pos;
}t_form;
#endif