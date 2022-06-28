#include "List.h"

//LIST USAGE EXAMPLE

int main ()
{
    list ABOBA;
    list* lst = &ABOBA;

    ListCtor (lst, 10);

    ListInsert(lst, ZERO , 10);
    ListInsert(lst, lst->head , 40);
    ListInsert(lst, 1 , 60);
    ListInsert(lst, lst->tail , 40);
    ListDelete(lst, 2);
    ListInsert(lst, ZERO , 35);

    ListDump(lst);

    ListDtor (lst);

    return 0;
}   