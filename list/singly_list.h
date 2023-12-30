#ifndef __SINGLY_LIST_H_
#define __SINGLY_LIST_H_

#include "list_common.h"

typedef struct SinglyListItem_t
{
	struct SinglyListItem_t *Next;
}SinglyListItem_t;

typedef struct
{
	SinglyListItem_t Head;
	uint32_t Len;
}SinglyList_t;

typedef void *(*SinglyListItemHandleFunc_t)(SinglyListItem_t *item, void *params);

extern void SinglyListItemInit(SinglyListItem_t *item);
extern void SinglyListItemInsertHead(SinglyListItem_t *head, SinglyListItem_t *item);
extern void SinglyListItemInsertTail(SinglyListItem_t *head, SinglyListItem_t *item);
extern void SinglyListItemInsert(SinglyListItem_t *head, SinglyListItem_t *item, int index);
extern SinglyListItem_t *SinglyListItemRemoveHead(SinglyListItem_t *head);
extern SinglyListItem_t *SinglyListItemRemoveTail(SinglyListItem_t *head);
extern SinglyListItem_t *SinglyListItemRemove(SinglyListItem_t *head, SinglyListItem_t *item);
extern SinglyListItem_t *SinglyListItemRemoveIndex(SinglyListItem_t *head, int index);
extern SinglyListItem_t *SinglyListItemGet(SinglyListItem_t *head, int index);
extern int SinglyListItemIndexOf(SinglyListItem_t *head, SinglyListItem_t *item);
extern int SinglyListItemGetLen(SinglyListItem_t *head);
extern void *SinglyListItemForeach(SinglyListItem_t *head, SinglyListItemHandleFunc_t func, void *params);
extern bool SinglyListItemIsErrorLoop(SinglyListItem_t *head);

extern void SinglyListInit(SinglyList_t *list);
extern void SinglyListInsertHead(SinglyList_t *list, SinglyListItem_t *item);
extern void SinglyListInsertTail(SinglyList_t *list, SinglyListItem_t *item);
extern void SinglyListInsert(SinglyList_t *list, SinglyListItem_t *item, int index);
extern SinglyListItem_t *SinglyListRemoveHead(SinglyList_t *list);
extern SinglyListItem_t *SinglyListRemoveTail(SinglyList_t *list);
extern SinglyListItem_t *SinglyListRemove(SinglyList_t *list, SinglyListItem_t *item);
extern SinglyListItem_t *SinglyListRemoveIndex(SinglyList_t *list, int index);
extern SinglyListItem_t *SinglyListRemoveAll(SinglyList_t *list);
extern SinglyListItem_t *SinglyListGet(SinglyList_t *list, int index);
extern int SinglyListIndexOf(SinglyList_t *list, SinglyListItem_t *item);
extern int SinglyListGetLen(SinglyList_t *list);
extern void *SinglyListForeach(SinglyList_t *list, SinglyListItemHandleFunc_t func, void *params);
extern bool SinglyListIsErrorLoop(SinglyList_t *list);

#endif /*__SINGLY_LIST_H_*/