/*
该头文件主要存放Status的定义及其相关操作
同时也存放了一些其他常用的内容
*/
#pragma once

#include <stdio.h>

/*枚举类型Status*/
typedef enum _Status { OK, ERROR, OVERFLOW } Status;

/*检查函数返回值 , 如果不为OK则在当前函数中return -1*/
/*用法 : checkStatu( 函数调用 ); */
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

/*参数检查 : 检查参数是否为空 , 若空则返回ERROR*/
#define checkNull(arg,argName) \
if(!arg){printf("%s is NULL , return ERROR \n",argName);return ERROR;}
/*检查变量是否为空 , 若空则返回OVERFLOW*/
#define checkOverflow(var,varName) \
if(!var){printf("%s is NULL , return OVERFLOW",varName);return OVERFLOW;}

/* ==========其他常用内容==========*/

/*手动bool类型*/
typedef enum _bool { false, true } bool;
/*快速生成一个循环size次的for循环 , 循环形参为i*/
#define times(i,size) for((i)=1;(i)<=(size);++(i))