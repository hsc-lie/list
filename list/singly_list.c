#include "singly_list.h"

/*
 * @函数名  SinglyListItemInit
 * @用  途  单向链表项初始化
 * @参  数  item:链表项
 * @返回值
*/
void SinglyListItemInit(SinglyListItem_t *item)
{
	item->Next = item;
}

/*
 * @函数名  SinglyListItemInsertHead
 * @用  途  单向链表项头部插入(切勿插入链表中已经存在的项,会导致链表错乱)
 * @参  数  head:链表头指针
 *          item:需要插入的项
 * @返回值
*/
void SinglyListItemInsertHead(SinglyListItem_t *head, SinglyListItem_t *item)
{
	item->Next = head->Next;
	head->Next = item;
}

/*
 * @函数名  SinglyListItemInsertTail
 * @用  途  单向链表项尾部部插入(切勿插入链表中已经存在的项,会导致链表错乱)
 * @参  数  head:链表头指针
 *          item:需要插入的项
 * @返回值
*/
void SinglyListItemInsertTail(SinglyListItem_t *head, SinglyListItem_t *item)
{
	SinglyListItem_t *p = head;

	for(p = head;p->Next != head;p = p->Next)
	{

	}

	item->Next = head;
	p->Next = item;
}

/*
 * @函数名  SinglyListItemInsert
 * @用  途  单向链表项按下标插入(切勿插入链表中已经存在的项,会导致链表错乱)
 * @参  数  head:链表头指针
 *          item:需要插入的项
 *          index:插入的下标
 * @返回值
*/
void SinglyListItemInsert(SinglyListItem_t *head, SinglyListItem_t *item, int index)
{
	int i = 0;
	SinglyListItem_t *p = head;

	do
	{
		if(i == index)
		{
			item->Next = p->Next;
			p->Next = item;
			break;
		}
		++i;
		p = p->Next;
	} while (p != head);
	
}

/*
 * @函数名  SinglyListItemRemoveHead
 * @用  途  单向链表项移除头部项
 * @参  数  head:链表头指针
 * @返回值  head:该链表已经为空
 *         其他:已经移除的链表项指针
 *         如果链表项存储在堆区,请根据返回值释放,或插入到别的链表中
*/
SinglyListItem_t *SinglyListItemRemoveHead(SinglyListItem_t *head)
{
	SinglyListItem_t *ret;

	ret = head->Next;
	head->Next = ret->Next;
	
	return ret;
}

/*
 * @函数名  SinglyListItemRemoveTail
 * @用  途  单向链表项移除尾部项
 * @参  数  head:链表头指针
 * @返回值  NULL:该链表已经为空
 *         其他:已经移除的链表项指针
 *         如果链表项存储在堆区,请根据返回值释放,或插入到别的链表中
*/
SinglyListItem_t *SinglyListItemRemoveTail(SinglyListItem_t *head)
{
	SinglyListItem_t *p;
	SinglyListItem_t *ret = NULL;

	for(p = head;p->Next->Next != head;p = p->Next)
	{
		
	}

	ret = p->Next;
	p->Next = head;

	return ret;
}

/*
 * @函数名  SinglyListItemRemove
 * @用  途  单向链表项移除对应的项
 * @参  数  head:链表头指针
 *          item:移除的项
 * @返回值  NULL:该链表不存在该项
 *         其他:已经移除的链表项指针
 *         如果链表项存储在堆区,请根据返回值释放,或插入到别的链表中
*/
SinglyListItem_t *SinglyListItemRemove(SinglyListItem_t *head, SinglyListItem_t *item)
{
	SinglyListItem_t *p;

	for(p = head->Next;p != head;p = p->Next)
	{
		if(p->Next == item)
		{
			p->Next = item->Next;
			return item;
		}
	}

	return NULL;
}

/*
 * @函数名  SinglyListItemRemoveIndex
 * @用  途  单向链表项移除对应的下标的项
 * @参  数  head:链表头指针
 *          index:需要移除项对应的下标
 * @返回值  NULL:索引超出链表长度
 *         其他:已经移除的链表项指针
 *         如果链表项存储在堆区,请根据返回值释放,或插入到别的链表中
*/
SinglyListItem_t *SinglyListItemRemoveIndex(SinglyListItem_t *head, int index)
{
	int i = 0;
	SinglyListItem_t *p = head;
	SinglyListItem_t *ret;

	for(i = 0,p = head;p->Next != head;++i,p = p->Next)
	{
		if(i == index)
		{
			ret = p->Next;
			p->Next = ret->Next;
			return ret;
		}
	}

	return NULL;
}

/*
 * @函数名  SinglyListItemGet
 * @用  途  单向链表项根据下标索引得到项
 * @参  数  head:链表头指针
 *          index:索引的下标
 * @返回值  索引得出的链表项
 *          返回NULL表示该链表不存在该索引
*/
SinglyListItem_t *SinglyListItemGet(SinglyListItem_t *head, int index)
{
	int i;
	SinglyListItem_t *p;

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
 * @函数名  SinglyListItemIndexOf
 * @用  途  单向链表项根据项得到该索引
 * @参  数  head:链表头指针
 *          item:链表项
 * @返回值  需要获取的链表项对应的下标
 *          返回-1表示项不在链表中
*/
int SinglyListItemIndexOf(SinglyListItem_t *head, SinglyListItem_t *item)
{
	int i;
	SinglyListItem_t *p;

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
 * @函数名  SinglyListItemGetLen
 * @用  途  获取单向链表的长度(遍历所有来得到长度)
 * @参  数  head:链表头指针
 * @返回值  链表的长度
*/
int SinglyListItemGetLen(SinglyListItem_t *head)
{
	int i;
	SinglyListItem_t *p;

	for(i = 0, p = head->Next;p != head;++i, p = p->Next)
	{

	}

	return i;
}

/*
 * @函数名  SinglyListItemForeach
 * @用  途  遍历单向链表
 * @参  数  head:链表头指针
 *          func:遍历每一个项时需要执行的函数
 *               返回值为NULL则继续遍历,否则直接退出遍历
 *          params:遍历每一项时传入的参数,会直接传给func输入参数去调用
 * @返回值  调用func输入参数回调后返回的值
*/
void *SinglyListItemForeach(SinglyListItem_t *head, SinglyListItemHandleFunc_t func, void *params)
{
	SinglyListItem_t *p;
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
 * @函数名  SinglyListItemIsErrorLoop
 * @用  途  判断单向链表是否有错误的环(指遍布链表无法再次找到头部导致无法退出)
 * @参  数  head:链表头指针
 * @返回值  FALSE:不存在错误的环
 *          TRUE:存在错误的环
*/
bool SinglyListItemIsErrorLoop(SinglyListItem_t *head)
{
	SinglyListItem_t *slow = head->Next;
	SinglyListItem_t *fast = slow;
	
	SinglyListItem_t *temp;
	
	while (fast != head)
	{
		temp = fast->Next;
		if(temp == head)
		{
			break;
		}

		fast = temp->Next;
		slow = slow->Next;

		if(slow == fast)
		{
			return TRUE;
		}
	}

	return FALSE;
}

/*
 * @函数名  SinglyListInit
 * @用  途  单向链表初始化
 * @参  数  list:链表
 * @返回值
*/
void SinglyListInit(SinglyList_t *list)
{
	list->Head.Next = &list->Head;
	list->Len = 0;
}

/*
 * @函数名  SinglyListInsertHead
 * @用  途  单向链表头部插入(切勿插入链表中已经存在的项,会导致链表错乱)
 * @参  数  list:链表
 *          item:需要插入的项
 * @返回值
*/
void SinglyListInsertHead(SinglyList_t *list, SinglyListItem_t *item)
{
	SinglyListItemInsertHead(&list->Head, item);
	++(list->Len);
}

/*
 * @函数名  SinglyListInsertTail
 * @用  途  单向链表尾部插入(切勿插入链表中已经存在的项,会导致链表错乱)
 * @参  数  list:链表
 *          item:需要插入的项
 * @返回值
*/
void SinglyListInsertTail(SinglyList_t *list, SinglyListItem_t *item)
{
	SinglyListItemInsertTail(&list->Head, item);
	++(list->Len);
}

/*
 * @函数名  SinglyListInsert
 * @用  途  单向链表按下标插入项(切勿插入链表中已经存在的项,会导致链表错乱)
 * @参  数  list:链表
 *          item:需要插入的项
 *          index:插入的下标
 * @返回值
*/
void SinglyListInsert(SinglyList_t *list, SinglyListItem_t *item, int index)
{
	SinglyListItemInsert(&list->Head, item, index);
	++(list->Len);
}

/*
 * @函数名  SinglyListRemoveHead
 * @用  途  单向链表移除头部
 * @参  数  list:链表
 * @返回值  NULL:链表已经为空
 *         其他:已经移除了的头部项指针
 *         如果插入的链表项是存放在堆区的,请根据此返回值来释放
*/
SinglyListItem_t *SinglyListRemoveHead(SinglyList_t *list)
{
	SinglyListItem_t *ret = NULL;
	SinglyListItem_t *head = &list->Head;

	if(head != head->Next)
	{
		ret = SinglyListItemRemoveHead(head);
		--(list->Len);
	}

	return ret;
}

/*
 * @函数名  SinglyListRemoveTail
 * @用  途  单向链表移除尾部
 * @参  数  list:链表
 * @返回值  NULL:链表已经为空
 *         其他:已经移除了的尾部项指针
 *         如果插入的链表项是存放在堆区的,请根据此返回值来释放
*/
SinglyListItem_t *SinglyListRemoveTail(SinglyList_t *list)
{
	SinglyListItem_t *ret = NULL;
	SinglyListItem_t *head = &list->Head;

	if(head != head->Next)
	{
		ret = SinglyListItemRemoveTail(head);
		--(list->Len);
	}

	return ret;
}

/*
 * @函数名  SinglyListRemove
 * @用  途  单向链表移除对应项
 * @参  数  list:链表
 *          item:移除的项
 * @返回值  NULL:链表中没有该项
 *         其他:已经移除了的链表项指针
 *         如果插入的链表项是存放在堆区的,请根据此返回值来释放
*/
SinglyListItem_t *SinglyListRemove(SinglyList_t *list, SinglyListItem_t *item)
{
	SinglyListItem_t *ret;

	ret = SinglyListItemRemove(&list->Head, item);

	if(NULL != ret)
	{
		--(list->Len);
	}

	return ret;
}

/*
 * @函数名  SinglyListRemoveIndex
 * @用  途  单向链表根据下标索引移除项
 * @参  数  list:链表
 *          index:需要移除的项对应下标
 * @返回值  NULL:索引超出链表长度
 *         其他:已经移除了的链表项指针
 *         如果插入的链表项是存放在堆区的,请根据此返回值来释放
*/
SinglyListItem_t *SinglyListRemoveIndex(SinglyList_t *list, int index)
{
	SinglyListItem_t *ret;

	ret = SinglyListItemRemoveIndex(&list->Head, index);

	if(NULL != ret)
	{
		--(list->Len);
	}

	return ret;
}

/*
 * @函数名  SinglyListRemoveAll
 * @用  途  单向链表移除所有项
 * @参  数  list:链表
 * @返回值  已经移除了的链表项指针
 *         如果插入的链表项是存放在堆区的,请根据此返回值来释放
*/
SinglyListItem_t *SinglyListRemoveAll(SinglyList_t *list)
{
	SinglyListItem_t *p = &list->Head;
	SinglyListItem_t *ret = p->Next;

	p->Next = p;
	list->Len = 0;

	return ret;
}

/*
 * @函数名  SinglyListGet
 * @用  途  单向链表根据下标获取对应项
 * @参  数  list:链表
 *          index:需要获取项对应的下标索引
 * @返回值  NULL:索引超出链表长度
 *         其他:对应下标索引的链表项指针
*/
SinglyListItem_t *SinglyListGet(SinglyList_t *list, int index)
{
	return SinglyListItemGet(&list->Head, index);
}

/*
 * @函数名  SinglyListIndexOf
 * @用  途  单向链表根据项获取对应的下标索引
 * @参  数  list:链表
 *          item:链表项
 * @返回值  -1:链表中没有该项
 *         其他:链表项对应的下标索引
*/
int SinglyListIndexOf(SinglyList_t *list, SinglyListItem_t *item)
{
	return SinglyListItemIndexOf(&list->Head, item);

}

/*
 * @函数名  SinglyListGetLen
 * @用  途  获取单向链表的长度(直接从变量中获取,如果对链表有不合理的操作,该值会不正确)
 * @参  数  list:链表
 * @返回值  链表长度
*/
int SinglyListGetLen(SinglyList_t *list)
{
	return list->Len;
}

/*
 * @函数名  SinglyListForeach
 * @用  途  遍历单向链表
 * @参  数  list:链表
 *          func:遍历每一个项时需要执行的函数
 *               返回值为NULL则继续遍历,否则直接退出遍历
 *          params:遍历每一项时传入的参数,会直接传给func输入参数去调用
 * @返回值  调用func输入参数回调后返回的值
*/
void *SinglyListForeach(SinglyList_t *list, SinglyListItemHandleFunc_t func, void *params)
{
	return SinglyListItemForeach(&list->Head, func, params);
}

/*
 * @函数名  SinglyListIsErrorLoop
 * @用  途  判断单向链表是否有错误的环(指遍布链表无法再次找到头部导致无法退出)
 * @参  数  list:链表
 * @返回值  FALSE:不存在错误的环
 *          TRUE:存在错误的环
*/
bool SinglyListIsErrorLoop(SinglyList_t *list)
{
	return SinglyListItemIsErrorLoop(&list->Head);
}
