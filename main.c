#include "hasmap.h"

int are_strings_equal(void *str1, void *str2)
{
  return strcmp(str1, str2) == 0;
}

int main(void)
{
  Hashmap_ptr hasmap = create_hashmap(10);
  char key[] = "hi";
  char val[] = "hello";
  char val2[] = "new value";
  char key2[] = "num";
  int num = 5;
  set(hasmap, key, val);
  set(hasmap, key, val2);
  set(hasmap, key2, &num);
  printf("%s\n", get(hasmap, key));
  printf("%d", *(int *)get(hasmap, key2));
  return 0;
}
