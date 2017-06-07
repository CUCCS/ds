#ifndef _MYDS_H_
#define _MYDS_H_

typedef enum _Status {
    OK,
    ERROR,
    OVERFLOW,
    FILE_NOT_EXIST,
    FILE_PARSE_ERROR,
    KEY_FOUND,
    KEY_NOT_FOUND,
    DUPLICATE
} Status;

#ifdef _HASH_TABLE_H_
typedef int KeyType;
typedef int ValueType;
typedef struct _ElemType {
    KeyType key;      // 关键字
    ValueType val;    // 值
#ifdef CHAINED_HASH
    struct _ElemType *next;
#endif
} ElemType;
#else
typedef int ElemType;
#endif
typedef char TElemType;

typedef enum { false, true} bool;
#endif
