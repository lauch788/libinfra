#ifndef _LIBINFRA_UNICODE_H
#define _LIBINFRA_UNICODE_H

#include <stdint.h>

static inline int
infra_ascii_is_digit(uint32_t c)
{
  return (c >= '0' && c <= '9');
}

static inline int
infra_ascii_is_upper_alpha(uint32_t c)
{
  return (c >= 'A' && c <= 'Z');
}

static inline int
infra_ascii_is_lower_alpha(uint32_t c)
{
  return (c >= 'a' && c <= 'z');
}

static inline int
infra_ascii_is_alpha(uint32_t c)
{
  return (infra_ascii_is_lower_alpha(c)
       || infra_ascii_is_upper_alpha(c));
}

static inline int
infra_ascii_is_alnum(uint32_t c)
{
  return (infra_ascii_is_digit(c)
       || infra_ascii_is_alpha(c));
}

/* Strings */

/* These casing functions can be iterated over an UTF-8 string */
static inline char
infra_ascii_to_lower(char c)
{
  return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
}

static inline char
infra_ascii_to_upper(char c)
{
  return (c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c;
}

#endif /* _LIBINFRA_UNICODE_H */
