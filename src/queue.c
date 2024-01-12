#include <infra/queue.h>

#include <stdlib.h>
#include <string.h>

static void infra__queue_double_capacity(InfraQueue *q);

static const int k_infra__queue_start_capacity = 4;

InfraQueue *
infra_queue_create(void)
{
  InfraQueue *q = calloc(1, sizeof (*q));

  q->capacity = k_infra__queue_start_capacity;
  q->items = calloc(q->capacity, sizeof (q->items[0]));

  q->length = 0;
  q->rear = -1;

  return q;
}

void
infra_queue_free(InfraQueue *queue)
{
  free(queue->items);
  free(queue);
}

static void
infra__queue_double_capacity(InfraQueue *q)
{
  int new_capacity = q->capacity * 2;
  void **new_items = calloc(new_capacity, sizeof (q->items[0]));

  if (q->length > 0 && q->front >= q->rear)
  {
    int offset_from_end = q->capacity - q->front;

    memcpy(&new_items[0], &q->items[0], (q->rear + 1) * sizeof (q->items[0]));

    int new_front = new_capacity - offset_from_end;

    memcpy(&new_items[new_front], &q->items[q->front],
     offset_from_end * sizeof (q->items[0]));

    q->front = new_front;
  }

  else
  {
    memcpy(&new_items[0], &q->items[0], q->capacity * sizeof (q->items[0]));
  }

  q->capacity = new_capacity;
  free(q->items);
  q->items = new_items;
}

void *
infra_queue_enqueue(InfraQueue *q, void *item)
{
  if (q->length == q->capacity)
    infra__queue_double_capacity(q);

  q->rear = (q->rear + 1) % q->capacity;

  q->items[q->rear] = item;
  q->length++;

  return item;
}

void *
infra_queue_dequeue(InfraQueue *q)
{
  if (q->length == 0)
    return NULL;

  void *item = q->items[q->front];

  q->front = (q->front + 1) % q->capacity;
  q->length--;

  return item;
}
