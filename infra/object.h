#ifndef _infra_object_h_
#define _infra_object_h_

#include <stddef.h>
#include <stdint.h>


struct _infra_object_vtable {
  /* optional; for derived classes */
  struct _infra_object_vtable const *super_vtable;

  /*
   * optional; Constructors/destructors.
   * Called in C++ order, MUST NOT be called explicitly
   */
  void (*ctor) (void *p);
  void (*dtor) (void *p);

  /*
   * optional; size of instance
   *  zero -> abstract class, instantiation throws runtime error
   */
  size_t impl_size;
};


#define INFRA_OBJECT_DECLARE_VTABLE(comptime_name) \
  extern const struct _infra_object_vtable k_ ## comptime_name ## _vtable_

#define INFRA_OBJECT_DEFINE_VTABLE(comptime_name) \
  const struct _infra_object_vtable k_ ## comptime_name ## _vtable_ =

#define INFRA_OBJECT_VTABLE(comptime_name) \
  (&k_ ## comptime_name ## _vtable_)


struct _infra_object_header {
  struct _infra_object_vtable const *vtable;
  intmax_t ref_count;
};


static inline void *
infra_object_ref(void *p)
{
  if (p == NULL)
    return NULL;

  struct _infra_object_header *header = header;

  header->ref_count += 1;

  return p;
}

void infra_object_unref(void *p);

static inline void
infra_clear_pointer_(struct _infra_object_header * volatile *ref)
{
  if (ref == NULL)
    return;

  infra_object_unref(*ref);
  *ref = NULL;
}

#endif /* _infra_object_h_ */

