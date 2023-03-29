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

// k���� n���� �Ųٷ� ����ϰ� �׵��� ���� ��ȯ�Ѵ�
int PrintK2NBwrd1(int k, int n)        // n-1��, 1��
{
    /***
    [����]
    [�Ϲݱ�Ģ]
    [�������]
    [�ߴ�����]
    [�ܼ���] ?
    ***/
    return 0;
}

int PrintK2NBwrd2(int k, int n)        // 1��, n-1��
{
    /***
    [����] k [k+1, n]
    [�Ϲݱ�Ģ] p(k,n) ::= p(k+1, n)
    [�������] ?
    [�ߴ�����] ?
    [�ܼ���] ?
    ***/
    return 0;
}

int PrintK2NBwrd3(int k, int n)        // n/2��, 1��, n/2��
{
    /***
    [����] [k, m-1] m [m+1, n]
    [�Ϲݱ�Ģ] p(k,n) ::= m=(k+n)/2, t1=p(m+1, n), m��, t2=p(k, m-1), t1+t2+m ��
    [�������] ������ ������ ���� ---> p(k,k) p(n,n)
    [�ߴ�����] p(k,k) ::= m=k, t1=p(k+1, k), k��, t2=p(k, k-1), t1+t2+k�� --> k>n
    [�ܼ���] ��X, ��O
    ***/
    return 0;
}

int PrintK2NBwrd4(int k, int n)        // n/3��, 1��, n/3��, 1��, n/3��
{
    /***
    [����] [k, m1-1] m1 [m1+1, m2-1] m2 [m2+1, n]
    [�Ϲݱ�Ģ] p(k,n) ::= N=n-k+1, m1=k+N/3, m2=k+2N/3, t1=p(m2+1), m2��, t2=p(m1+1,m2-1), m1��, t3=p(k,m1-1), t1+t2+t3+m1+m2+m3��
    [�������] ������ 1/3�� ���� --> p(k,k)
    [�ߴ�����] p(k,k) p(k, k-1), p(k+1,k)
    [�ܼ���] ?
    ***/
    // ���⼭���� ����
    int nSum = 0, nCtr = n - k + 1, m1 = k + nCtr / 3, m2 = k + nCtr * 2 / 3;
    nSum += PrintK2NBwrd4(m2 + 1, n);
    printf("%d ", m2);
    nSum += PrintK2NBwrd4(m1 + 1, m2 - 1);
    printf("%d ", m2);
    nSum += PrintK2NBwrd4(k, m1 - 1);
    return nSum + m1 + m2;
}

int PrintK2NBwrd5(int k, int n)        // n/4��, 1��, n/4��, 1��, n/4��, 1��, n/4��
{
    /***
    [����] [k, m1-1] m1 [m1+1,m2-1] m2 [m2+1,m3-1] m3 [m3+1,n]
    [�Ϲݱ�Ģ] p(k,n) ::= nCtr = n-k+1, m1=k+nCtr/4, m2=k+n
    [�������] ?
    [�ߴ�����] ?
    [�ܼ���] ?
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
