#include "LRU.h"

size_t Get_Size ()
{
    return 5;
}

elem_t  Get_elem ()
{
    elem_t current;
    PRINT_LINE
    scanf (FORMAT_LIST_ELEM, &current);
    PRINT_LINE
    return current;
}

void Push_elem  (elem_t current, list* lst)
{   
    if (lst->size == lst->capacity - 1)
    {
        index_t cell = ListSearch (current, lst);

        if (cell == BASE)
        {
            ListDelete (lst, lst->tail);
        }
        else
        {
            ListDelete (lst, cell);
        }
        
    }
    ListInsert (lst, BASE, current);
}