#ifndef _LIBINFRA_UNICODE_H
#define _LIBINFRA_UNICODE_H

#include <stdint.h>

static inline int
infra_ascii_is_lower_alpha(uint32_t c)
{
  return (c >= 'a' && c <= 'z');
}

static inline int
infra_ascii_is_upper_alpha(uint32_t c)
{
  return (c >= 'A' && c <= 'Z');
}

static inline int
infra_ascii_is_alpha(uint32_t c)
{
  return (infra_ascii_is_lower_alpha(c)
       || infra_ascii_is_upper_alpha(c));
}

#endif /* _LIBINFRA_UNICODE_H */
