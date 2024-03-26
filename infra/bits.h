#ifndef _LIBINFRA_BITS_H
#define _LIBINFRA_BITS_H
/*
 * Copyright 2024 Adrien Ricciardi
 * See LICENSE for details
 */
#include <stdint.h>

static inline uint8_t
infra_bitpos8(int idx)
{
  return (uint8_t)1 << idx;
}

static inline uint16_t
infra_bitpos16(int idx)
{
  return (uint16_t)1 << idx;
}

static inline uint32_t
infra_bitpos32(int idx)
{
  return (uint32_t)1 << idx;
}

#endif /* _LIBINFRA_BITS_H */

