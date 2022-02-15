#include "list.h"         

void ListCtor (list* lst, size_t elem_num)
{
    if (elem_num < 10 )
    {
        elem_num = 10;
    }
    lst->start_ptr = (list_elem*) calloc (elem_num, sizeof(list_elem));
    if (NULL == lst->start_ptr)                                 
    {                                                       
        /*dump*/                                            
        return;                                             
    }

    lst->capacity = elem_num;

    DATA(0) = POISON;
    NEXT(0) = ZERO;
    PREV(0) = ZERO;
    for (int i  = 1 ; i < elem_num - 1 ; i++)
    {
        NEXT(i) = (i + 1);
        PREV(i) = -1;
    }
    NEXT(elem_num - 1) = 0;
    PREV(elem_num - 1) = -1;
}

void ListInsert (list* lst, index_t pr_i, elem_t new_elem)
{
    index_t new_free = lst->start_ptr[lst->free].next;

    if (pr_i > 0)
    {
        DATA(lst->free) = new_elem;
        NEXT(lst->free) = NEXT(pr_i);
        PREV(lst->free) = pr_i;

        lst->start_ptr[pr_i].next = lst->free;

        if (lst->tail != pr_i)//tail
        {
           PREV(NEXT(pr_i)) = lst->free; 
        }
        else
        {
            lst->tail = lst->free;
        }
    }
    if (pr_i == 0)//head
    {
        DATA(lst->free) = new_elem;
        NEXT(lst->free) = lst->head;
        PREV(lst->free) = ZERO;

        lst->head = lst->free;
    }

    lst->free = new_free;
}

void ListDelete (list* lst, index_t del)
{
    DATA(del) = POISON;

    if (del != lst->head) //head
    {
        NEXT(PREV(del)) = NEXT(del);
    }
    else
    {
        lst->head = NEXT(del);
    }
    if (del != lst->tail)//tail
    {
        PREV(NEXT(del)) = PREV(del);
    }
    else
    {
        lst->tail = PREV(del);
    }

    NEXT(del) = lst->free;
    PREV(del) = -1;
}

void ListDtor (list* lst)
{
    free(lst->start_ptr);
    free(lst);
}