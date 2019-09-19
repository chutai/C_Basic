#include "stack_maze.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define N 8 
#define M 8 
Stack_t *root; 
Stack_t *root1;
int xSource,ySource;
int xDestination, yDestination; 
bool visited[N][M];
int maze[N][M];
int pathSolution[N][M];
bool Maze_Solve(int maze[N][M],Stack_t** root,enum direction direc);
int main(void)
{
	/*default Source Des */
	xSource = ySource = 0;
	xDestination = yDestination = M;
	int i , j;
	/*read input*/
	FILE *fp = fopen("input.txt","r");
	for (i = 0; i < N ; i++)
	{
		for (j  = 0; j < M; j++)
		{
			fscanf(fp,"%d",&maze[i][j]);
			if ( 2 == maze[i][j] )
			{
				xSource = i;
				ySource = j;
				printf("xSource-ySource:%d-%d\n",xSource,ySource);
			}
			if ( 3 == maze[i][j] )
			{
				xDestination = i;
				yDestination = j;
				printf("xDes-yDes:%d-%d\n",xDestination,yDestination);
			}
		}
	}
	root = (Stack_t*)malloc(sizeof(Stack_t));
	root1 = (Stack_t*)malloc(sizeof(Stack_t));
	memset(visited,true,sizeof(visited));
	memset(pathSolution,0,sizeof(pathSolution));
	bool solve,solve1;
	solve = Maze_Solve(maze,&root,RIGHT);
	memset(visited,true,sizeof(visited));
	solve1 = Maze_Solve(maze,&root1,DOWN);
	if (true == solve || true == solve1) 
	{ 
		Stack_t temp;
		if ( true == solve && true == solve1)
		{	
			printf("PATH FOUNDED:\n");
			while(false == isEmpty(root))
			{
			    temp = pop(&root);
			    pathSolution[temp.x][temp.y] = 1;
			}
			while(false == isEmpty(root1))
			{
			    temp = pop(&root1);
			    pathSolution[temp.x][temp.y] = 1;
			}
		}
		else if (true == solve && false == solve1)
		{
			printf("PATH FOUNDED:\n");
			while(false == isEmpty(root))
			{
			     temp = pop(&root);
			     pathSolution[temp.x][temp.y] = 1;
			}
		}
		else if (true == solve1 && false == solve)
		{
			printf("PATH FOUNDED:\n");
			while(false == isEmpty(root1))
			{
			     temp = pop(&root1);
			     pathSolution[temp.x][temp.y] = 1;
			}
		}
		pathSolution[0][0] = 0;
		pathSolution[xSource][ySource] = 2;
		pathSolution[xDestination][yDestination] = 3;
		for (i = 0; i < N ; i++)
		{
			for (j  = 0; j < M; j++)
			{
				printf("%d ",pathSolution[i][j]);
			}
			printf("\n");
		 } 
	}	
	else printf("NO PATH FOUND\n");
	free(root);
	free(root1);
	fclose(fp);
	return 0;
}
bool Maze_Solve(int maze[N][M],Stack_t **root,enum direction direc) 
{ 
    int i = xSource, j = ySource;  
    Stack_t temp;
    push(root,i,j,direc); 
    visited[i][j] = false;
    while (false == isEmpty(*root)) 
	{ 
						  
	 /*printf("went while\n");			    
         Pop the top node && move to the 
         left, right, top, down or retract  
         back according the value of node's 
         dir variable. 
	 */
	 enum direction d;
	 temp = (peek(*root));
		
	 d = (temp).dir; 
	 i = (temp).x, j =(temp).y; 	
	 /*	
	  Increment the direction && 
	  push the node in the stack again. 
	  */
	  ((temp).dir)++; 
	  pop(root); 
	  push(root,temp.x,temp.y,temp.dir); 
	  if (i == xDestination && j == yDestination) 
	  {
            return true; 
          } 
						  
		switch(d)
		{
		case UP:
		case UP_NEXT:
		{ 
			if ((i - 1 >= 0) && ( maze[i - 1][j]) &&  
				( true == visited[i - 1][j])) 
			 {
				Stack_t *temp1 = newNode(i - 1, j,direc );
				 visited[i - 1][j] = false; 
				push(root,temp1->x,temp1->y,temp1->dir); 
			 } 
			 break;
		} 
		
		case LEFT:
		case LEFT_NEXT:
		{ 
			 if ((j - 1 >= 0) && (maze[i][j - 1]) &&  
				(true == visited[i][j - 1])) 
			{ 
				Stack_t *temp1 = newNode(i, j - 1, direc );
				visited[i][j - 1] = false; 
				push(root,temp1->x,temp1->y,temp1->dir); 
			} 
			break;
		} 
		case DOWN:
		{ 
			if ((i + 1 < N) && ( maze[i + 1][j]) &&  
            (true == visited[i + 1][j])) 
			{  
				Stack_t *temp1 = newNode(i +  1, j, direc );
				visited[i + 1][j] = false; 
				push(root,temp1->x,temp1->y,temp1->dir); 
			} 
			break;
		 } 
		  
		 case RIGHT:
		 case RIGHT_NEXT:
		 { 
			if ((j + 1 < M) && ( maze[i][j + 1]) &&  
			  (true == visited[i][j + 1])) 
			{ 
				Stack_t *temp1 = newNode(i, j + 1, direc );
				visited[i][j + 1] = false; 
				push(root,temp1->x,temp1->y,temp1->dir); 
		    } 
			break;
		  } 
		   /*If none of the direction can take  
		   the rat to the Food, retract back  
		   to the path where the rat came from. 
		  */
		  default: 
		  { 
			 pop(root);
			 break;
		  } 
		}
	}
	return false;
}

