#ifndef _LIBINFRA_NAMESPACE_H
#define _LIBINFRA_NAMESPACE_H

/*
 * Copyright 2024 (c) Adrien Ricciardi
 * This file is part of the libinfra distribution (https://github.com/rshadr/libinfra)
 * See LICENSE for details
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


enum InfraNamespace {
  INFRA_NAMESPACE_NULL = 0,
  INFRA_NAMESPACE_HTML,
  INFRA_NAMESPACE_SVG,
  INFRA_NAMESPACE_XLINK,
  INFRA_NAMESPACE_XML,
  INFRA_NAMESPACE_XMLNS,

  NUM_INFRA_NAMESPACE
};


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* _LIBINFRA_NAMESPACE_H */

