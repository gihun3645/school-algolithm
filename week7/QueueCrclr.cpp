#include <stdio.h>

#define N 	10
#pragma warning(disable: 4326 4996 6031)

typedef int Item;

typedef struct {
    Item items[N];
    int nFront;
    int nRear;
}	Queue, *QueuePtr;

int main(void)
{
    int  IsEmptyQueue(QueuePtr pQueue);
    int  IsFullQueue(QueuePtr pQueue);
    int  AddQueue(QueuePtr pQueue, Item nItem);
    int  DeleteQueue(QueuePtr pQueue, Item *pItem);
    void PrintQueue(QueuePtr pQueue);
    int  Error(const char *sMsg);

    /** Create Queue **/
    Queue aQueue;
    aQueue.nFront = aQueue.nRear = 0;

    while (1) {
        int value;
        printf("-2:Exit -1:Delete, 0~:Add ? ");
        scanf("%d", &value);
        if (value < -1)
            break;
        else if (value == -1) {
            if (DeleteQueue(&aQueue, &value) == false)
                Error("empty");
            else
                printf("%d is deleted\n", value);
        }
        else {
            if (AddQueue(&aQueue, value) == false)
                Error("full");
            else
                printf("%d is inserted\n", value);
        }
        PrintQueue(&aQueue);
    }
}

// 문제점
// 빈 상태와 가득 찬 상태를 구별하지 못함


// 해결책
// 방법 1 : 최대 (N-1)까지 저장
// 즉 공간 하나를 사용하지 않음
// 문제점 : 공간이 크면 메모리 낭비
// 방법 2 : 태그를 사용하여 구분 -> QueueTag에서..
// 문제점 : 알고리즘이 약간 복잡

int IsEmptyQueue(QueuePtr pQueue)
{	// 큐가 비었는지에 따라 T/F를 반환한다.
    return pQueue->nFront == pQueue->nRear;
}

int IsFullQueue(QueuePtr pQueue)
{	// 큐가 가득 찼는지에 따라 T/F를 반환한다.
    return (pQueue->nRear + 1) % N == pQueue->nFront;
}

int AddQueue(QueuePtr pQueue, Item nItem)
{	// 큐에 nItem을 추가하는데 승패에 따라 T/F를 반환한다.
    // rear를 증가하여 삽입
    if (IsFullQueue(pQueue))
        return false;
    pQueue->items[pQueue->nRear = (pQueue->nRear + 1) % N] = nItem;
    return true;
}

int DeleteQueue(QueuePtr pQueue, Item *pItem)
{	// 큐에서 삭제하여 pItem에 저장하는데 승패에 따라 T/F를 반환한다.
    // front를 증가하여 받아냄
    if (IsEmptyQueue(pQueue))
        return false;
    *pItem = pQueue->items[pQueue->nFront = (pQueue->nFront + 1) % N];
    return true;
}

void PrintQueue(QueuePtr pQueue)
{
    int nCtr = (pQueue->nRear - pQueue->nFront + N) % N;
    for (int i = 1; i <= nCtr; i++)
        printf("--%d-", (pQueue->nFront + i) % N);
    printf("--\n");
    for (int i = 1; i <= nCtr; i++)
        printf("%3d ", pQueue->items[(pQueue->nFront + i) % N]);
    printf("\n");
    for (int i = 1; i <= nCtr; i++)
        printf("----");
    printf("--\n\n");
}

int Error(const char *sMsg)
{
    printf("***** Queue is %s. *****\n", sMsg);
    return -1;
}