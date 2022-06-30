#include "LRU.h"

//LIST USAGE EXAMPLE

int main ()
{
    list ABOBA;
    list* lst = &ABOBA;

    size_t size = Get_Size ();

    ListCtor (lst, size + 1);

    elem_t current = Get_elem();
printf ("21");
    while (current != 228)
    {
        
        Push_elem(current, lst);
        current = Get_elem();
    }
    
    ListDump(lst);

    ListDtor (lst);

    return 0;
}   