#ifndef LIST_H
#define LIST_H

#include <iostream>

typedef int elem_t;
#define FORMAT_LIST_ELEM "%d"

typedef int index_t;
#define FORMAT_LIST_INDEX "%d"

const int ZERO = 0;
const int POISON = 1488;

struct list_elem
{
    index_t prev;
    elem_t data;
    index_t next;
};

struct list
{
    list_elem*  start_ptr;
    size_t      size = 0;
    size_t      capacity;
    index_t     free = 1;
    index_t     head = 0;
    index_t     tail = 1;
};

#undef TAIL
#define TAIL lst->tail

#undef PREV
#undef DATA
#undef NEXT
#define PREV(i) lst->start_ptr[i].prev
#define DATA(i) lst->start_ptr[i].data
#define NEXT(i) lst->start_ptr[i].next

void            ListCtor            (list* lst, size_t elem_num);

void            ListInsert          (list* lst, index_t pr_i, elem_t new_elem);

void            ListDelete          (list* lst, index_t del_i);

void            ListDtor            (list *lst);

void            ListDump            (list* lst);

#endif 