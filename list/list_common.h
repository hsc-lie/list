#ifndef __LIST_COMMON_H_
#define __LIST_COMMON_H_

#include <stdio.h>
#include <stdint.h>

typedef unsigned char bool;

#ifndef FALSE
#define FALSE (0)
#endif 

#ifndef TRUE
#define TRUE (!(FALSE))
#endif

#define CONTAINER_OF(p,type,member)        ((type *)((char *)(p) - (char *)(&(((type *)0)->member))))
#define LIST_ENTRY(p,type,member)          CONTAINER_OF(p,type,member) 

#endif /*__LIST_COMMON_H_*/