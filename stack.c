#include<stdio.h>

static int stack[1000];
static int top = -1;

int push(int value)
{
  if(top < 999) 
    stack[++top] = value;
  else 
    return -1;
  return 1;
}

int pop(void) 
{
  if(top < 0) {
    printf("stack empty\n");
  } else {
    return stack[top--];
  }
  return -123456;
}

int getval(void)
{
  if(top >= 0) {
    return stack[top];
  } else {
    return -123456;
  }
}

