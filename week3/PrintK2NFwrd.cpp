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

// k���� n���� ����ϰ� �׵��� ���� ��ȯ�Ѵ�
int PrintK2NFwrd1(int k, int n)		// n-1���� ��ȯ�� ������ 1
{
    /***
    [����] [k, n-1] n
    [�Ϲݱ�Ģ] p(k,n) ::= t=p(k, n-1), n�� ���, t+n�� ��ȯ
    [�������] n�� 1�� ����
    [�ߴ�����] n>k
    [�ܼ���] ��� X, ��ȯ O
    ***/
    if(k > n)
        return 0;
    int t = PrintK2NFwrd1(k, n-1);
    printf("%d ", n);
    return t+n;
}

int PrintK2NFwrd2(int k, int n)		// 1���� ������ n-1���� ��ȯ
{
    /***
    [����] k[k+1, n]
    [�Ϲݱ�Ģ] p(k,n) ::= t=p(k+1, n)
    [�������] k�� 1�� ���� (���ʰ� �����ʰ��� ���� ����)
    [�ߴ�����] p(n,n) ::= n���, t=p(n+1,n) t+n ��ȯ --> k>n: ��X, ��ȯO
    [�ܼ���] ��X, ��O
    ***/
    return 0;
}

int PrintK2NFwrd3(int k, int n)		//  n/2��, 1��, n/2���� ��ȯ
{
    /***
    [����] [k, m-1] m [m+1, n]
    [�Ϲݱ�Ģ] p(k,n) ::= t1=p(k, m-1), m�� ���, t2=p(m+1, n) n�� ���
    [�������]
    [�ߴ�����] ?
    [�ܼ���] ?
    ***/
    return 0;
}