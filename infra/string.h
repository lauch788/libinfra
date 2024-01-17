#ifndef _LIBINFRA_STRING_H
#define _LIBINFRA_STRING_H

#include <stdint.h>
#include <string.h>

typedef struct InfraString_s {
  char *    data;
  int32_t   refcnt;
  uint16_t  size;
  uint16_t  capacity;
} InfraString;

InfraString *infra_string_create(void);
void infra__string_free(InfraString *string);

static inline InfraString *
infra_string_ref(InfraString *string)
{
  if (string != NULL)
    string->refcnt++;

  return string;
}

static inline void
infra_string_unref(InfraString *string)
{
  if (string != NULL && --string->refcnt <= 0)
    infra__string_free(string);
}

static inline void
infra_string_zero(InfraString *string)
{
  if (string != NULL)
    memset(string->data, 0, string->capacity);
}

void infra_string_put_char(InfraString *string, char c);
void infra_string_put_unicode(InfraString *string, uint32_t c);
void infra_string_put_chunk(InfraString *string, const char *chunk, size_t chunk_len);

InfraString *infra_string_from_cstring(const char *cstring);

InfraString *infra_string_clone(const InfraString *string);

#endif /* _LIBINFRA_STRING_H */
