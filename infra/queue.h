#ifndef _LIBINFRA_QUEUE_H
#define _LIBINFRA_QUEUE_H

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

static inline int
infra_queue_is_empty(const InfraQueue *queue)
{
  return queue->length == 0;
}

#endif /* _LIBINFRA_QUEUE_H */
