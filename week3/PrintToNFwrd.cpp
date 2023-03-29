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

// 1부터 n까지 출력하고 그들의 합을 반환한다
int PrintToNFwrd(int n)		// n-1개의 순환과 나머지 1
{
	/***
	[분할] [1, n-1] n
	[일반규칙] p(n) ::= t=p(n-1), n줄, t+n반
	[진행방향] n이 1감소
	[중단조건] p(1) ::= t=p(0), 1줄, t+1반 -> n==0
	[단순해] 출력 X, 0 반환
	***/
	if(n == 0)
        return 0;
    int t = PrintToNFwrd(n-1);
    printf("%d ", n);
	return t+n;
}