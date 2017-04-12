#pragma once

#include <stdio.h>
typedef enum _Status { OK, ERROR, OVERFLOW } Status;
#define CHECK(func) \
do {\
	_Statu = func;\
	switch (_Statu) {\
	case OK:\
		break;\
	case ERROR:\
		printf("ERROR\n");\
		return 0;\
		break;\
	case OVERFLOW:\
		printf("OVERFLOW\n");\
		return 0;\
		break;\
	default:\
		printf("UNDEFINED\n");\
		return 0;\
		break;\
	}\
} while (0);

int _Statu;