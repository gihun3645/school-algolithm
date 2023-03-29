#include <stdio.h>

#pragma warning(disable: 4326 4996 6031)

int main(void)
{
    while (1) {
        int k, n;
        printf("k ? ");
        scanf("%d", &k);
        if (k < 0)
            break;
        printf("n ? ");
        scanf("%d", &n);
        if (k > n)
            break;
        int PrintK2NFwrd1(int k, int n);
        int PrintK2NFwrd2(int k, int n);
        int PrintK2NFwrd3(int k, int n);
        printf(" Print: ");
        printf("\nReturn: %d\n\n", PrintK2NFwrd1(k, n));
        printf(" Print: ");
        printf("\nReturn: %d\n\n", PrintK2NFwrd2(k, n));
        printf(" Print: ");
        printf("\nReturn: %d\n\n", PrintK2NFwrd3(k, n));
    }
}

// k부터 n까지 출력하고 그들의 합을 반환한다
int PrintK2NFwrd1(int k, int n)		// n-1개의 순환과 나머지 1
{
    /***
    [분할] [k, n-1] n
    [일반규칙] p(k,n) ::= t=p(k, n-1), n을 출력, t+n을 반환
    [진행방향] n이 1씩 감소
    [중단조건] n>k
    [단순해] 출력 X, 반환 O
    ***/
    if(k > n)
        return 0;
    int t = PrintK2NFwrd1(k, n-1);
    printf("%d ", n);
    return t+n;
}

int PrintK2NFwrd2(int k, int n)		// 1개와 나머지 n-1개의 순환
{
    /***
    [분할] k[k+1, n]
    [일반규칙] p(k,n) ::= t=p(k+1, n)
    [진행방향] k가 1씩 증가 (왼쪽과 오른쪽과의 숫자 차이)
    [중단조건] p(n,n) ::= n출력, t=p(n+1,n) t+n 반환 --> k>n: 출X, 반환O
    [단순해] 출X, 반O
    ***/
    return 0;
}

int PrintK2NFwrd3(int k, int n)		//  n/2개, 1개, n/2개의 순환
{
    /***
    [분할] [k, m-1] m [m+1, n]
    [일반규칙] p(k,n) ::= t1=p(k, m-1), m을 출력, t2=p(m+1, n) n을 출력
    [진행방향]
    [중단조건] ?
    [단순해] ?
    ***/
    return 0;
}