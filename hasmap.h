#ifndef __HASHMAP_H__
#define __HASHMAP_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  void *key;
  void *value;
} Hash;

typedef Hash *Hash_ptr;

typedef struct
{
  Hash_ptr *array;
  int capacity;
} Hashmap;

typedef Hashmap *Hashmap_ptr;

Hashmap_ptr create_hashmap(int length);
Hash_ptr create_hash(void *key, void *value);
int hash_function(void *key, int size);
void set(Hashmap_ptr hashmap, void *key, void *value);
void *get(Hashmap_ptr hashmap, void *key);

#endif
