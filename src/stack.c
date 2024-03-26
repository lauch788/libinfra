/*
 * Copyright 2024 Adrien Ricciardi
 * See LICENSE for details
 */
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <infra/stack.h>

static void maybe_grow(InfraStack *stack, size_t need);

static const uint32_t k_infra__stack_grow_step = 4;

InfraStack *
infra_stack_create(void)
{
  InfraStack *stack;

  stack = calloc(sizeof (*stack), 1);

  int32_t init_capacity = k_infra__stack_grow_step;
  stack->capacity = init_capacity;

  void **items = calloc(init_capacity, sizeof (void *));
  stack->items = items;

  return stack;
}

void
infra_stack_free(InfraStack *stack)
{
  free(stack->items);
  free(stack);
}

static void
maybe_grow(InfraStack *stack, size_t need)
{
  int32_t new_size = stack->size + need;

  if (new_size > stack->capacity) {
    int32_t new_capacity = stack->capacity + k_infra__stack_grow_step;
    stack->capacity = new_capacity;

    void **new_items = calloc(new_capacity, sizeof (void *));
    memcpy(new_items, stack->items, stack->size * sizeof (void *));
    free(stack->items);
    stack->items = new_items;
  }

}

void *
infra_stack_push(InfraStack *stack, void *item)
{
  maybe_grow(stack, 1);
  stack->items[stack->size++] = item;

  return item;
}

void
infra_stack_insert(InfraStack *stack, int idx, void *item)
{
  assert(idx >= 0 && idx < stack->size);

  maybe_grow(stack, 1);
  memmove(&stack->items[idx], &stack->items[idx + 1],
   (stack->size - idx) * sizeof (stack->items[0]));
  stack->items[idx] = item;
}
