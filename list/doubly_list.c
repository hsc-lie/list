#include "doubly_list.h"

/*
 * @函数名  DoublyListItemInit
 * @用  途  双向链表项初始化
 * @参  数  item:链表项
 * @返回值
*/
void DoublyListItemInit(DoublyListItem_t *item)
{
    item->Next = item; 
    item->Prev = item;
}

/*
 * @函数名  DoublyListItemInsertAfter
 * @用  途  双向链表项插入到后面(切勿插入链表中已经存在的项,会导致链表错乱)
 * @参  数  item:链表项
 *          new:需要插入的项
 * @返回值
*/
void DoublyListItemInsertAfter(DoublyListItem_t *item, DoublyListItem_t *new)
{
    new->Next = item->Next;
    new->Prev = item;

	item->Next->Prev = new;
    item->Next = new;
    
}

/*
 * @函数名  DoublyListItemInsertBefore
 * @用  途  双向链表项插入到前面(切勿插入链表中已经存在的项,会导致链表错乱)
 * @参  数  item:链表项
 *          new:需要插入的项
 * @返回值
*/
void DoublyListItemInsertBefore(DoublyListItem_t *item, DoublyListItem_t *new)
{
    new->Next = item;
    new->Prev = item->Prev;

    item->Prev->Next = new;
    item->Prev = new;
}

/*
 * @函数名  DoublyListItemInsert
 * @用  途  双向链表项按下标插入(切勿插入链表中已经存在的项,会导致链表错乱)
 * @参  数  head:链表头指针
 *          item:需要插入的项
 *          index:插入的下标
 * @返回值
*/
void DoublyListItemInsert(DoublyListItem_t *head, DoublyListItem_t *item, int index)
{
	int i = 0;
	DoublyListItem_t *p = head;

	do
	{
		if(i == index)
		{
			DoublyListItemInsertAfter(p, item);
		}
		++i;
		p=p->Next;
	} while (p != head);
}

/*
 * @函数名  DoublyListItemRemove
 * @用  途  移除双向链表项
 * @参  数  head:链表项,如果链表项存储在堆区,请自行释放,或插入到别的链表中
 * @返回值
*/
void DoublyListItemRemove(DoublyListItem_t *item)
{
    item->Next->Prev = item->Prev;
    item->Prev->Next = item->Next;

    item->Next = item;
    item->Prev = item;
}

/*
 * @函数名  DoublyListItemRemoveIndex
 * @用  途  双向链表项移除对应的下标的项
 * @参  数  head:链表头指针
 *          index:需要移除项对应的下标
 * @返回值  NULL:索引超出链表长度
 *         其他:已经移除的链表项指针
 *         如果链表项存储在堆区,请根据返回值释放,或插入到别的链表中
*/
DoublyListItem_t *DoublyListItemRemoveIndex(DoublyListItem_t *head, int index)
{
	DoublyListItem_t *p;

	p = DoublyListItemGet(head, index);
	if(NULL != p)
	{
		DoublyListItemRemove(p);
	}

	return p;
}

/*
 * @函数名  DoublyListItemGet
 * @用  途  双向链表项根据下标索引得到项
 * @参  数  head:链表头指针
 *          index:索引的下标
 * @返回值  索引得出的链表项
 *          返回NULL表示该链表不存在该索引
*/
DoublyListItem_t *DoublyListItemGet(DoublyListItem_t *head, int index)
{
	int i;
	DoublyListItem_t *p;
	
	for(i = 0,p = head->Next;p != head;++i,p = p->Next)
	{
		if(i == index)
		{
			return p;
		}
	}

	return NULL;
}

/*
 * @函数名  DoublyListItemIndexOf
 * @用  途  双向链表项根据项得到该索引
 * @参  数  head:链表头指针
 *          item:链表项
 * @返回值  需要获取的链表项对应的下标
 *          返回-1表示项不在链表中
*/
int DoublyListItemIndexOf(DoublyListItem_t *head, DoublyListItem_t *item)
{
	int i;
	DoublyListItem_t *p;
	

	for(i = 0,p = head->Next;p != head;++i,p = p->Next)
	{
		if(p == item)
		{
			return i;
		}	
	}

	return -1;
}

/*
 * @函数名  DoublyListItemGetLen
 * @用  途  获取双向链表的长度(遍历所有来得到长度)
 * @参  数  head:链表头指针
 * @返回值  链表的长度
*/
int DoublyListItemGetLen(DoublyListItem_t *head)
{
    int i;
    DoublyListItem_t *p;

	for(i = 0,p = head->Next;p != head;++i,p = p->Next)
	{
		
	}

    return i;
}

/*
 * @函数名  DoublyListItemForeach
 * @用  途  遍历双向链表
 * @参  数  head:链表头指针
 *          func:遍历每一个项时需要执行的函数
 *               返回值为NULL则继续遍历,否则直接退出遍历
 *          params:遍历每一项时传入的参数,会直接传给func输入参数去调用
 * @返回值  调用func输入参数回调后返回的值
*/
void *DoublyListItemForeach(DoublyListItem_t *head, DoublyListItemHandleFunc_t func, void *params)
{
	DoublyListItem_t *p;
	void *ret;

	for(p = head->Next;p != head;p = p->Next)
	{
		ret = func(p, params);
		if(NULL != ret)
		{
			return ret;
		}
	}

	return NULL;
}

/*
 * @函数名  DoublyListItemForwardIsErrorLoop
 * @用  途  判断双向向链表正向是否有错误的环(指正向遍布链表无法再次找到头部导致无法退出)
 * @参  数  head:链表头指针
 * @返回值  -1:存在错误的环
 *         其他:环长度
*/
static int DoublyListItemForwardIsErrorLoop(DoublyListItem_t *head)
{
	int count = 0;
	DoublyListItem_t *slow = head->Next;
	DoublyListItem_t *fast = slow;
	DoublyListItem_t *temp;
	
	while(fast != head)
	{
		temp = fast->Next;
		++count;
		if(temp == head)
		{
			break;
		}

		fast = temp->Next;
		++count;
		slow = slow->Next;
		if(slow == fast)
		{
			return -1;
		}
	}

	return count;
}

/*
 * @函数名  DoublyListItemForwardIsErrorLoop
 * @用  途  判断双向向链表反向是否有错误的环(指反向遍布链表无法再次找到头部导致无法退出)
 * @参  数  head:链表头指针
 * @返回值  -1:存在错误的环
 *         其他:环长度
*/
static int DoublyListItemReverseIsErrorLoop(DoublyListItem_t *head)
{
	int count = 0;
	DoublyListItem_t *slow = head->Prev;
	DoublyListItem_t *fast = slow;
	DoublyListItem_t *temp;
	
	while(fast != head)
	{
		temp = fast->Prev;
		++count;
		if(temp == head)
		{
			break;
		}

		fast = temp->Prev;
		++count;
		slow = slow->Prev;
		if(slow == fast)
		{
			return -1;
		}
	}

	return count;
}

/*
 * @函数名  DoublyListItemForwardIsErrorLoop
 * @用  途  判断双向向链表是否有错误的环(指遍布链表无法再次找到头部导致无法退出,或正向遍历和方向遍历长度不相等)
 * @参  数  head:链表头指针
 * @返回值  FALSE:不存在错误的环
 *          TRUE:存在错误的环
*/
bool DoublyListItemIsErrorLoop(DoublyListItem_t *head)
{
	int forwarCount = DoublyListItemForwardIsErrorLoop(head);
	int reverseCount = DoublyListItemReverseIsErrorLoop(head);

	if((forwarCount != reverseCount) || (-1 == forwarCount) || (-1 == reverseCount))
	{
		return TRUE;
	}

	return FALSE;
}

/*
 * @函数名  DoublyListInit
 * @用  途  双向链表初始化
 * @参  数  list:链表
 * @返回值
*/
void DoublyListInit(DoublyList_t *list)
{
	list->Head.Next = &list->Head;
	list->Head.Prev = &list->Head;

	list->Len = 0;
}

/*
 * @函数名  DoublyListInsertHead
 * @用  途  双向链表头部插入(切勿插入链表中已经存在的项,会导致链表错乱)
 * @参  数  list:链表
 *          item:需要插入的项
 * @返回值
*/
void DoublyListInsertHead(DoublyList_t *list, DoublyListItem_t *item)
{
	DoublyListItemInsertAfter(&list->Head, item);
	++(list->Len);
}

/*
 * @函数名  DoublyListInsertTail
 * @用  途  双向链表尾部插入(切勿插入链表中已经存在的项,会导致链表错乱)
 * @参  数  list:链表
 *          item:需要插入的项
 * @返回值
*/
void DoublyListInsertTail(DoublyList_t *list, DoublyListItem_t *item)
{
	DoublyListItemInsertBefore(&list->Head, item);
	++(list->Len);
}

/*
 * @函数名  DoublyListInsert
 * @用  途  双向链表按下标插入项(切勿插入链表中已经存在的项,会导致链表错乱)
 * @参  数  list:链表
 *          item:需要插入的项
 *          index:插入的下标
 * @返回值
*/
void DoublyListInsert(DoublyList_t *list, DoublyListItem_t *item, uint32_t index)
{
	DoublyListItemInsert(&list->Head, item, index);
	++(list->Len);
}

/*
 * @函数名  DoublyListRemoveHead
 * @用  途  双向链表移除头部
 * @参  数  list:链表
 * @返回值  NULL:链表已经为空
 *         其他:已经移除了的头部项指针
 *         如果插入的链表项是存放在堆区的,请根据此返回值来释放
*/
DoublyListItem_t *DoublyListRemoveHead(DoublyList_t *list)
{
	DoublyListItem_t *head = &list->Head;

	if(head != head->Next)
	{
		DoublyListItemRemove(head->Next);
		--(list->Len);

		return head->Next;
	}
	
	return NULL;
}

/*
 * @函数名  DoublyListRemoveTail
 * @用  途  双向链表移除尾部
 * @参  数  list:链表
 * @返回值  NULL:链表已经为空
 *         其他:已经移除了的尾部项指针
 *         如果插入的链表项是存放在堆区的,请根据此返回值来释放
*/
DoublyListItem_t *DoublyListRemoveTail(DoublyList_t *list)
{
	DoublyListItem_t *head = &list->Head;

	if(head != head->Prev)
	{
		DoublyListItemRemove(head->Prev);
		--(list->Len);

		return head->Prev;
	}

	return NULL;
}

/*
 * @函数名  DoublyListRemove
 * @用  途  双向链表移除对应项
 * @参  数  list:链表
 *          item:移除的项,如果插入的链表项是存放在堆区的,请根据此返回值来释放
 * @返回值
*/
void DoublyListRemove(DoublyList_t *list, DoublyListItem_t *item)
{
	DoublyListItemRemove(item);
	--(list->Len);
}

/*
 * @函数名  DoublyListRemoveIndex
 * @用  途  双向链表根据下标索引移除项
 * @参  数  list:链表
 *          index:需要移除的项对应下标
 * @返回值  NULL:索引超出链表长度
 *         其他:已经移除了的链表项指针
 *         如果插入的链表项是存放在堆区的,请根据此返回值来释放
*/
DoublyListItem_t *DoublyListRemoveIndex(DoublyList_t *list, int index)
{
	DoublyListItem_t *p;
	p = DoublyListItemRemoveIndex(&list->Head, index);

	if(p != NULL)
	{
		--(list->Len);
	}

	return p;
}

/*
 * @函数名  DoublyListRemoveAll
 * @用  途  双向链表移除所有项
 * @参  数  list:链表
 * @返回值  已经移除了的链表项指针
 *         如果插入的链表项是存放在堆区的,请根据此返回值来释放
*/
DoublyListItem_t *DoublyListRemoveAll(DoublyList_t *list)
{
	DoublyListItem_t *head = &list->Head;
	DoublyListItem_t *ret = NULL;

	if(head != head->Next)
	{
		ret = head->Next;
		DoublyListItemRemove(&list->Head);
		list->Len = 0;
	}

	return ret;
}

/*
 * @函数名  DoublyListGet
 * @用  途  双向链表根据下标获取对应项
 * @参  数  list:链表
 *          index:需要获取项对应的下标索引
 * @返回值  NULL:索引超出链表长度
 *         其他:对应下标索引的链表项指针
*/
DoublyListItem_t *DoublyListGet(DoublyList_t *list, int index)
{
	return DoublyListItemGet(&list->Head, index);
}

/*
 * @函数名  DoublyListIndexOf
 * @用  途  双向链表根据项获取对应的下标索引
 * @参  数  list:链表
 *          item:链表项
 * @返回值  -1:链表中没有该项
 *         其他:链表项对应的下标索引
*/
int DoublyListIndexOf(DoublyList_t *list, DoublyListItem_t *item)
{
	return DoublyListItemIndexOf(&list->Head, item);
}

/*
 * @函数名  DoublyListGetLen
 * @用  途  获取双向链表的长度(直接从变量中获取,如果对链表有不合理的操作,该值会不正确)
 * @参  数  list:链表
 * @返回值  链表长度
*/
int DoublyListGetLen(DoublyList_t *list)
{
	return list->Len;

}

/*
 * @函数名  DoublyListForeach
 * @用  途  遍历双向链表
 * @参  数  list:链表
 *          func:遍历每一个项时需要执行的函数
 *               返回值为NULL则继续遍历,否则直接退出遍历
 *          params:遍历每一项时传入的参数,会直接传给func输入参数去调用
 * @返回值  调用func输入参数回调后返回的值
*/
void *DoublyListForeach(DoublyList_t *list, DoublyListItemHandleFunc_t func, void *params)
{
	return DoublyListItemForeach(&list->Head, func, params);
}

/*
 * @函数名  DoublyListIsErrorLoop
 * @用  途  判断双向链表是否有错误的环((指遍布链表无法再次找到头部导致无法退出,或正向遍历和方向遍历长度不相等))
 * @参  数  list:链表
 * @返回值  FALSE:不存在错误的环
 *          TRUE:存在错误的环
*/
bool DoublyListIsErrorLoop(DoublyList_t *list)
{
	return DoublyListItemIsErrorLoop(&list->Head);
}
