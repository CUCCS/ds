#include "solveException.h"
int seh_filer(int code)
{
	switch (code)
	{
	case EXCEPTION_ACCESS_VIOLATION:
		printf("存储保护异常，错误代码：%x\n", code);
		break;
	case EXCEPTION_DATATYPE_MISALIGNMENT:
		printf("数据类型未对齐异常，错误代码：%x\n", code);
		break;
	case EXCEPTION_BREAKPOINT:
		printf("中断异常，错误代码：%x\n", code);
		break;
	case EXCEPTION_SINGLE_STEP:
		printf("单步中断异常，错误代码：%x\n", code);
		break;
	case EXCEPTION_ARRAY_BOUNDS_EXCEEDED:
		printf("数组越界异常，错误代码：%x\n", code);
		break;
	case EXCEPTION_FLT_DENORMAL_OPERAND:
	case EXCEPTION_FLT_DIVIDE_BY_ZERO:
	case EXCEPTION_FLT_INEXACT_RESULT:
	case EXCEPTION_FLT_INVALID_OPERATION:
	case EXCEPTION_FLT_OVERFLOW:
	case EXCEPTION_FLT_STACK_CHECK:
	case EXCEPTION_FLT_UNDERFLOW:
		printf("浮点数计算异常，错误代码：%x\n", code);
		break;
	case EXCEPTION_INT_DIVIDE_BY_ZERO:
		printf("被0除异常，错误代码：%x\n", code);
		break;
	case EXCEPTION_INT_OVERFLOW:
		printf("数据溢出异常，错误代码：%x\n", code);
		break;
	case EXCEPTION_IN_PAGE_ERROR:
		printf("页错误异常，错误代码：%x\n", code);
		break;
	case EXCEPTION_ILLEGAL_INSTRUCTION:
		printf("非法指令异常，错误代码：%x\n", code);
		break;
	case EXCEPTION_STACK_OVERFLOW:
		printf("堆栈溢出异常，错误代码：%x\n", code);
		break;
	case EXCEPTION_INVALID_HANDLE:
		printf("无效句病异常，错误代码：%x\n", code);
		break;
	default:
		if (code & (1 << 29))
			printf("用户自定义的软件异常，错误代码：%x\n", code);
		else
			printf("其它异常，错误代码：%x\n", code);
		break;
	}

	exit(-1);
	return 1;
}