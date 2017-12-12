#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define DECLARE(name, length) Stack name; \
    StackCreate (&name, length);

#define DECLARE_int(name, length) Stack_int name; \
    StackCreate_int (&name, length);

typedef char T;


struct Stack
{
    T* data;
    int capacity;
    int size;
};

void StackPush (Stack* stk, T value);
T StackPop (Stack* stk);
T StackTop (Stack* stk);
void StackCreate (Stack* stk, int capacity);
int StackEmpty (Stack* stk);

struct Stack_int
{
    int* data;
    int capacity;
    int size;
};
void StDump (Stack* stk);
void StackPush_int (Stack_int* stk, int value);
int StackPop_int (Stack_int* stk);
void StackCreate_int (Stack_int* stk, int capacity);
void StackDiv (Stack_int* stk);
void StackMul (Stack_int* stk);
void StackSub (Stack_int* stk);
void StackAdd (Stack_int* stk);
void FromBufToPol (char* buf[], char* Pol[]);
int Polresult (char** Pol);


int main()
{
    int sum = 0;
    char* buf;
    char* PolBuf;
    buf = (char*) calloc (1000, sizeof(char));
    PolBuf = (char*) calloc (1000, sizeof(char));
    gets(buf);
    FromBufToPol (&buf, &PolBuf);
  //  printf ("%s\n", PolBuf);
    sum = Polresult (&PolBuf);
    printf ("%d\n", sum);
}

void FromBufToPol (char** buf, char** Pol)
{
    int i = 0;
    int j = 0;
    char f;
    DECLARE(stk, 100);
    if ((*buf)[i] == '-')
        {
            (*Pol)[j] = '0';
            j++;
            (*Pol)[j] = ' ';
            j++;
        }
    while ((*buf)[i]!='\0')
    {
        switch ((*buf)[i])
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            while (isdigit((*buf)[i]))
            {
                (*Pol)[j] = (*buf)[i];
                j++;
                i++;
            }
            (*Pol)[j] = ' ';
            j++;
            break;
        case '+':
        case '-':
            if (!StackEmpty (&stk))
                if (StackTop (&stk) != '(')
                {
                    (*Pol)[j] = StackPop (&stk);
                    j++;
                    (*Pol)[j] = ' ';
                    j++;
                }
            else;
            StackPush (&stk, (*buf)[i]) ;
            i++;
            break;
        case '*':
        case '/':
            if (!StackEmpty (&stk))
                if (StackTop (&stk) == '*' || StackTop (&stk) == '/')
                {
                    (*Pol)[j] = StackPop (&stk);
                    j++;
                    (*Pol)[j] = ' ';
                    j++;
                }
            else;
            StackPush (&stk, (*buf)[i]) ;
            i++;
            break;
        case '(':
           StackPush (&stk, (*buf)[i]) ;
           i++;
           if ((*buf)[i] == '-')
               {
                    (*Pol)[j] = '0';
                    j++;
                    (*Pol)[j] = ' ';
                    j++;
               }
           break;
        case ')':
            f=StackPop (&stk);
            while (f != '(')
            {
                (*Pol)[j] = f;
                j++;
                (*Pol)[j] = ' ';
                j++;
                f = StackPop (&stk);
            }
            i++;
            break;
        case ' ':
            i++;
            break;
        }
    }
    while (!StackEmpty (&stk))
    {
        (*Pol)[j] = StackPop (&stk);
        j++;
        (*Pol)[j] = ' ';
        j++;
    };
    (*Pol) [j] = '\0';

}


int Polresult (char** Pol)
{
    int i = 0;
    int a = 0;
    int NumberOfDigits = 0;
    int j = 0;
    char* c_a;
    c_a = (char*) calloc (12, sizeof(char));
    DECLARE_int(stk, 100);
    while ((*Pol)[i] != '\0')
    {
        switch ((*Pol)[i])
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            a = atoi (&(*Pol)[i]);
            StackPush_int(&stk, a);
            while (a!=0)
            {
                a = a/10;
                NumberOfDigits ++;
            }
            i+= NumberOfDigits;
            NumberOfDigits = 0;
            break;
        case '+':
            StackAdd(&stk);
            i++;
            break;
        case '-':
            StackSub(&stk);
            i++;
            break;
        case '*':
            i++;
            StackMul (&stk);
            break;
        case '/':
            i++;
            StackDiv (&stk);
            break;
        case ' ':
            i++;
            break;
        }
    }
    return StackPop_int (&stk);

}


void StackAdd (Stack_int* stk)
{

    int a = StackPop_int (stk);
    int b = StackPop_int (stk);

    StackPush_int(stk, a+b);
}

void StackSub (Stack_int* stk)
{

    int a = StackPop_int (stk);
    int b = StackPop_int (stk);

    StackPush_int(stk, b-a);
}

void StackMul (Stack_int* stk)
{

    int a = StackPop_int (stk);
    int b = StackPop_int (stk);

    StackPush_int(stk, a*b);
}

void StackDiv (Stack_int* stk)
{

    int a = StackPop_int (stk);
    int b = StackPop_int (stk);
    StackPush_int(stk, b/a);
}

void StackPush (Stack* stk, T value)
{

    stk->data [stk->size] = value;

    stk->size ++;

}

T StackPop (Stack* stk)
{


    stk->size --;
    T a = stk->data [stk->size];
    stk->data [stk->size] = 0;

    return a;
}
T StackTop (Stack* stk)
{

    return (stk->data [stk->size-1]);
}

void StackCreate (Stack* stk, int capacity)
{


    stk->capacity = capacity;

    stk->data  = (T*) calloc (capacity, sizeof (T));

    stk->size = 0;
}

int StackEmpty (Stack* stk)
{

    if (stk->size == 0)
        return 1;
    else
        return 0;
}

void StDump (Stack* stk)
{
    int i = 0;
    printf ("Stack:\n");
    for (i = 0; i < stk->size; i++)
    {
        if (i < stk->size)
        printf ("%c  ", stk->data[i]);
    }
}


void StackPush_int (Stack_int* stk, int value)
{

    stk->data [stk->size] = value;
    stk->size ++;

}

int StackPop_int (Stack_int* stk)
{


    stk->size --;
    int a = stk->data [stk->size];
    stk->data [stk->size] = 0;

    return a;
}

void StackCreate_int (Stack_int* stk, int capacity)
{
    stk->capacity = capacity;
    stk->data  = (int*) calloc (capacity, sizeof (int));
    stk->size = 0;
}

