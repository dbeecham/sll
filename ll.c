#include "ll.h"


list reverse(list cur) { // {{{
    // Handle edge-cases
    if (!cur) return cur;
    if (!cur->next) return cur;


    // We need to keep track of the first to remove it's 'next' link
    list first = cur;
    list prev = cur;
    list next = null;
    cur = cur->next;

    int breaking = false;
    while (true) {
        if (!cur->next) breaking = true;
        else next = cur->next;

        cur->next = prev;

        if (breaking) break;

        prev = cur;
        cur = next;
    }
    first->next = null;

    return cur;
} // }}}

list cons(int x, list xs) { // {{{
    list tmp = (list) malloc(sizeof(struct i_item));
    tmp->next = xs;
    tmp->value = x;
    return tmp;
} // }}}

bool empty(list xs) { // {{{
    if (!xs) return true;
    return false;
} // }}}

int car(list xs) { // {{{
    return xs->value;
} // }}}

list cdr(list xs) { // {{{
    if (empty(xs)) return xs;
    return xs->next;
} // }}}

int sum(list xs) { // {{{
    if (empty(xs)) return 0;
    return car(xs) + sum(cdr(xs));
} // }}}

int fsum(list ptr, int (*filter)(int)) { // {{{
    if (empty(ptr)) return 0;
    if (!filter(car(ptr))) return fsum(cdr(ptr), filter);
    return car(ptr) + fsum(cdr(ptr), filter);
} // }}}

list range(int x) { // {{{
    list l = null;
    for (int i = 0; i < x; i++) {
        l = cons((i + 1), l);
    }
    return l;
} // }}}

void delete(list xs) { // {{{
    if (empty(xs)) return;

    delete(cdr(xs));
    free(xs);
} // }}}

int fact(list ptr) { // {{{
    if (empty(ptr)) return 1;
    return car(ptr) * fact(cdr(ptr));
} // }}}
