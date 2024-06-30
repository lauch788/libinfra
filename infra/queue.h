#ifndef _LIBINFRA_QUEUE_H
#define _LIBINFRA_QUEUE_H

/*
 * Copyright 2024 (c) Adrien Ricciardi
 * This file is part of the libinfra distribution (https://github.com/rshadr/libinfra)
 * See LICENSE for details
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdbool.h>


typedef struct InfraQueue_s {
  void **items;
  int capacity;
  int length;

  int front;
  int rear;
} InfraQueue;


InfraQueue *infra_queue_create(void);
void infra_queue_free(InfraQueue *queue);


void *infra_queue_enqueue(InfraQueue *queue, void *item);
void *infra_queue_dequeue(InfraQueue *queue);


static inline bool
infra_queue_is_empty(InfraQueue const *queue)
{
  return queue->length == 0;
}


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */


#endif /* _LIBINFRA_QUEUE_H */
