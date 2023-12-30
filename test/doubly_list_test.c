#include <stdio.h>

#include "doubly_list_test.h"
#include "doubly_list.h"

typedef struct
{
    int Data;
    char Text[10];
    DoublyListItem_t ListItem;
}DoublyListTest_t;

static DoublyListTest_t DoublyListTestArr[10] = 
{
    {.Data = 0, .Text = "000"},
    {.Data = 1, .Text = "111"},
    {.Data = 2, .Text = "222"},
    {.Data = 3, .Text = "333"},
    {.Data = 4, .Text = "444"},
    {.Data = 5, .Text = "555"},
    {.Data = 6, .Text = "666"},
    {.Data = 7, .Text = "777"},
    {.Data = 8, .Text = "888"},
    {.Data = 9, .Text = "999"},
};


static void *PrintfListItemTest(DoublyListItem_t *item, void *params)
{
    DoublyListTest_t *doublyListTest;
    doublyListTest = LIST_ENTRY(item, DoublyListTest_t, ListItem);
    printf("data = %d, text = %s\n", doublyListTest->Data, doublyListTest->Text);

    return NULL;
}

static void PrintfListTest(DoublyList_t *list)
{
    printf("len = %d\n", DoublyListGetLen(list));
    DoublyListForeach(list, PrintfListItemTest, NULL);
    printf("\n");
}

void DoublyListInsertTest()
{
    DoublyList_t testList;

    DoublyListInit(&testList);

    printf("双向链表插入测试\n");
    DoublyListInsertHead(&testList, &DoublyListTestArr[1].ListItem);
    DoublyListInsertTail(&testList, &DoublyListTestArr[3].ListItem);
    DoublyListInsert(&testList, &DoublyListTestArr[0].ListItem, 0);
    DoublyListInsert(&testList, &DoublyListTestArr[2].ListItem, 2);
    DoublyListInsert(&testList, &DoublyListTestArr[4].ListItem, 4);
    
    PrintfListTest(&testList);
    
}


void DoublyListRemoveTest()
{
    DoublyList_t testList;

    DoublyListInit(&testList);
    DoublyListInsertHead(&testList, &DoublyListTestArr[9].ListItem);
    DoublyListInsertHead(&testList, &DoublyListTestArr[8].ListItem);
    DoublyListInsertHead(&testList, &DoublyListTestArr[3].ListItem);
    DoublyListInsertHead(&testList, &DoublyListTestArr[2].ListItem);
    DoublyListInsertHead(&testList, &DoublyListTestArr[7].ListItem);
    DoublyListInsertHead(&testList, &DoublyListTestArr[1].ListItem);
    DoublyListInsertHead(&testList, &DoublyListTestArr[6].ListItem);
    DoublyListInsertHead(&testList, &DoublyListTestArr[0].ListItem);
    DoublyListInsertHead(&testList, &DoublyListTestArr[5].ListItem);
    DoublyListInsertHead(&testList, &DoublyListTestArr[4].ListItem);

    printf("双向链表删除测试\n");

    DoublyListRemoveHead(&testList);
    DoublyListRemoveTail(&testList);
    DoublyListRemoveIndex(&testList, 0);
    DoublyListRemoveIndex(&testList, 1);
    DoublyListRemoveIndex(&testList, 5);
    DoublyListRemove(&testList, &DoublyListTestArr[7].ListItem); 

    PrintfListTest(&testList);

}

void DoublyListGetTest()
{
    DoublyList_t testList;
    DoublyListTest_t *doublyListTest;
    int index;

    DoublyListInit(&testList);
    DoublyListInsertHead(&testList, &DoublyListTestArr[5].ListItem);
    DoublyListInsertHead(&testList, &DoublyListTestArr[4].ListItem);
    DoublyListInsertHead(&testList, &DoublyListTestArr[3].ListItem);
    DoublyListInsertHead(&testList, &DoublyListTestArr[2].ListItem);
    DoublyListInsertHead(&testList, &DoublyListTestArr[1].ListItem);

    printf("双向链表获取测试\n");
    doublyListTest = LIST_ENTRY(DoublyListGet(&testList, 0), DoublyListTest_t, ListItem);
    printf("第1个项: data = %d, text = %s\n", doublyListTest->Data, doublyListTest->Text);
    doublyListTest = LIST_ENTRY(DoublyListGet(&testList, 2), DoublyListTest_t, ListItem);
    printf("第3个项: data = %d, text = %s\n", doublyListTest->Data, doublyListTest->Text);
    doublyListTest = LIST_ENTRY(DoublyListGet(&testList, 4), DoublyListTest_t, ListItem);
    printf("第5个项: data = %d, text = %s\n", doublyListTest->Data, doublyListTest->Text);
    printf("\n");


    printf("双向链表查询测试\n");
    index = DoublyListIndexOf(&testList, &DoublyListTestArr[1].ListItem);
    printf("data = %d, text = %s:链表下标为%d\n", DoublyListTestArr[1].Data, DoublyListTestArr[1].Text, index);
    index = DoublyListIndexOf(&testList, &DoublyListTestArr[3].ListItem);
    printf("data = %d, text = %s:链表下标为%d\n", DoublyListTestArr[3].Data, DoublyListTestArr[3].Text, index);
    index = DoublyListIndexOf(&testList, &DoublyListTestArr[5].ListItem);
    printf("data = %d, text = %s:链表下标为%d\n", DoublyListTestArr[5].Data, DoublyListTestArr[5].Text, index);
    printf("\n");
}


void DoublyListLoopTest()
{
    DoublyList_t testList;
    bool isErrorLoop;

    DoublyListInit(&testList);
    DoublyListInsertHead(&testList, &DoublyListTestArr[4].ListItem);
    DoublyListInsertHead(&testList, &DoublyListTestArr[3].ListItem);
    DoublyListInsertHead(&testList, &DoublyListTestArr[2].ListItem);
    DoublyListInsertHead(&testList, &DoublyListTestArr[1].ListItem);
    DoublyListInsertHead(&testList, &DoublyListTestArr[0].ListItem);

    printf("双向链表判断接口测试\n");
    isErrorLoop = DoublyListIsErrorLoop(&testList);

    if(TRUE == isErrorLoop)
    {
        goto error;   
    }

    DoublyListInsertHead(&testList, &DoublyListTestArr[4].ListItem);
    isErrorLoop = DoublyListIsErrorLoop(&testList);

    if(FALSE == isErrorLoop)
    {
        goto error;
    }

    printf("接口功能正常!\n");
    return;

error:
    printf("接口功能错误!\n");
    return;

}
