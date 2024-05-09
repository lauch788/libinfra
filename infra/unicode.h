#ifndef _infra_unicode_h_
#define _infra_unicode_h_

#include <stdbool.h>
#include <uchar.h>

static inline bool
infra_unicode_is_leading_surrogate(char32_t c)
{
  return (c >= 0xD800 && c <= 0xDBFF);
}

static inline bool
infra_unicode_is_trailing_surrogate(char32_t c)
{
  return (c >= 0xDC00 && c <= 0xDFFF);
}

static inline bool
infra_unicode_is_surrogate(char32_t c)
{
  return (unicode_is_leading_surrogate(c)
       || unicode_is_trailing_surrogate(c));
}

static inline bool
infra_unicode_is_noncharacter(char32_t c)
{
  if (c >= 0xFDD0 && c <= 0xFDEF)
    return true;

  switch (c) {

    case 0x00FFFE: case 0x00FFFF:
    case 0x01FFFE: case 0x01FFFF:
    case 0x02FFFE: case 0x02FFFF:
    case 0x03FFFE: case 0x03FFFF:
    case 0x04FFFE: case 0x04FFFF:
    case 0x05FFFE: case 0x05FFFF:
    case 0x06FFFE: case 0x06FFFF:
    case 0x07FFFE: case 0x07FFFF:
    case 0x08FFFE: case 0x08FFFF:
    case 0x09FFFE: case 0x09FFFF:
    case 0x0AFFFE: case 0x0AFFFF:
    case 0x0BFFFE: case 0x0BFFFF:
    case 0x0CFFFE: case 0x0CFFFF:
    case 0x0DFFFE: case 0x0DFFFF:
    case 0x0EFFFE: case 0x0EFFFF:
    case 0x0FFFFE: case 0x0FFFFF:
    case 0x10FFFE: case 0x10FFFF:
      return true;

    default:
      return false;
  }

}

#if defined(INFRA_SHORT_NAMES)
# define unicode_is_leading_surrogate(...) infra_unicode_is_leading_surrogate(__VA_ARGS__)
# define unicode_is_trailing_surrogate(...) infra_unicode_is_trailing_surrogate(__VA_ARGS__)
# define unicode_is_surrogate(...) infra_unicode_is_surrogate(__VA_ARGS__)
# define unicode_is_noncharacter(...) infra_unicode_is_noncharacter(__VA_ARGS__)
#endif /* defined(INFRA_SHORT_NAMES) */

#endif /* !defined(_infra_unicode_h_) */

