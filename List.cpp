#include "list.h"         

void ListCtor (list* lst, size_t elem_num)
{
    if (elem_num < 10 )
    {
        //elem_num = 10;
    }

    lst->base = (list_elem*) calloc (elem_num, sizeof(list_elem));
    if (NULL == lst->base)                                 
    {                                                       
        /*dump*/
        printf("LIST START PTR IS NULL (PTR CALLOCATION ERROR)!!!!!!!!!");
        return;
    }

    lst->capacity = elem_num;

    DATA(0) = POISON;
    NEXT(0) = BASE;
    PREV(0) = BASE;
    for (int i  = 1 ; i < elem_num ; i++)
    {
        NEXT(i) = (i + 1);
        DATA(i) = POISON;
        PREV(i) = -1;
    }
    NEXT(elem_num - 1) = 0;
    PREV(elem_num - 1) = -1;
}

void ListInsert (list* lst, index_t pr_i, elem_t new_elem)
{
    index_t new_free = NEXT(lst->free);

    if (pr_i > BASE)
    {
        DATA(lst->free) = new_elem;//
        NEXT(lst->free) = NEXT(pr_i);//
        PREV(lst->free) = pr_i;

        if (lst->tail != pr_i)
        {
           PREV(NEXT(pr_i)) = lst->free; 
           
        }
        else//tail
        {
            lst->tail = lst->free;
        }

        NEXT(pr_i) = lst->free;
    }
    if (pr_i == BASE)//head
    {
        DATA(lst->free) = new_elem;
        NEXT(lst->free) = lst->head;
        PREV(lst->free) = BASE;

        PREV(lst->head) = lst->free;

        lst->head = lst->free;
    }

    lst->free = new_free;
    lst->size++;
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
    lst->free = del;
    PREV(del) = -1;
    lst->size--;
}

void ListDtor (list* lst)
{
    free(lst->base);
    free(lst);
}

#undef FPRINT
#undef COMMA
#undef FPRINT_ELEM 
#define FPRINT(data) fprintf(log_file, data); 
#define COMMA ,
#define FPRINT_ELEM(j)                  \
FPRINT("    \"%d \\n " COMMA j)         \
FPRINT("PREV = ")                       \
FPRINT(FORMAT_LIST_INDEX COMMA PREV(j)) \
FPRINT(" \\n ")                         \
FPRINT("DATA = ")                       \
FPRINT(FORMAT_LIST_ELEM COMMA DATA(j))  \
FPRINT(" \\n ")                         \
FPRINT("NEXT = ")                       \
FPRINT(FORMAT_LIST_INDEX COMMA NEXT(j)) \
FPRINT(" \\n ")                         \
FPRINT("\"")

void ListDump (list* lst)
{
    FILE* log_file = fopen("log_file.txt", "w");

    //FPRINT("<graph>")
    FPRINT("digraph G{\n")
    FPRINT("    graph [ rankdir=UD ]\n")

    for (index_t i = 0; i < lst->capacity - 1; i++)
    {
        FPRINT_ELEM(i)
        FPRINT(" -> ")
        FPRINT_ELEM(i + 1)
        FPRINT(" [ style=invis ]")
        FPRINT("\n")
    }

    index_t cur_i = lst->head;
    while (NEXT(cur_i) != 0)
    {
        FPRINT_ELEM(cur_i)
        FPRINT(" -> ")
        FPRINT_ELEM(NEXT(cur_i))
        FPRINT(" [ color = blue ]")
        cur_i = NEXT(cur_i);
        FPRINT("\n")
    }

    cur_i = lst->free;
    while (NEXT(cur_i)!= 0)
    {
        FPRINT_ELEM(cur_i)
        FPRINT(" -> ")
        FPRINT_ELEM(NEXT(cur_i))
        FPRINT(" [ color = red ]")
        cur_i = NEXT(cur_i);
        FPRINT("\n")
    }
    FPRINT("}")
    //FPRINT("</graph>")

    fclose(log_file);

    system ("\"C:/Program Files/Graphviz/bin/dot.exe\" -Tpng log_file.txt -o ListLog.png");
}

#undef FPRINT
#undef COMMA
#undef FPRINT_ELEM

index_t ListSearch (elem_t desired, list* lst)
{
    if (DATA(lst->head) == desired)
    {
        return lst->head;
    }

    index_t answer = lst->head;

    while(1)
    { 
        if (DATA(NEXT(answer)) != desired)
        {
            answer = NEXT(answer);
        }
        else
        {
            return NEXT(answer);
        }

        if (answer == 0)
        {
            break;
        }
    } 

    return BASE;
}

