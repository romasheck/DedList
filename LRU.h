#ifndef LRU_H
#define LRU_H

#include "List.h"

size_t              Get_Size            ();

elem_t              Get_elem            ();

void                Push_elem           (elem_t current, list* lst);

#endif