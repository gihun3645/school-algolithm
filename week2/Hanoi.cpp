// hanoi.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

int main(void)
{
    while (true) {
        int nCtr;
        printf("Disks ? ");
        scanf("%d", &nCtr);			// 옮기는 탑의 층을 입력 받는다.
        if (nCtr <= 0)
            break;
        // 함수 프로토타입
        void hanoi(int nDisk, int nFrom, int nTo);
        hanoi(nCtr, 1, 2);			// 탑을 1에서 2로 옮기시요.
        putchar(10);
    }
}

void hanoi(int nDisk, int nFrom, int nTo)
{
    if(nDisk == 1) {
        printf("%d --> %d\n", nFrom, nTo);
//        hanoi 함수 내에서 재귀 호출을 끝내고, 함수를 종료하는 역할을 함
        return;
    }
    int x = 6 - nFrom -nTo;
    hanoi(nDisk -1, nFrom, x);
    hanoi(1, nFrom, nTo);
    hanoi(nDisk -1, x, nTo);
}