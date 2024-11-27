#include "hash.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *x;
    int value;
} Items;

void freeItem(void *item);
int main() {
    char x[MAX_LINE_SIZE];
    Hashtable *ht = hash_create(65536);
    if (!ht) {
        fprintf(stderr, "Failed to create hash table\n");
        return EXIT_FAILURE;
    }

    int Count = 0;
    while (fgets(x, MAX_LINE_SIZE, stdin)) {
        x[strcspn(x, "\n")] = 0;
        if (!hash_get(ht, x)) {
            Items *newItem = malloc(sizeof(Items));
            newItem->x = strdup(x);
            newItem->value = 1;
            if (!hash_put(ht, newItem->x, newItem)) {
                free(newItem->x);
                free(newItem);
                continue;
            }
            Count = Count + 1;
        }
    }

    printf("%d\n", Count);
    hash_destroy(&ht, freeItem);

    return EXIT_SUCCESS;
}

void freeItem(void *item) {
    Items *lineItem = (Items *) item;
    free(lineItem->x);
    free(lineItem);
}
