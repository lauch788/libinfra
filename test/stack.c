#include <stdio.h>
#include <infra/util.h>
#include <infra/stack.h>

static char *k_dummy_strings[] = {
 "🗚 🗚 🗚 🗚",
  "⚓",
  "🏷",
  "🔔",
  "⚕",
};

#define NUM_RUNS 3

int
main(int argc, char *argv[])
{
  (void) argc;
  (void) argv;

  for (int _ = 0; _ < NUM_RUNS; _++)
  {
    InfraStack *stack = infra_stack_create();

    for (int i = 0; i < (int)INFRA_COUNTOF(k_dummy_strings); i++)
    {
      infra_stack_push(stack, k_dummy_strings[i]);
    }

    const char *s;
    while ((s = infra_stack_pop(stack)))
    {
      // printf("%s\n", s);
    }

    infra_stack_free(stack);
  }

  return 0;
}
