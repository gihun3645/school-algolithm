#include <stdio.h>

#pragma warning(disable: 4326 4996 6031)

#define N	25

int main(void)
{
    int arr[N];
    for (int i = 0; i < N; i++)
        arr[i] = i + 101;
    while (1) {
        int n;
        printf("n ? ");
        scanf("%d", &n);
        if (n < 0 || n > N)
            break;
        int PrintArrayFwrd1(int a[], int n);
        int PrintArrayFwrd2(int a[], int n);
        int PrintArrayFwrd3(int a[], int n);
        printf(" Print: ");
        printf("\nReturn: %d\n\n", PrintArrayFwrd1(arr, n));
        printf(" Print: ");
        printf("\nReturn: %d\n\n", PrintArrayFwrd2(arr, n));
        printf(" Print: ");
        printf("\nReturn: %d\n\n", PrintArrayFwrd3(arr, n));
    }
}

// 배열에서 n개의 값들을 출력하고 그들의 합을 반환한다
int PrintArrayFwrd1(int a[], int n)		// n-1개의 순환과 나머지 1
{
    /***
    [분할] [0, n-2] n-1
    [일반규칙] p(a,n) ::=
    [진행방향] ?
    [중단조건] ?
    [단순해] ?
    ***/
    return 0;
}

int PrintArrayFwrd2(int a[], int n)		// 1개와 나머지 n-1개의 순환
{
    /***
    [분할] ?
    [일반규칙] p(a,n) ::= ?
    [진행방향] ?
    [중단조건] ?
    [단순해] ?
    ***/
    return 0;
}

int PrintArrayFwrd3(int a[], int n)		// n/2개, 1개, n/2개의 순환
{
    /***
    [분할] ?
    [일반규칙] p(a,n) ::= ?
    [진행방향] ?
    [중단조건] ?
    [단순해] ?
    ***/
    return 0;
}
