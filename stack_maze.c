#include <stdlib.h> 
#include <stdbool.h>   
#include <stdio.h>  
Stack* newNode(int x, int y, enum direction dir) 
{ 
    Stack* stackNode = (Stack*)malloc(sizeof(Stack)); 
    stackNode->x = x; 
    stackNode->y = y; 
    stackNode->dir =  dir; 
    stackNode->next = NULL; 
    return stackNode;
} 

bool isEmpty(Stack* root) 
{ 
    if (NULL == root)
        return true;
    return false; 
} 
void push(Stack** root, int x, int y, enum direction dir) 
{

    Stack* stackNode = newNode(x,y,dir);
    stackNode->next = *root;
    *root = stackNode;
}

Stack pop(Stack** root)
{
    static Stack popped;
    if (isEmpty(*root))
    {
        popped.x = -1;
        popped.y = -1;
        return popped;
    }
Stack* temp = *root;
    *root = (*root)->next;
    popped.x = (*temp).x;
    popped.y = (*temp).y;
    free(temp);

    return popped;
}

Stack peek(struct StackNode* root)
{
    Stack temp;
    temp.x = -1;
    temp.y = -1;
    if (isEmpty(root))
    {
        return temp;
    }
  return *root;
}

