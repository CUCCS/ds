#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct stack_node
{
	int x; //·������x
	int y; //·������y
	struct stack_node *next;
};
typedef struct stack_node stack_list;
typedef stack_list * link;