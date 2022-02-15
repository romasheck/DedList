#include "List.h"

int main ()
{
    list ABOBA;
    list* lst = &ABOBA;

    ListCtor (lst, 10);

    ListInsert(lst, 0 , 10);
    ListInsert(lst, lst->head , 40);
    ListInsert(lst, 0 , 35);

    printf ("%d", DATA(lst->head));

    return 0;
}