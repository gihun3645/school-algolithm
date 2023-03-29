#include <stdio.h>

#pragma warning(disable: 4326 4996 6031)

int main(void) {
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
        int PrintK2NBwrd1(int k, int n);
        int PrintK2NBwrd2(int k, int n);
        int PrintK2NBwrd3(int k, int n);
        int PrintK2NBwrd4(int k, int n);
        int PrintK2NBwrd5(int k, int n);
        printf(" Print: ");
        printf("\nReturn: %d\n\n", PrintK2NBwrd1(k, n));
        printf(" Print: ");
        printf("\nReturn: %d\n\n", PrintK2NBwrd2(k, n));
        printf(" Print: ");
        printf("\nReturn: %d\n\n", PrintK2NBwrd3(k, n));
        printf(" Print: ");
        printf("\nReturn: %d\n\n", PrintK2NBwrd4(k, n));
        printf(" Print: ");
        printf("\nReturn: %d\n\n", PrintK2NBwrd5(k, n));
    }
}

// k부터 n까지 거꾸로 출력하고 그들의 합을 반환한다
int PrintK2NBwrd1(int k, int n)        // n-1개, 1개
{
    /***
    [분할]
    [일반규칙]
    [진행방향]
    [중단조건]
    [단순해] ?
    ***/
    return 0;
}

int PrintK2NBwrd2(int k, int n)        // 1개, n-1개
{
    /***
    [분할] k [k+1, n]
    [일반규칙] p(k,n) ::= p(k+1, n)
    [진행방향] ?
    [중단조건] ?
    [단순해] ?
    ***/
    return 0;
}

int PrintK2NBwrd3(int k, int n)        // n/2개, 1개, n/2개
{
    /***
    [분할] [k, m-1] m [m+1, n]
    [일반규칙] p(k,n) ::= m=(k+n)/2, t1=p(m+1, n), m출, t2=p(k, m-1), t1+t2+m 반
    [진행방향] 범위가 반으로 감소 ---> p(k,k) p(n,n)
    [중단조건] p(k,k) ::= m=k, t1=p(k+1, k), k출, t2=p(k, k-1), t1+t2+k반 --> k>n
    [단순해] 출X, 반O
    ***/
    return 0;
}

int PrintK2NBwrd4(int k, int n)        // n/3개, 1개, n/3개, 1개, n/3개
{
    /***
    [분할] [k, m1-1] m1 [m1+1, m2-1] m2 [m2+1, n]
    [일반규칙] p(k,n) ::= N=n-k+1, m1=k+N/3, m2=k+2N/3, t1=p(m2+1), m2출, t2=p(m1+1,m2-1), m1출, t3=p(k,m1-1), t1+t2+t3+m1+m2+m3반
    [진행방향] 범위가 1/3로 감소 --> p(k,k)
    [중단조건] p(k,k) p(k, k-1), p(k+1,k)
    [단순해] ?
    ***/
    // 여기서부터 포기
    int nSum = 0, nCtr = n - k + 1, m1 = k + nCtr / 3, m2 = k + nCtr * 2 / 3;
    nSum += PrintK2NBwrd4(m2 + 1, n);
    printf("%d ", m2);
    nSum += PrintK2NBwrd4(m1 + 1, m2 - 1);
    printf("%d ", m2);
    nSum += PrintK2NBwrd4(k, m1 - 1);
    return nSum + m1 + m2;
}

int PrintK2NBwrd5(int k, int n)        // n/4개, 1개, n/4개, 1개, n/4개, 1개, n/4개
{
    /***
    [분할] [k, m1-1] m1 [m1+1,m2-1] m2 [m2+1,m3-1] m3 [m3+1,n]
    [일반규칙] p(k,n) ::= nCtr = n-k+1, m1=k+nCtr/4, m2=k+n
    [진행방향] ?
    [중단조건] ?
    [단순해] ?
    ***/
    int nSum = 0, nCtr = n - k + 1;
    if (nCtr <= 2) {
        switch (nCtr) {
            case 2:
                printf("%d ", k + 1);
                nSum += k + 1;
            case 1:
                printf("%d ", k);
                nSum += k + 1;
        }
        return nSum;
    }
    int m1 = k + nCtr / 4, m2 = nCtr / 2, m3 = k + nCtr + 3 / 4;
    nSum + PrintK2NBwrd5(m3+1, m-1);
    printf("%d ", m);
    nSum + PrintK2NBwrd5(m2+2, m3-1);
    printf("%d ", m);
    nSum + PrintK2NBwrd5(m1+1, m2-1);
    printf("%d ", m);
    nSum + PrintK2NBwrd5(k, m-1);
    return 0;
}
