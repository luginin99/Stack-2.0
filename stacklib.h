#ifndef  _stacklib_H_
#define  _stacklib_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Stack
{
    int* data;
    size_t capacity = 0;
    size_t size = 0;
};

void StackPush       (Stack* stk, int value);
int  StackPop        (Stack* stk);
void StackClean      (Stack* stk);
int  StackTop        (Stack* stk);
int  StackSize       (Stack* stk);
int  StackEmpty      (Stack* stk);
int  StackIsFull     (Stack* stk);
int  StackOK         (Stack* stk);
void StackDump       (Stack* stk);
void StackCreate     (Stack* stk, int capacity);
void StackDestroy    (Stack* stk);
void StackChangeSize (Stack* stk, int new_capacity);

#include "OwnStack.cpp"
#endif // _stacklib_H_
