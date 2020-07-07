#include "hasmap.h"

Hashmap_ptr create_hashmap(int length)
{
  Hashmap_ptr new_hashmap = malloc(sizeof(Hashmap));
  new_hashmap->array = malloc(sizeof(Hash_ptr) * length);
  new_hashmap->capacity = length;
  return new_hashmap;
}

Hash_ptr create_hash(void *key, void *value)
{
  Hash_ptr hash = malloc(sizeof(Hash));
  hash->key = key;
  hash->value = value;
  return hash;
}

int hash_function(void *key, int size)
{
  unsigned long int i = 0;
  for (int j = 0; j < strlen(key); j++)
  {
    i += (((char *)key)[j]);
  }
  return i % size;
}

void set(Hashmap_ptr hashmap, void *key, void *value)
{
  Hash_ptr hash = create_hash(key, value);
  int index = hash_function(key, hashmap->capacity);

  while (hashmap->array[index] != NULL && strcmp(hashmap->array[index]->key, key) != 0)
  {
    index++;
  }

  hashmap->array[index] = hash;
}

void *get(Hashmap_ptr hashmap, void *key)
{
  int index = hash_function(key, hashmap->capacity);
  int is_not_found = 1;
  void *value = NULL;

  while (is_not_found && hashmap->array[index] != NULL)
  {
    if (strcmp(hashmap->array[index]->key, key) == 0)
    {
      value = hashmap->array[index]->value;
      is_not_found = 0;
    }
    index++;
  }

  return value;
}
