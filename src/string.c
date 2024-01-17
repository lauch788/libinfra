/*
 * Copyright 2024 Adrien Ricciardi
 * See LICENSE for details
 */
#include <assert.h>
#include <stdlib.h>
#include <grapheme.h>
#include <infra/string.h>

static void maybe_grow(InfraString *string, size_t need);

static const uint16_t k_infra__string_grow_step = 4;

InfraString *
infra_string_create(void)
{
  InfraString *string;

  string = calloc(sizeof (*string), 1);

  uint16_t init_capacity = k_infra__string_grow_step;
  char *data = calloc(init_capacity, 1);

  string->data = data;
  string->capacity = init_capacity;

  return infra_string_ref(string);
}

void
infra__string_free(InfraString *string)
{
  free(string->data);
  free(string);
}

static void
maybe_grow(InfraString *string, size_t need)
{
  size_t new_size = string->size + need;

  if (new_size >= string->capacity) {
    size_t new_capacity;

    for (new_capacity = string->capacity;
         new_size >= new_capacity;
         new_capacity += k_infra__string_grow_step) ;

    char *new_data = calloc(new_capacity, 1);

    memcpy(new_data, string->data, string->size);
    free(string->data);

    string->data = new_data;
    string->capacity = new_capacity;
  }

}

void
infra_string_put_char(InfraString *string, char c)
{
  maybe_grow(string, 1);
  string->data[string->size++] = c;
}

void
infra_string_put_unicode(InfraString *string, uint32_t c)
{
  char utf8[10] = { 0 };
  size_t written;

  written = grapheme_encode_utf8(c, utf8, sizeof (utf8));
  maybe_grow(string, written);

  memcpy(&string->data[string->size], utf8, written);
  string->size += written;
}

void
infra_string_put_chunk(InfraString *string, const char *chunk,
                       size_t chunk_len)
{
  assert(chunk != NULL);

  maybe_grow(string, chunk_len);
  memcpy(&string->data[string->size], chunk, chunk_len);
  string->size += chunk_len;
}

InfraString *
infra_string_from_cstring(const char *cstring)
{
  InfraString *string = infra_string_create();
  size_t slen = strlen(cstring);

  infra_string_put_chunk(string, cstring, slen);

  return string;
}

InfraString *
infra_string_clone(const InfraString *src)
{
  InfraString *clone;

  clone = calloc(sizeof (*clone), 1);

  clone->capacity = src->capacity;
  clone->size = src->size;
  clone->data = calloc(src->capacity, 1);
  memcpy(&clone->data[0], &src->data[0], src->size);

  return infra_string_ref(clone);
}
