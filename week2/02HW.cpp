//
// Created by 송기훈 on 2023/03/21.
//

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
        int PrintArrayBwrd1(int a[], int n);
        int PrintArrayBwrd2(int a[], int n);
        int PrintArrayBwrd3(int a[], int n);
//        int PrintArrayBwrd4(int a[], int n);
//        int PrintArrayBwrd5(int a[], int n);
        printf(" Print: ");
        printf("\nReturn: %d\n\n", PrintArrayBwrd1(arr, n));
        printf(" Print: ");
        printf("\nReturn: %d\n\n", PrintArrayBwrd2(arr, n));
        printf(" Print: ");
//        printf("\nReturn: %d\n\n", PrintArrayBwrd3(arr, n));
//        printf(" Print: ");
//        printf("\nReturn: %d\n\n", PrintArrayBwrd4(arr, n));
//        printf(" Print: ");
//        printf("\nReturn: %d\n\n", PrintArrayBwrd5(arr, n));
    }
}

int PrintArrayBwrd1(int a[], int n)		// n-1개, 1개
{
    /***
    [분할] ? [0,n-2], n-1
    [일반규칙] p(a,n) ::= a[n-1] 출력, t = p(a,n-1), t+a[n-1] 반환
    [진행방향] ?
    [중단조건] ?
    [단순해] ?
    ***/
    if (n == 1) { // 중단 조건: 원소가 1개인 경우
        printf("%d ", a[0]); // 마지막 원소 출력
        return a[0]; // 마지막 원소 반환
    }
    else { // 분할 방법: 배열을 n-1개와 1개로 분할
        printf("%d ", a[n-1]); // 마지막 원소 출력
        int sum = PrintArrayBwrd1(a, n-1); // 나머지 원소에 대해 함수 호출
        return sum + a[n-1]; // 반환값 계산
    }
    return 0;
}

int PrintArrayBwrd2(int a[], int n)		// 1개, n-1개
{
    /***
    [분할] ?
    [일반규칙] p(a,n) ::= ?
    [진행방향] ?
    [중단조건] ?
    [단순해] ?
    ***/
    if (n == 1) {
        printf("%d ", a[0]);
        return a[0];
    } else {
        int sum = a[n-1];
        printf("%d ", sum);
        for (int i = 1; i < n; i++) {
            printf("%d ", a[n-i-1]);
            sum += a[n-i-1];
        }
        return sum;
    }
}

int PrintArrayBwrd3(int a[], int n)		// n/2개, 1개, n/2개
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

int PrintArrayBwrd4(int a[], int n)		// n/3개, 1개, n/3개, 1개, n/3개
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

int PrintArrayBwrd5(int a[], int n)		// n/4개, 1개, n/4개, 1개, n/4개, 1개, n/4개
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

