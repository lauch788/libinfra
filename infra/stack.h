#ifndef _LIBINFRA_STACK_H
#define _LIBINFRA_STACK_H

#include <stddef.h>
#include <stdint.h>

typedef struct InfraStack_s {
  void **   items;
  uint32_t  size;
  uint32_t  capacity;
} InfraStack;

InfraStack *infra_stack_create(void);
void infra_stack_free(InfraStack *stack);

static inline void *
infra_stack_peek(InfraStack *stack)
{
  if (stack->size == 0)
    return NULL;

  return stack->items[stack->size - 1];
}

void *infra_stack_push(InfraStack *stack, void *item);

static inline void *
infra_stack_pop(InfraStack *stack)
{
  if (stack->size == 0)
    return NULL;

  return stack->items[--stack->size];
}

#define INFRA_STACK_FOREACH(stack, index) \
  for (int index = 0; index < (stack)->size; index++)

#define INFRA_STACK_REVERSE_FOREACH(stack, index) \
  for (int index = (stack)->size - 1; index >= 0; index--)

#endif /* _LIBINFRA_STACK_H */
