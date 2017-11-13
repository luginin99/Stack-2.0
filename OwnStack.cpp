#define DECLARE(name, length) Stack name; \
    StackCreate (&name, length); \

#define PRINT_NAME(name) printf(#name);
#define StackDump(stk) printf ("Stack dump from line (%d)\n", __LINE__); \
        StDump(&stk);

int StackOK (Stack* stk)
{
    if (stk == NULL)
    {
        printf ("Stack pointer = NULL\n");
        return 0;
    }

    if (stk->data==NULL)
    {
        printf ("Stack data pointer = NULL\n");
        return 0;
    }

    if (stk->size > stk->capacity)
    {
        printf ("Stack overflow\n");
        return 0;
    }
    if (stk->size < 0)
    {
        printf ("False size\n");
        return 0;
    }

    return 1;

}

void StackPush (Stack* stk, int value)
{
    assert (StackOK(stk));

    stk->data [stk->size] = value;

    stk->size ++;

}

int StackPop (Stack* stk)
{
    assert (StackOK(stk));

    assert (stk->size > 0);

    stk->size --;
    int a = stk->data [stk->size];
    stk->data [stk->size] = 0;

    assert (StackOK(stk));
    return a;
}

void StackClean (Stack* stk)
{
    assert (StackOK(stk));

    for (int i = stk->capacity - 1; i > stk->size; i--)
        stk->data[i] = 0;

    while (stk->size > 0)
    {
        stk->data[stk->size] = 0;
        stk->size --;
    }
    stk->data[stk->size] = 0;

    assert (stk->size == 0);
}

int StackTop (Stack* stk)
{
    assert (StackOK(stk));
    assert (stk->size > 0);

    return (stk->data [stk->size-1]);
}

int StackSize (Stack* stk)
{
    assert (StackOK(stk));

    return stk->size;
}

int StackEmpty (Stack* stk)
{
    assert (StackOK(stk));

    if (stk->size == 0)
        return 1;
    else
        return 0;
}

int StackIsFull (Stack* stk)
{
    assert (StackOK(stk));

    if ((stk->size) == stk->capacity)
        return 1;
    else
        return 0;
}


void StDump (Stack* stk)
{
    assert (StackOK(stk));

    printf ("Stack name - ");
    PRINT_NAME(stk);
    printf ("  0x%p\n", &stk, "Stack Dump", __LINE__);
    printf ("Stack capacity = %d      Stack capacity pointer 0x%p\n", stk->capacity, &stk->capacity);
    printf ("Stack size = %d\n", stk->size);

    if (stk->size >0)
        printf ("Stack data pointer 0x%p\n Stack data\n{\n", &stk->data);
    for (int i = 0; i < stk->capacity; i++)
    {
        if (i < stk->size)
            printf ("*  ");
        else
            printf ("   ");
        printf ("%3d", i);
        printf ("  %10d\n", stk->data[i]);
    }
    if (stk->size >0)
        printf ("}\n");
}

void StackCreate (Stack* stk, int capacity)
{
    assert (StackOK(stk));

    stk->capacity = capacity;

    stk->data  = (int*) calloc (capacity, sizeof (int));

    stk->size = 0;
}

void StackDestroy (Stack* stk)
{
    assert (StackOK(stk));

    free (stk->data);
    stk->capacity = 0;
    stk->size = 0;
}

void StackCopy (Stack* stk_old, Stack* stk_new)
{
    assert (StackOK(stk_old));
    assert (StackOK(stk_new));

    StackCreate(stk_new, stk_old->capacity);
    stk_new->size = stk_old->size;

    for (int i = 0; i < stk_old->size ; i ++)
    {
        stk_new->data[i] = stk_old->data[i];
    }

}

void StackChangeSize (Stack* stk, int new_capacity)
{
    assert (StackOK(stk));

    Stack stk_tmp;

    StackCopy (stk, &stk_tmp);

    StackCreate (stk, new_capacity);

    assert (stk_tmp.size < stk->capacity);

    for (int i = 0; i < stk_tmp.size ; i ++)
    {
        stk->data[i] = stk_tmp.data[i];
    }

    stk->size = stk_tmp.size;
}
