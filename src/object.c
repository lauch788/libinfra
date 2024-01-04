/*
 * Copyright 2024 Adrien Ricciardi
 * See LICENSE for details
 */
#include <stdlib.h>

#include <infra/object.h>

void
infra__object_free(InfraObject *any)
{
  InfraObjectShared *shared = any;
  const InfraClass *class = shared->class;

  if (class->finalizer != NULL)
    class->finalizer(any);

  free(any);
}
