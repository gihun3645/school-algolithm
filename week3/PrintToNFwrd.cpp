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
		int PrintToNFwrd(int n);
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintToNFwrd(n));
	}
}

// 1���� n���� ����ϰ� �׵��� ���� ��ȯ�Ѵ�
int PrintToNFwrd(int n)		// n-1���� ��ȯ�� ������ 1
{
	/***
	[����] [1, n-1] n
	[�Ϲݱ�Ģ] p(n) ::= t=p(n-1), n��, t+n��
	[�������] n�� 1����
	[�ߴ�����] p(1) ::= t=p(0), 1��, t+1�� -> n==0
	[�ܼ���] ��� X, 0 ��ȯ
	***/
	if(n == 0)
        return 0;
    int t = PrintToNFwrd(n-1);
    printf("%d ", n);
	return t+n;
}