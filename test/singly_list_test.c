#include <stdio.h>

#include "singly_list_test.h"
#include "singly_list.h"

typedef struct
{
    int Data;
    char Text[10];
    SinglyListItem_t ListItem;
}SinglyListTest_t;

static SinglyListTest_t SinglyListTestArr[10] = 
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


static void *PrintfListItemTest(SinglyListItem_t *item, void *params)
{
    SinglyListTest_t *singlyListTest;
    singlyListTest = LIST_ENTRY(item, SinglyListTest_t, ListItem);
    printf("data = %d, text = %s\n", singlyListTest->Data, singlyListTest->Text);

    return NULL;
}

static void PrintfListTest(SinglyList_t *list)
{
    printf("len = %d\n", SinglyListGetLen(list));
    SinglyListForeach(list, PrintfListItemTest, NULL);
    printf("\n");
}

void SinglyListInsertTest()
{
    SinglyList_t testList;

    SinglyListInit(&testList);

    printf("单向链表插入测试\n");

    SinglyListInsertHead(&testList, &SinglyListTestArr[1].ListItem);
    SinglyListInsertTail(&testList, &SinglyListTestArr[3].ListItem);
    SinglyListInsert(&testList, &SinglyListTestArr[0].ListItem, 0);
    SinglyListInsert(&testList, &SinglyListTestArr[2].ListItem, 2);
    SinglyListInsert(&testList, &SinglyListTestArr[4].ListItem, 4);
    
    PrintfListTest(&testList);
}


void SinglyListRemoveTest()
{
    SinglyList_t testList;

    SinglyListInit(&testList);
    SinglyListInsertHead(&testList, &SinglyListTestArr[9].ListItem);
    SinglyListInsertHead(&testList, &SinglyListTestArr[8].ListItem);
    SinglyListInsertHead(&testList, &SinglyListTestArr[3].ListItem);
    SinglyListInsertHead(&testList, &SinglyListTestArr[2].ListItem);
    SinglyListInsertHead(&testList, &SinglyListTestArr[7].ListItem);
    SinglyListInsertHead(&testList, &SinglyListTestArr[1].ListItem);
    SinglyListInsertHead(&testList, &SinglyListTestArr[6].ListItem);
    SinglyListInsertHead(&testList, &SinglyListTestArr[0].ListItem);
    SinglyListInsertHead(&testList, &SinglyListTestArr[5].ListItem);
    SinglyListInsertHead(&testList, &SinglyListTestArr[4].ListItem);

    printf("单向链表删除测试\n");

    SinglyListRemoveHead(&testList);
    SinglyListRemoveTail(&testList);
    SinglyListRemoveIndex(&testList, 0);
    SinglyListRemoveIndex(&testList, 1);
    SinglyListRemoveIndex(&testList, 5);
    SinglyListRemove(&testList, &SinglyListTestArr[7].ListItem); 

    PrintfListTest(&testList);
}

void SinglyListGetTest()
{
    SinglyList_t testList;
    SinglyListTest_t *singlyListTest;
    int index;

    SinglyListInit(&testList);
    SinglyListInsertHead(&testList, &SinglyListTestArr[5].ListItem);
    SinglyListInsertHead(&testList, &SinglyListTestArr[4].ListItem);
    SinglyListInsertHead(&testList, &SinglyListTestArr[3].ListItem);
    SinglyListInsertHead(&testList, &SinglyListTestArr[2].ListItem);
    SinglyListInsertHead(&testList, &SinglyListTestArr[1].ListItem);

    printf("单向链表获取测试\n");
    singlyListTest = LIST_ENTRY(SinglyListGet(&testList, 0), SinglyListTest_t, ListItem);
    printf("第1个项: data = %d, text = %s\n", singlyListTest->Data, singlyListTest->Text);
    singlyListTest = LIST_ENTRY(SinglyListGet(&testList, 2), SinglyListTest_t, ListItem);
    printf("第3个项: data = %d, text = %s\n", singlyListTest->Data, singlyListTest->Text);
    singlyListTest = LIST_ENTRY(SinglyListGet(&testList, 4), SinglyListTest_t, ListItem);
    printf("第5个项: data = %d, text = %s\n", singlyListTest->Data, singlyListTest->Text);
    printf("\n");


    printf("单向链表查询测试\n");
    index = SinglyListIndexOf(&testList, &SinglyListTestArr[1].ListItem);
    printf("data = %d, text = %s:链表下标为%d\n", SinglyListTestArr[1].Data, SinglyListTestArr[1].Text, index);
    index = SinglyListIndexOf(&testList, &SinglyListTestArr[3].ListItem);
    printf("data = %d, text = %s:链表下标为%d\n", SinglyListTestArr[3].Data, SinglyListTestArr[3].Text, index);
    index = SinglyListIndexOf(&testList, &SinglyListTestArr[5].ListItem);
    printf("data = %d, text = %s:链表下标为%d\n", SinglyListTestArr[5].Data, SinglyListTestArr[5].Text, index); 
    printf("\n");
}

void SinglyListLoopTest()
{
    SinglyList_t testList;
    bool isErrorLoop;

    SinglyListInit(&testList);
    SinglyListInsertHead(&testList, &SinglyListTestArr[4].ListItem);
    SinglyListInsertHead(&testList, &SinglyListTestArr[3].ListItem);
    SinglyListInsertHead(&testList, &SinglyListTestArr[2].ListItem);
    SinglyListInsertHead(&testList, &SinglyListTestArr[1].ListItem);
    SinglyListInsertHead(&testList, &SinglyListTestArr[0].ListItem);

    printf("单向链表判断接口测试\n");
    isErrorLoop = SinglyListIsErrorLoop(&testList);

    if(TRUE == isErrorLoop)
    {
        goto error;   
    }

    SinglyListInsertHead(&testList, &SinglyListTestArr[4].ListItem);
    isErrorLoop = SinglyListIsErrorLoop(&testList);

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

