#include "list.h"

#define CALLOC_AND_CHECK_PTR(type, list_field)          \
list_field = (type*) calloc (elem_num, sizeof(type));   \
if (NULL == list_field)                                 \
{                                                       \
    /*dump*/                                            \
    return;                                             \
}             

void ListCtor (list* lst, size_t elem_num)
{
    if (elem_num < 10 )
    {
        elem_num = 10;
    }
    CALLOC_AND_CHECK_PTR(list_elem, lst->start_ptr)

    lst->capacity = elem_num;

    lst->start_ptr->next = ZERO;
    lst->start_ptr->prev = ZERO;

    for (int i  = 1 ; i < elem_num - 1 ; i++)
    {
        (lst->start_ptr + i)->next = (i + 1);
        (lst->start_ptr + i)->prev = -1;
    }
    (lst->start_ptr + elem_num - 1)->next = 0;
    (lst->start_ptr + elem_num - 1)->prev = -1;
}

void ListInsert (list* lst, index_t pr_i, elem_t new_elem)
{
    index_t new_free = lst->start_ptr[lst->free].next;
    if (pr_i > 0)
    {
        lst->start_ptr[lst->free].data = new_elem;
        lst->start_ptr[lst->free].next = lst->start_ptr[pr_i].next;
        lst->start_ptr[lst->free].prev = pr_i;

        lst->start_ptr[lst->start_ptr[pr_i].next].prev = lst->free;
        lst->start_ptr[pr_i].next = lst->free;
    }
    if (pr_i == 0)
    {
        lst->start_ptr[lst->free].data = new_elem;
        lst->start_ptr[lst->free].next = lst->head;
        lst->start_ptr[lst->free].prev = ZERO;

        if (lst->head > 0)
        {
            lst->start_ptr[lst->head].prev = lst->free;
        }

        lst->head = lst->free;
    }
    lst->free = new_free;
}

void ListDtor (list* lst)
{
    free(lst->start_ptr);
    free(lst);
}