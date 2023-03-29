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

// 1부터 n까지 거꾸로 출력하고 그들의 합을 반환한다.
int PrintToNBwrd(int n)	// n-1개의 순환과 나머지 1
{
	/***
	[분할] [n, n-1] n
	[일반규칙] p(n) ::= n을 출력, t = p(n-1), t+n 반환
	[진행방향] n이 1감소
	[중단조건] p(1) ::= 1줄, t=p(0), t+1반 --> n==0 출력 X, 반환 O
	[단순해] 출력 X , 반환 O
	***/
	if(n==0)
        return 0;
    printf("%d ", n);
    int t = PrintToNBwrd(n-1);
	return t+n;
}