#ifndef _stakmaths_H
#include "stacklib.h"
#include <math.h>

void StackAdd        (Stack* stk);
void StackSub        (Stack* stk);
void StackMul        (Stack* stk);
void StackDiv        (Stack* stk);
void Stacksqr        (Stack* stk);
void Stacksqrt       (Stack* stk);
void StackLinEq      (Stack* stk);
void StackReverseSub (Stack* stk);
void StackReverseDiv (Stack* stk);

#include "stackmaths.cpp"
#endif // _stakmaths_H




