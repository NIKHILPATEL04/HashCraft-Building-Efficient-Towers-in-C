#include "ll.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

LL *list_create() {
    LL *l = (LL *) malloc(sizeof(LL));
    if (l == NULL) {
        return NULL;
    }
    l->head = NULL;
    l->end = NULL;
    return l;
}

void list_remove(LL *l, bool (*cmp)(item *, item *), item *i) {
    if (l == NULL || l->head == NULL)
        return;

    Node *x = l->head;
    Node *backx = NULL;

    while (x != NULL) {
        if (cmp(&x->data, i)) {
            if (backx == NULL) {
                l->head = x->next;
            } else {
                backx->next = x->next;
            }

            if (x == l->end) {
                l->end = backx;
            }

            free(x);
            return;
        }
        backx = x;
        x = x->next;
    }
}

bool list_add(LL *l, item *i) {
    Node *n = (Node *) malloc(sizeof(Node));
    if (n == NULL) {
        return false;
    }
    n->data = *i;
    n->next = NULL;
    if (l->head == NULL) {
        l->head = n;
    } else {
        l->end->next = n;
    }
    l->end = n;
    return true;
}

item *list_find(LL *l, bool (*cmp)(item *, item *), item *i) {
    Node *n = l->head;
    while (n != NULL) {
        if (cmp(&n->data, i)) {
            return &n->data;
        }
        n = n->next;
    }
    return NULL;
}

void list_destroy(LL **list) {
    if (list == NULL || *list == NULL)
        return;

    Node *a = (*list)->head;
    Node *placeholder;

    while (a != NULL) {
        placeholder = a;
        a = a->next;
        free(placeholder);
    }
    free(*list);
    *list = NULL;
}
