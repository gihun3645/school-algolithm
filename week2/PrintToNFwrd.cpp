//
// Created by 송기훈 on 2023/03/21.
//

#include "stdio.h"

// 1부터 n까지 출력하고 그들의 합을 반환한다.
int PrintToNFwrd(int n)
{
    if(n == 0)
        return 0;
    int nRtn = PrintToNFwrd(n-1);
    printf("%d ", n);
    return n + nRtn;
}

int main(void) {
    int PrintToNFwrd(int n);
    printf("n ? ");
}