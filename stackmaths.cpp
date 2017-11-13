#include "stacklib.h"

void StackAdd        (Stack* stk);
void StackSub        (Stack* stk);
void StackMul        (Stack* stk);
void StackDiv        (Stack* stk);
void Stacksqr        (Stack* stk);
void Stacksqrt       (Stack* stk);
void StackLinEq      (Stack* stk);
void StackReverseSub (Stack* stk);
void StackReverseDiv (Stack* stk);

void StackAdd (Stack* stk)
{
    assert (StackOK(stk));
    assert (StackSize (stk) > 1);

    int a = StackPop (stk);
    int b = StackPop (stk);

    StackPush(stk, a+b);
}

void StackSub (Stack* stk)
{
    assert (StackOK(stk));
    assert (StackSize (stk) > 1);

    int a = StackPop (stk);
    int b = StackPop (stk);

    StackPush(stk, a-b);
}

void StackMul (Stack* stk)
{
    assert (StackOK(stk));
    assert (StackSize (stk) > 1);

    int a = StackPop (stk);
    int b = StackPop (stk);

    StackPush(stk, a*b);
}

void StackDiv (Stack* stk)
{
    assert (StackOK(stk));
    assert (StackSize (stk) > 1);

    int a = StackPop (stk);
    int b = StackPop (stk);

    StackPush(stk, a/b);
}

void Stacksqr (Stack* stk)
{
    assert (StackOK(stk));

    int a = StackPop (stk);

    StackPush(stk, a*a);
}

void Stacksqrt (Stack* stk)
{
    assert (StackOK(stk));

    int a = StackPop (stk);

    StackPush(stk, sqrt(a));
}

void StackLinEq (Stack* stk)
{
    assert (StackOK(stk));
    assert (StackSize (stk) > 1);

    StackPush (stk, 0);
    StackSub (stk);
    StackDiv (stk);
}


void StackReverseSub (Stack* stk)
{
    assert (StackOK(stk));
    assert (StackSize (stk) > 1);

    int a = StackPop (stk);
    int b = StackPop (stk);

    StackPush(stk, b-a);
}


void StackReverseDiv (Stack* stk)
{
    assert (StackOK(stk));
    assert (StackSize (stk) > 1);

    int a = StackPop (stk);
    int b = StackPop (stk);

    StackPush(stk, b/a);
}

