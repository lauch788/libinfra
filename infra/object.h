#ifndef _LIBINFRA_OBJECT_H
#define _LIBINFRA_OBJECT_H

#include <stdint.h>

typedef void InfraObject;
typedef struct InfraObjectShared_s InfraObjectShared;

typedef struct InfraClass_s {
  void (*finalizer) (InfraObjectShared *obj);
} InfraClass;

struct InfraObjectShared_s {
  const InfraClass *class;
  int_least32_t strong_refcnt;
  int_least32_t weak_refcnt;
  /* opaque */
};

void infra__object_free(InfraObject *any);

static inline InfraObject *
infra_strong_ref_object(InfraObject *any)
{
  if (any != NULL)
    ((InfraObjectShared *) any)->strong_refcnt++;

  return any;
}

static inline void
infra_strong_unref_object(InfraObject *any)
{
  InfraObjectShared *shared = any;

  if (shared != NULL && --shared->strong_refcnt <= 0)
    infra__object_free(shared);
}

static inline InfraObject *
infra_weak_ref_object(InfraObject *any)
{
  if (any != NULL)
    ((InfraObjectShared *) any)->weak_refcnt++;

  return any;
}

static inline void
infra_weak_unref_object(InfraObject *any)
{
  InfraObjectShared *shared = any;

  if (shared != NULL)
    shared->weak_refcnt--;
}

#endif /* _LIBINFRA_OBJECT_H */
