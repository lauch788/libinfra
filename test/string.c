#include <stdio.h>
#include <infra/util.h>
#include <infra/string.h>
#include <grapheme.h>

static const char *k_test_cstrings[] = {
  "fhewfjewj",
  "💾🗜",
  "φοβερό…",
};

int
main(int argc, char *argv[])
{
  for (int i = 0; i < INFRA_COUNTOF(k_test_cstrings); i++) {
    InfraString *string = infra_string_from_cstring(k_test_cstrings[i]);
    size_t slen = strlen(k_test_cstrings[i]);
    
    size_t off, ret;
    uint_least32_t c = { 0 };
    for (off = 0; off < slen; off += ret) {
      if ((ret = grapheme_decode_utf8(k_test_cstrings[i] + off,
          slen - off, &c)) > (slen - off))
        break;
      infra_string_put_unicode(string, c);
    }

    infra_string_unref(string);
  }

  return 0;
}
