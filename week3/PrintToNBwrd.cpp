#include <stdio.h>

#pragma warning(disable: 4326 4996 6031)

int main(void)
{
	while (1) {
		printf("n ? ");
		int n;
		scanf("%d", &n);
		if (n < 0)
			break;
		int PrintToNBwrd(int n);
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintToNBwrd(n));
	}
}

// 1���� n���� �Ųٷ� ����ϰ� �׵��� ���� ��ȯ�Ѵ�.
int PrintToNBwrd(int n)	// n-1���� ��ȯ�� ������ 1
{
	/***
	[����] [n, n-1] n
	[�Ϲݱ�Ģ] p(n) ::= n�� ���, t = p(n-1), t+n ��ȯ
	[�������] n�� 1����
	[�ߴ�����] p(1) ::= 1��, t=p(0), t+1�� --> n==0 ��� X, ��ȯ O
	[�ܼ���] ��� X , ��ȯ O
	***/
	if(n==0)
        return 0;
    printf("%d ", n);
    int t = PrintToNBwrd(n-1);
	return t+n;
}