#include "stack_maze.h" 
#include <stdlib.h> 
#include <stdbool.h>   
#include <stdio.h>  
Stack_t* newNode(int x, int y, enum direction dir) 
{ 
    Stack_t* stackNode = (Stack*)malloc(sizeof(Stack_t)); 
    stackNode->x = x; 
    stackNode->y = y; 
    stackNode->dir =  dir; 
    stackNode->next = NULL; 
    return stackNode;
} 

bool isEmpty(Stack_t* root) 
{ 
    if (NULL == root)
    return true;
    return false; 
} 
  
void push(Stack_t** root, int x, int y, enum direction dir) 
{ 
    
    Stack_t* stackNode = newNode(x,y,dir); 
    stackNode->next = *root; 
    *root = stackNode; 
}

Stack_t pop(Stack_t** root) 
{ 
    static Stack_t popped;
    if (isEmpty(*root))
	{
	    popped.x = -1;
	    popped.y = -1;
	    return popped; 
	}
    Stack_t* temp = *root; 
    *root = (*root)->next; 
    popped.x = (*temp).x;
    popped.y = (*temp).y; 
    free(temp);
    return popped; 
} 

Stack_t peek(Stack_t* root) 
{
	Stack_t temp;
	temp.x = -1;
	temp.y = -1;
	if (isEmpty(root))
	{
	    return temp; 
	}
	return *root; 
} 
