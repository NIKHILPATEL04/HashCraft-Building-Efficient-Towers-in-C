#ifndef _HASH

#define _HASH
#include "item.h"
#include "ll.h"

#include <stdbool.h>

typedef struct Hashtable {
    LL **hash;
    int size;
} Hashtable;

Hashtable *hash_create(int size);

void hash_destroy(Hashtable **a);

bool hash_put(Hashtable *a, char *key, void *value);

void *hash_get(Hashtable *a, char *key);

bool hash_remove(Hashtable *a, char *key);

int hash_function(char *key, int size);

#endif
