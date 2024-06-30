#ifndef _LIBINFRA_UTIL_H
#define _LIBINFRA_UTIL_H

/*
 * Copyright 2024 (c) Adrien Ricciardi
 * This file is part of the libinfra distribution (https://github.com/rshadr/libinfra)
 * See LICENSE for details
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


#define INFRA_COUNTOF(comptime_array) \
  (sizeof ((comptime_array)) / sizeof ((comptime_array)[0]))


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */


#endif /* _LIBINFRA_UTIL_H */

