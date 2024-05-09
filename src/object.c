#include "infra/object.h"

#include <stdlib.h>
#include <assert.h>

static void *
infra_object_alloc_(struct _infra_object_vtable const *vtable)
{

  assert( vtable->impl_size != 0 );

  struct _infra_object_header *header = calloc(1, vtable->impl_size);

  header->vtable = vtable;
  header->ref_count = 1;

  return (void *)header;
}

static void
infra_object_construct_(struct _infra_object_vtable const *vtable, void *p)
{
  if (vtable == NULL)
    return;

  infra_object_construct_(vtable->super_vtable, p);

  if (vtable->ctor != NULL)
    vtable->ctor(p);
}

void *
infra_object_new_(struct _infra_object_vtable const *vtable)
{
  void *p = infra_object_alloc_(vtable);
  infra_object_construct_(vtable, p);

  return p;
}

static void
infra_object_destroy_(void *p)
{
  struct _infra_object_header *header = p;

  for (struct _infra_object_vtable const *vtable = header->vtable;
       vtable != NULL; vtable = vtable->super_vtable)
    if (vtable->dtor != NULL)
      vtable->dtor(p);

  free(p);
}

#if defined(__GNUC__)
/* covers clang and GCC */
__attribute__((hot))
#endif /* defined(__GNUC__) */
void
infra_object_unref(void *p)
{
  if (p == NULL)
    return;

  struct _infra_object_header *header = p;

  if (--header->ref_count <= 0)
    infra_object_destroy_(p);
}


