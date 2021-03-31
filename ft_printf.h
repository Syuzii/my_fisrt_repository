/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:30:19 by symatevo          #+#    #+#             */
/*   Updated: 2021/03/30 19:54:48 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct				s_flags
{
	int						minus;
	int						dot;
	int						width;
	int						star;
	int						zero;
	int						type;
	long long unsigned int	p;
}							t_flags;

int							ft_printf(const char *format, ...);
int							ft_putchar(char c);
int							ft_handle(const char *keep, int i,
		t_flags *flags, va_list args);
t_flags						*ft_handle_zero(const char *keep,
		int i, t_flags *flags);
t_flags						*ft_handle_minus(t_flags *flags);
int							ft_handle_dot(const char *keep, int i,
		va_list args, t_flags *flags);
int							ft_handle_star(va_list args, t_flags *flags);
int							is_flag(char c);
int							is_specifier(char c);
size_t						ft_strlen(const char *str);
void						*ft_calloc(size_t nitems, size_t size);
void						ft_bzero(void *str, size_t n);
char						*ft_strdup(const char *str);
char						*make_d(const char *keep, int i,
		t_flags *flags, int *length);
char						*spec_d(char *str, char *ptr, t_flags *flags,
		int *length);
int							ft_isdigit(int c);
char						*ft_itoa(int n);
char						*star_d(char *str, int width);
char						*dot_d(char *str, t_flags *flags);
int							count_d(const char *keep, int i, t_flags *flags,
		va_list args);
char						*make_str_d(t_flags *flags, int length);
int							count_s(const char *keep, int i, t_flags *flags,
		va_list args);
char						*make_str_s(t_flags *flags, char *ptr);
char						*spec_s(char *str, char *ptr);
char						*make_s(const char *keep, int i, t_flags *flags,
		va_list args);
int							count_c(t_flags *flags, va_list args);
char						*ft_strrev(char *str);
int							ft_isalpha(int ch);
char						*ft_reverse_digit(char *str);
int							ft_checkdot(const char *keep, int i);
int							count_hex(const char *keep, int i, t_flags *flags,
		va_list args);
char						*ft_strrev_bonus(char *str);
char						*ft_reverse_str(char *str, int length, int dot);
char						*ft_unsigned_itoa(unsigned int n);
int							count_unsigned(const char *keep, int i,
		t_flags *flags, va_list args);
char						*make_str_unsigned(t_flags *flags, unsigned int a);
char						*make_str_hex(t_flags *flags, int length);
char						*spec_hex(char *str, char *ptr);
int							count_pointer(const char *keep, int i,
		t_flags *flags, va_list args);
char						*ft_reverse_hex(char *str, int length, int dot);
void						ft_putstr_fd(char *s, int fd);
char						*ft_putptr(char *str, char *ptr);
char						*make_hex(unsigned int n);
char						*make_hex_up(unsigned int n);
char						*make_hex_forpointer(long long unsigned int n);
char						*ft_dot_s_utils(char *str, int dot, int width,
		int length);
char						*zero_s(char *str, int length);
char						*write_tmp(char *str, char *ptr);

#endif
