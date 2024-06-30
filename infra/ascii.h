#ifndef _infra_ascii_h_
#define _infra_ascii_h_

/*
 * Copyright 2024 (c) Adrien Ricciardi
 * This file is part of the libinfra distribution (https://github.com/rshadr/libinfra)
 * See LICENSE for details
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdbool.h>
#include <uchar.h>


static inline bool
infra_ascii_is_digit(char32_t c)
{
  return (c >= '0' && c <= '9');
}


static inline bool
infra_ascii_is_upper_xdigit(char32_t c)
{
  return (infra_ascii_is_digit(c) || (c >= 'A' && c <= 'F'));
}


static inline bool
infra_ascii_is_lower_xdigit(char32_t c)
{
  return (infra_ascii_is_digit(c) || (c >= 'a' && c <= 'f'));
}


static inline bool
infra_ascii_is_xdigit(char32_t c)
{
  return (infra_ascii_is_upper_xdigit(c) || infra_ascii_is_lower_xdigit(c));
}


static inline bool
infra_ascii_is_upper_alpha(char32_t c)
{
  return (c >= 'A' && c <= 'Z');
}


static inline bool
infra_ascii_is_lower_alpha(char32_t c)
{
  return (c >= 'a' && c <= 'z');
}


static inline bool
infra_ascii_is_alpha(char32_t c)
{
  return (infra_ascii_is_upper_alpha(c) || infra_ascii_is_lower_alpha(c));
}


static inline bool
infra_ascii_is_alnum(char32_t c)
{
  return (infra_ascii_is_digit(c) || infra_ascii_is_alpha(c));
}


static inline char32_t
infra_ascii_tolower(char32_t c)
{
  return infra_ascii_is_upper_alpha(c) ? c - 'A' + 'a' : c;
}


static inline char32_t
infra_ascii_toupper(char32_t c)
{
  return infra_ascii_is_lower_alpha(c) ? c - 'a' + 'A' : c;
}


static inline int
infra_ascii_strincmp(char const *a, char const *b, size_t len)
{
  size_t i = 0;
  
  for (; a[i] != '\0' && b[i] != '\0' && i < len; i++)
    if (infra_ascii_tolower(a[i]) != infra_ascii_tolower(b[i]))
      return (a[i] - b[i]);
  
  return 0;
}


#if defined(INFRA_SHORT_NAMES)
# define ascii_is_digit(...) infra_ascii_is_digit(__VA_ARGS__)
# define ascii_is_upper_xdigit(...) infra_ascii_is_upper_xdigit(__VA_ARGS__)
# define ascii_is_lower_xdigit(...) infra_ascii_is_lower_xdigit(__VA_ARGS__)
# define ascii_is_xdigit(...) infra_ascii_is_xdigit(__VA_ARGS__)
# define ascii_is_upper_alpha(...) infra_ascii_is_upper_alpha(__VA_ARGS__)
# define ascii_is_lower_alpha(...) infra_ascii_is_lower_alpha(__VA_ARGS__)
# define ascii_is_alpha(...) infra_ascii_is_alpha(__VA_ARGS__)
# define ascii_is_alnum(...) infra_ascii_is_alnum(__VA_ARGS__)
# define ascii_tolower(...) infra_ascii_tolower(__VA_ARGS__)
# define ascii_toupper(...) infra_ascii_toupper(__VA_ARGS__)
# define ascii_strincmp(...) infra_ascii_strincmp(__VA_ARGS__)
#endif /* defined(INFRA_SHORT_NAMES) */


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */


#endif /* _infra_ascii_h_ */

