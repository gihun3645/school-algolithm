//
// Created by User on 2023-03-15.
//

#include "stdio.h"

#pragma warning(disable: 4996 4326 6031)

int main(void)
{
    int nNmbr1, nNmbr2;
    while (1) {
        printf("Number 1 ? ");
        scanf("%d", &nNmbr1);		// 수 하나 입력
        if (nNmbr1 <= 0)			// 음수이면 끝낸다
            break;
        printf("Number 2 ? ");
        scanf("%d", &nNmbr2);		// 다른 수 하나 더 입력
        int Euclid(int nBig, int nSmall);
        printf("GCD: %d\n\n", Euclid(nNmbr1, nNmbr2));	// 최대공약수 출력
    }
}

int Euclid(int nBig, int nSmall)
{	// GCD(Greatest Common Divisor)를 계산한다
    // [일반규칙] GCD(b,s) ::= GCD(s,b%s)
    // [진행방향] b,s가 감소
    // [중단조건] b가 s로 나누어지면 단순해는 s
    int nRem = nBig % nSmall;
    if(nRem == 0)
        return nSmall;
    return Euclid(nSmall, nRem);
}