#ifndef __DOUBLY_LIST_H_
#define __DOUBLY_LIST_H_

#include "list_common.h"

typedef struct DoublyListItem_t
{
    struct DoublyListItem_t *Next;  
    struct DoublyListItem_t *Prev;
}DoublyListItem_t;

typedef struct 
{
    int Len;
    DoublyListItem_t Head;
}DoublyList_t;

typedef void *(*DoublyListItemHandleFunc_t)(DoublyListItem_t *item, void *params);

extern void DoublyListItemInit(DoublyListItem_t *item);
extern void DoublyListItemInsertAfter(DoublyListItem_t *item, DoublyListItem_t *new);
extern void DoublyListItemInsertBefore(DoublyListItem_t *item, DoublyListItem_t *new);
extern void DoublyListItemInsert(DoublyListItem_t *head, DoublyListItem_t *item, int index);
extern void DoublyListItemRemove(DoublyListItem_t *item);
extern DoublyListItem_t *DoublyListItemRemoveIndex(DoublyListItem_t *head, int index);
extern DoublyListItem_t *DoublyListItemGet(DoublyListItem_t *head, int index);
extern int DoublyListItemIndexOf(DoublyListItem_t *head, DoublyListItem_t *item);
extern int DoublyListItemGetLen(DoublyListItem_t *head);
extern void *DoublyListItemForeach(DoublyListItem_t *head, DoublyListItemHandleFunc_t func, void *params);
extern bool DoublyListItemIsErrorLoop(DoublyListItem_t *head);

extern void DoublyListInit(DoublyList_t *list);
extern void DoublyListInsertHead(DoublyList_t *list, DoublyListItem_t *item);
extern void DoublyListInsertTail(DoublyList_t *list, DoublyListItem_t *item);
extern void DoublyListInsert(DoublyList_t *list, DoublyListItem_t *item, uint32_t index);
extern DoublyListItem_t *DoublyListRemoveHead(DoublyList_t *list);
extern DoublyListItem_t *DoublyListRemoveTail(DoublyList_t *list);
extern void DoublyListRemove(DoublyList_t *list, DoublyListItem_t *item);
extern DoublyListItem_t *DoublyListRemoveIndex(DoublyList_t *list, int index);
extern DoublyListItem_t *DoublyListRemoveAll(DoublyList_t *list);
extern DoublyListItem_t *DoublyListGet(DoublyList_t *list, int index);
extern int DoublyListIndexOf(DoublyList_t *list, DoublyListItem_t *item);
extern int DoublyListGetLen(DoublyList_t *list);
extern void *DoublyListForeach(DoublyList_t *list, DoublyListItemHandleFunc_t func, void *params);
extern bool DoublyListIsErrorLoop(DoublyList_t *list);

#endif /*__DOUBLY_LIST_H_*/