
#include <string.h>

void parse_querystring(char *qs, void *data, void (*pair)(void *, char *,char *)) {
  char *ands, *ands_r;
  char *equals, *equals_r;
  char *first;
  char *second;
  
  if (qs && qs[0] == '?')
    qs++;

  ands = strtok_r(qs, "&", &ands_r);
  while (ands != NULL) {
      first = strtok_r(ands, "=", &equals_r);
      second = strtok_r(NULL, "=", &equals_r);
      pair(data, first, second);
      ands = strtok_r(NULL, "&", &ands_r);
    }
}

