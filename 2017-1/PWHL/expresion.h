#include<stdio.h> 
#include<stdlib.h> 
#define TRUE 1 
#define FALSE 0 
#define MAXNUM 100 
typedef int DataType;
typedef  struct
{
	DataType s[MAXNUM];
	int t;
}SeqStack, *PSeqStack;

PSeqStack createEmptyStack_seq();
int isEmptyStack_seq(PSeqStack pastack);
void push_seq(PSeqStack pastack, DataType x);
void pop_seq(PSeqStack pastack);
DataType top_seq(PSeqStack pastack);
int infixtoSuffix(const char* infix, char* suffix);
int calculateSuffix(const char * suffix, int * presult);
void getline(char* line, int limit);
