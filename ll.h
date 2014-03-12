#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define null NULL

typedef int bool;

struct i_item {
    int value;
    struct i_item * next;
};

typedef struct i_item * list;

list reverse(list);
list cons(int, list);
int car(list);
list cdr(list);
int sum(list);
int fsum(list, int (*)(int));
bool empty(list);
int fact(list);
list range(int);
void delete(list);
