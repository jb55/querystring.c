
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "querystring.h"

struct parsed_data {
  char *name;
  int age;
};

void parser(void *data, char *fst, char *snd) {
  struct parsed_data *parsed_data = (struct parsed_data*)data;

  if (strcmp(fst, "name") == 0) {
    parsed_data->name = snd;
  }
  else if (strcmp(fst, "age") == 0) {
    parsed_data->age = atoi(snd);
  }
}

int main() {
  struct parsed_data data = {
    .name = "Anonymous",
    .age  = -1
  };
  char *qs = getenv("QUERY_STRING");
  parse_querystring(qs, (void*)&data, parser);

  printf("name: %s, age: %d\n", data.name, data.age);
}
