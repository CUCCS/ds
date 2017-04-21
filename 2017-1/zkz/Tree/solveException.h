#pragma once
#include <stdio.h>
#include <Windows.h>

#define solveException (printf("\nError : "__FUNCTION__" : "),seh_filer(GetExceptionCode()))
int seh_filer(int code);