/*
��ͷ�ļ���Ҫ���Status�Ķ��弰����ز���
ͬʱҲ�����һЩ�������õ�����
*/
#pragma once

#include <stdio.h>

/*ö������Status*/
typedef enum _Status { OK, ERROR, OVERFLOW } Status;

/*��麯������ֵ , �����ΪOK���ڵ�ǰ������return -1*/
/*�÷� : checkStatu( �������� ); */
#define checkStatu(func) \
do {\
	switch (func) {\
	case OK:\
		break;\
	case ERROR:\
		printf("ERROR");\
		return -1;\
		break;\
	case OVERFLOW:\
		printf("OVERFLOW");\
		return -1;\
		break;\
	default:\
			printf("UNDEFINED");\
		return -1;\
		break;\
	}/*end switch*/\
} while (0)

/*������� : �������Ƿ�Ϊ�� , �����򷵻�ERROR*/
#define checkNull(arg,argName) \
if(!arg){printf("%s is NULL , return ERROR \n",argName);return ERROR;}
/*�������Ƿ�Ϊ�� , �����򷵻�OVERFLOW*/
#define checkOverflow(var,varName) \
if(!var){printf("%s is NULL , return OVERFLOW",varName);return OVERFLOW;}

/* ==========������������==========*/

/*�ֶ�bool����*/
typedef enum _bool { false, true } bool;
/*��������һ��ѭ��size�ε�forѭ�� , ѭ���β�Ϊi*/
#define times(i,size) for((i)=1;(i)<=(size);++(i))