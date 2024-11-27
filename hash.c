#include "hash.h"

#include <stdlib.h>
#include <string.h>

int hash_function(char *key, int size) {
    unsigned long hash = 0;
    char *xx;
    for (xx = key; *xx != '\0'; xx++) {
        hash = 31 * hash + *xx;
    }
    return hash % size;
}

Hashtable *hash_create(int size) {
    Hashtable *a = malloc(sizeof(Hashtable));
    if (a == NULL)
        return NULL;
    a->size = size;
    a->hash = malloc(sizeof(LL *) * size);
    if (a->hash == NULL) {
        free(a);
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        a->hash[i] = list_create();
        if (a->hash[i] == NULL) {
            while (i-- > 0)
                list_destroy(&(a->hash[i]));
            free(a->hash);
            free(a);
            return NULL;
        }
    }
    return a;
}

bool hash_remove(Hashtable *a, char *key) {
    if (!a || !key)
        return false;
    int index = hash_function(key, a->size);
    return list_remove(a->hash[index], key);
}
void hash_destroy(Hashtable **a) {
    if (a && *a) {
        for (int i = 0; i < (*a)->size; i++) {
            if ((*a)->hash[i]) {
                list_destroy(&((*a)->hash[i]));
            }
        }
        free((*a)->hash);
        free(*a);
        *a = NULL;
    }
}

bool hash_put(Hashtable *a, char *key, void *value) {
    if (!a || !key)
        return false;
    int index = hash_function(key, a->size);
    return list_insert(a->hash[index], key, value);
}

void *hash_get(Hashtable *a, char *key) {
    if (!a || !key)
        return NULL;
    int index = hash_function(key, a->size);
    return list_search(a->hash[index], key);
}
