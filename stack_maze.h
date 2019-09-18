#ifndef _STACK_MAZE_
#define _STACK_MAZE_

#include <stdbool.h>

enum direction{RIGHT,LEFT,UP,DOWN,RIGHT_NEXT,UP_NEXT,LEFT_NEXT};

typedef struct StackNode {
     int x;
     int y;
     enum direction dir;
     struct StackNode* next;
    
}Stack;

Stack* newNode(int x,int y, enum direction dir);
bool isEmpty(Stack* stack);
void push(Stack** stack,int x,int y,enum direction dir);
Stack pop(Stack** stack);
Stack peek(Stack* stack);

#endif
