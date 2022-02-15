#ifndef LIST_H
#define LIST_H

#include <iostream>

typedef int elem_t;
#define FORMAT_LIST_ELEM "%d"

typedef int index_t;
#define FORMAT_LIST_INDEX "%d"

#define POISON 1488

#define ZERO 0

struct  list_elem
{
    index_t prev;
    elem_t data = 1488;
    index_t next;
};


struct list 
{
    list_elem*  start_ptr;
    size_t      size = 0;
    size_t      capacity;
    index_t     free = 1;
    index_t     head = 0;
    index_t     tail = 0;
};

void            ListCtor            (list* lst, size_t elem_num);

void            ListInsert          (list* lst, index_t pr_i, elem_t new_elem);

void            ListDtor            (list *lst);

#endif 