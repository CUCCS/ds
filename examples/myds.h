#ifndef _MYDS_H_
#define _MYDS_H_

typedef enum _Status {
    OK,
    ERROR,
    OVERFLOW,
    FILE_NOT_EXIST,
    FILE_PARSE_ERROR
} Status;

typedef int ElemType;
typedef char TElemType;

typedef enum { false, true} bool;
#endif
